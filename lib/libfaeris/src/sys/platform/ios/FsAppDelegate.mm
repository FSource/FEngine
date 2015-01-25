#import "FsAppDelegate.h"
#import "FsMacros.h"
#import "FsGlobal.h"
#import "sys/event/FsSysDispatcher.h"
#import "FsFaerisModule.h"

#import "FsGLESView.h"

NS_FS_USE




@implementation FsAppDelegate


static FsAppDelegate* ms_shareDelegate=nil;


+(FsAppDelegate*) getShareAppDelegate
{
    return ms_shareDelegate;
}

-(FsGLESView*) getGlesView
{
    return m_glesView;
}

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    //ms_shareDelegate=self;
    
    m_window = [[UIWindow alloc] initWithFrame: [[UIScreen mainScreen] bounds]];
    m_glesView= [FsGLESView viewWithFrame: [m_window bounds]];
    
    UIViewController* view_controller = [[UIViewController alloc] initWithNibName:nil bundle:nil];
    view_controller.wantsFullScreenLayout = YES;
    view_controller.view = m_glesView;


    [m_window setRootViewController:view_controller];
    [m_window makeKeyAndVisible];
    
    [[UIApplication sharedApplication] setStatusBarHidden: YES];
    
    
    FS_TRACE_WARN(("Applcaition didFinishLauching"));
    Faeris::FsFaeris_ModuleInit();

    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application
{

}



- (void)applicationDidEnterBackground:(UIApplication *)application 
{
    SysDispatcher* dispatcher= Global::sysDispatcher();
	if(dispatcher)
	{
		dispatcher->dispatchEvent(new SysEvent(SysDispatcher::BACKGROUND));
		dispatcher->flush();
	}
}

- (void)applicationWillEnterForeground:(UIApplication *)application 
{
	SysDispatcher* dispatcher= Global::sysDispatcher();
	if(dispatcher)
	{
		dispatcher->dispatchEvent(new SysEvent(SysDispatcher::FOREGROUND));
		dispatcher->flush();
	}
}

- (void)applicationDidBecomeActive:(UIApplication *)application 
{
}

- (void)applicationWillTerminate:(UIApplication *)application 
{
	SysDispatcher* dispatcher= Global::sysDispatcher();
	if(dispatcher)
	{
		dispatcher->dispatchEvent(new SysEvent(SysDispatcher::EXIT));
		dispatcher->flush();
	}

	FsFaeris_ModuleExit();
}

@end 
