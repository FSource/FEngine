#import <UIKit/UIKit.h>
#import <OpenGLES/EAGL.h>
#import <OpenGLES/EAGLDrawable.h>
#import <OpenGLES/ES2/gl.h>
#import <OpenGLES/ES2/glext.h>
#import <CoreFoundation/CoreFoundation.h>

namespace  Faeris
{
    class Window;
}


@interface FsGLESView: UIView 
{
    /* multi sample */
	BOOL m_multisampling;
    int m_numberOfSamples;
    
    /* pixel and depth format */
    NSString* m_pixelFormat;
    GLuint m_depthFormat;
    
    
    /* dicard buffer support */
    BOOL m_discardFramebufferSupported;
    BOOL m_preserveBackbuffer;
   
    /* share grounp */
    EAGLSharegroup* m_shareGrounp;
    
    /* opengl context */
    EAGLContext* m_context;
    
    GLuint m_defaultFrameBuffer;
    GLuint m_colorRenderBuffer;
    GLuint m_depthBuffer;
    
    /* buffer for multisample antialiasing  */
    GLuint m_msaaColorBuffer;
    GLuint m_msaaRenderBuffer;
    
    int m_width;
    int m_height;
    
    Faeris::Window* m_fswindow;
}

/* class method */
+ (id) viewWithFrame:(CGRect)frame;


/* instance method */
-(id) initWithFrame:(CGRect)frame ;
-(BOOL) initOpengles;
-(GLuint) getFrameBuffer;
-(GLuint) getColorRenderBuffer;
-(void) setFsWindow:(Faeris::Window*)fswindow;
-(void)swapBuffers;
-(int) getWidth;
-(int) getHeight;

@end 




