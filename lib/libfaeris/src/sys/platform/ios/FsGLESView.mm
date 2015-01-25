#include "FsMacros.h"
#import "FsGLESView.h"
#include "sys/FsWindow.h"



@implementation FsGLESView

+ (id) viewWithFrame:(CGRect) frame
{
	return [[self alloc] initWithFrame:frame] ;
}



+ (Class) layerClass
{
	return [CAEAGLLayer class];
}


- (id) initWithFrame:(CGRect)frame
{
	self=[super initWithFrame:frame];
	if(self)
	{
		m_pixelFormat=kEAGLColorFormatRGB565;

		m_multisampling=NO;
		m_numberOfSamples=0;
		m_depthFormat=GL_DEPTH_COMPONENT16;


#if GL_EXT_discard_framebuffer == 1
		m_discardFramebufferSupported= YES;
#else
		m_discardFramebufferSupported= NO;
#endif

		m_preserveBackbuffer=NO;

		/* share grounp */
		m_shareGrounp=nil;

		/* opengl context */
		m_context=nil;

		m_defaultFrameBuffer=0;
		m_colorRenderBuffer=0;
		m_depthBuffer=0;

		m_width=0;
		m_height=0;

		CAEAGLLayer* eaglLayer = (CAEAGLLayer *)self.layer;

		eaglLayer.opaque = YES;
		eaglLayer.drawableProperties = [NSDictionary dictionaryWithObjectsAndKeys:
			[NSNumber numberWithBool:NO],
			kEAGLDrawablePropertyRetainedBacking,
			kEAGLColorFormatRGB565,
			kEAGLDrawablePropertyColorFormat,
			nil];

		[self initOpengles];
	}

	return self;
}

-(BOOL) initOpengles
{
	if(m_shareGrounp)
	{
		m_context=[[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES2];
	}
	else
	{
		m_context=[[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES2 sharegroup:m_shareGrounp];
	}

	if(m_context)
	{
		if(![EAGLContext setCurrentContext:m_context])
		{
			FS_TRACE_WARN("Set Current Context Failed");
		}
	}
	else
	{
		return NO;
	}

	glGenFramebuffers(1, &m_defaultFrameBuffer);
	NSAssert( m_defaultFrameBuffer, @"Can't create default frame buffer");

	glGenRenderbuffers(1, &m_colorRenderBuffer);
	NSAssert( m_colorRenderBuffer, @"Can't create default render buffer");

	glBindFramebuffer(GL_FRAMEBUFFER, m_defaultFrameBuffer);
	glBindRenderbuffer(GL_RENDERBUFFER, m_colorRenderBuffer);
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_RENDERBUFFER, m_colorRenderBuffer);
	if(m_depthFormat)
	{
		glGenRenderbuffers(1, &m_depthBuffer);
		glBindRenderbuffer(GL_RENDERBUFFER, m_depthBuffer);
		glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, m_depthBuffer);

		if (m_depthFormat == GL_DEPTH24_STENCIL8_OES)
		{
			glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_STENCIL_ATTACHMENT, GL_RENDERBUFFER, m_depthBuffer);
		}
		glBindRenderbuffer(GL_RENDERBUFFER, m_colorRenderBuffer);
	}
	return true;
}


-(void)layoutSubviews
{
	CAEAGLLayer* layer=(CAEAGLLayer*)self.layer;

	glBindRenderbuffer(GL_RENDERBUFFER, m_colorRenderBuffer);
	if(![m_context renderbufferStorage:GL_RENDERBUFFER fromDrawable:layer])
	{
		FS_TRACE_WARN("falied to resize content");
	}

	GLint width=0;
	GLint height=0;
	glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_WIDTH, &width);
	glGetRenderbufferParameteriv(GL_RENDERBUFFER, GL_RENDERBUFFER_HEIGHT, &height);

	m_width=width;
	m_height=height;

	FS_TRACE_WARN("view resize =%d,%d",width,height);


	if (m_depthFormat)
	{

		glBindRenderbuffer(GL_RENDERBUFFER, m_depthBuffer);

		glRenderbufferStorage(GL_RENDERBUFFER, m_depthBuffer, width, height);

		glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, m_depthBuffer);

		if (m_depthFormat == GL_DEPTH24_STENCIL8_OES)
		{
			glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_STENCIL_ATTACHMENT, GL_RENDERBUFFER,m_depthBuffer);
		}

		glBindRenderbuffer(GL_RENDERBUFFER, m_colorRenderBuffer);
	}

	GLenum error;
	if( (error=glCheckFramebufferStatus(GL_FRAMEBUFFER)) != GL_FRAMEBUFFER_COMPLETE)
	{
		FS_TRACE_WARN("Failed to make complete framebuffer object 0x%X", error);
	}

	if(m_fswindow)
	{
		m_fswindow->setSize(width,height);
	}

}

-(GLuint)getFrameBuffer
{
	return m_defaultFrameBuffer;
}

-(void)setFsWindow:(Faeris::Window *)fswindow
{
	m_fswindow=fswindow;
}

-(int) getWidth
{
	CGSize bound = [self bounds].size;
	return (int)bound.width * self.contentScaleFactor;
}

-(int) getHeight
{
	CGSize bound = [self bounds].size;
	return (int)bound.height * self.contentScaleFactor;
}

-(void) swapBuffers
{
	if(![EAGLContext setCurrentContext:m_context])
	{
		FS_TRACE_WARN("Failed To Swap Buffer");
	}
}



- (void)dealloc
{
	if (m_defaultFrameBuffer) 
	{
		glDeleteFramebuffers(1, &m_defaultFrameBuffer);
		m_defaultFrameBuffer=0;
	}

	if (m_colorRenderBuffer) 
	{
		glDeleteRenderbuffers(1, &m_colorRenderBuffer);
		m_colorRenderBuffer= 0;
	}

	if( m_depthBuffer) 
	{
		glDeleteRenderbuffers(1, &m_depthBuffer);
		m_depthBuffer= 0;
	}


	if ([EAGLContext currentContext] == m_context)
	{
		[EAGLContext setCurrentContext:nil];
	}

	//[m_context release];
	m_context= nil;

	//[super dealloc];
}

@end




