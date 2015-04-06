#include "FsMacros.h"
#import "FsGLESView.h"
#include "sys/FsWindow.h"
#include "GL_IOS/gl_ios_es.h"
#include "sys/event/FsTouchDispatcher.h"
#include "FsGlobal.h"
#import <Foundation/Foundation.h>

NS_FS_USE

@implementation FsGLESView

+ (id) viewWithFrame:(CGRect) frame
{
	return [[self alloc] initWithFrame:frame]  ;
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
        
        m_touchPointNu=0;

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
    FS_GL_CHECK_GL_ERROR();
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
        FS_GL_CHECK_GL_ERROR();
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
    FS_GL_CHECK_GL_ERROR();

	m_width=width;
	m_height=height;

	FS_TRACE_WARN("view resize =%d,%d",width,height);


	if (m_depthFormat)
	{

		glBindRenderbuffer(GL_RENDERBUFFER, m_depthBuffer);
		glRenderbufferStorage(GL_RENDERBUFFER, m_depthFormat, width, height);


		glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_RENDERBUFFER, m_depthBuffer);
         FS_GL_CHECK_GL_ERROR();

		if (m_depthFormat == GL_DEPTH24_STENCIL8_OES)
		{
			glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_STENCIL_ATTACHMENT, GL_RENDERBUFFER,m_depthBuffer);
		}
       

		glBindRenderbuffer(GL_RENDERBUFFER, m_colorRenderBuffer);
        FS_GL_CHECK_GL_ERROR();
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
-(GLuint)getColorRenderBuffer
{
    return m_colorRenderBuffer;
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
    if(![m_context presentRenderbuffer:GL_RENDERBUFFER])
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


#define FS_IOS_MAX_TOUCHES_COUNT     10

- (void)touchesBegan:(NSSet *)touches withEvent:(UIEvent *)event
{
 
    int touch_event=TouchDispatcher::TOUCHES_BEGIN;
    if(m_touchPointNu>0)
    {
        touch_event=TouchDispatcher::TOUCHES_POINTER_DOWN;
    }
    
    m_touchPointNu+=[touches count];

    FS_TRACE_WARN("Touch Begin");
    TouchPoint  touches_points[FS_IOS_MAX_TOUCHES_COUNT];
    
    int i = 0;
    for (UITouch *touch in touches)
    {
        touches_points[i].id=(long)touch;

        float real_posx=[touch locationInView: [touch view]].x * self.contentScaleFactor;
        touches_points[i].x = real_posx/float(m_width);
        
        float real_posy=[touch locationInView: [touch view]].y* self.contentScaleFactor;
        touches_points[i].y = 1.0f-real_posy/float(m_height);
        ++i;
    }
    TouchDispatcher* dispatcher= Global::touchDispatcher();
    if(dispatcher)
    {
        dispatcher->dispatchEvent(new TouchEvent(touch_event,i,touches_points));
    }

    
}

- (void)touchesMoved:(NSSet *)touches withEvent:(UIEvent *)event
{
    FS_TRACE_WARN("Touch Move");

    TouchPoint  touches_points[FS_IOS_MAX_TOUCHES_COUNT];
    
    int i = 0;
    for (UITouch *touch in touches)
    {
        touches_points[i].id=(long)touch;
        
        float real_posx=[touch locationInView: [touch view]].x * self.contentScaleFactor;
        touches_points[i].x = real_posx/float(m_width);
        
        float real_posy=[touch locationInView: [touch view]].y* self.contentScaleFactor;
        touches_points[i].y = 1.0f-real_posy/float(m_height);
        ++i;
    }
    
    TouchDispatcher* dispatcher= Global::touchDispatcher();
    if(dispatcher)
    {
        dispatcher->dispatchEvent(new TouchEvent(TouchDispatcher::TOUCHES_MOVE,i,touches_points));
    }

    
}

- (void)touchesEnded:(NSSet *)touches withEvent:(UIEvent *)event
{
    FS_TRACE_WARN("Touch End");
    TouchPoint  touches_points[FS_IOS_MAX_TOUCHES_COUNT];
    
    int touch_event=TouchDispatcher::TOUCHES_POINTER_DOWN;
    
    m_touchPointNu-=[touches count];
    
    if(m_touchPointNu==0)
    {
        touch_event=TouchDispatcher::TOUCHES_END;
    }
    
    int i = 0;
    for (UITouch *touch in touches)
    {
        touches_points[i].id=(long)touch;
        
        float real_posx=[touch locationInView: [touch view]].x * self.contentScaleFactor;
        touches_points[i].x = real_posx/float(m_width);
        
        float real_posy=[touch locationInView: [touch view]].y* self.contentScaleFactor;
        touches_points[i].y = 1.0f-real_posy/float(m_height);
        ++i;
    }
    TouchDispatcher* dispatcher= Global::touchDispatcher();
    if(dispatcher)
    {
        dispatcher->dispatchEvent(new TouchEvent(touch_event,i,touches_points));
    }


}

-(void)touchesCancelled:(NSSet *)touches withEvent:(UIEvent *)event
{
    FS_TRACE_WARN("Touch Cancel");
    
    [self touchesEnded:touches withEvent:event];
}



@end




