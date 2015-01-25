#ifndef _FS_APP_DELEGATE_H_
#define _FS_APP_DELEGATE_H_


#import <UIKit/UIKit.h>

@class FsGLESView;

@interface FsAppDelegate :UIResponder <UIApplicationDelegate>
{
	UIWindow* m_window;
	FsGLESView* m_glesView;
    
}

+(FsAppDelegate*) getShareAppDelegate;
-(FsGLESView*) getGlesView;


@end 
#endif /*_FS_APP_DELEGATE_H_*/




