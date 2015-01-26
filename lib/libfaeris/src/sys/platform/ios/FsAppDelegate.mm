#import "FsAppDelegate.h"
#import "FsMacros.h"
#import "FsGlobal.h"
#import "sys/event/FsSysDispatcher.h"
#import "FsFaerisModule.h"
#import "scheduler/FsScheduler.h"

#import "FsGLESView.h"

NS_FS_USE

@interface FsAppDelegate ()

@end



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
    ms_shareDelegate=self;
    m_window = [[UIWindow alloc] initWithFrame: [[UIScreen mainScreen] bounds]];
    m_glesView= [FsGLESView viewWithFrame: [m_window bounds]];
    
    UIViewController* view_controller = [[UIViewController alloc] initWithNibName:nil bundle:nil];
    view_controller.wantsFullScreenLayout = YES;
    view_controller.view = m_glesView;


    [m_window setRootViewController:view_controller];
    [m_window makeKeyAndVisible];
    
    [[UIApplication sharedApplication] setStatusBarHidden: YES];
    
    

    FsFaeris_ModuleInit();
    FsMain_Entry(0,NULL);
    
    m_interval=1;
    m_displaylink=nil;
    
    
    [self mainLoop];
  //  FS_TRACE_WARN(("Applcaition didFinishLauching"));
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

-(void)doUpdate:(float) dt
{
   // FS_TRACE_WARN("update %f",dt);
    Global::scheduler()->update(dt);
}

-(void) displayEvent:(id) sender
{
    [self doUpdate:1.0/60.0];
}

-(void)mainLoop
{
    //FS_TRACE_WARN(("Do MainLoop"));
    
    m_displaylink = [NSClassFromString(@"CADisplayLink") displayLinkWithTarget:self selector:@selector(displayEvent:)];
    [m_displaylink setFrameInterval: m_interval];
    [m_displaylink addToRunLoop:[NSRunLoop currentRunLoop] forMode:NSDefaultRunLoopMode];
}

@end





