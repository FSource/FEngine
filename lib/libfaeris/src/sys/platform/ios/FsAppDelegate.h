#import <UIKit/UIKit.h>



@class FsGLESView;

@interface FsAppDelegate :UIResponder <UIApplicationDelegate>
{
	UIWindow* m_window;
	FsGLESView* m_glesView;
    id m_displaylink;
    int m_fps;
    int m_interval;
    float m_lastUpdateTime;
    
}


+(FsAppDelegate*) getShareAppDelegate;
-(FsGLESView*) getGlesView;
-(void) doUpdate:(float)dt;
-(void) mainLoop;
-(void) displayEvent:(id) sender;


@end




