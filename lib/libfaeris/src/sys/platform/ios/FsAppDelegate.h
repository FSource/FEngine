#ifndef _FS_APP_DELEGATE_H_
#define _FS_APP_DELEGATE_H_


#import <UIKit/UIKit.h>

@class FsGLESView;

@interface FsAppDelegate :NSObject <UIApplicationDelegate>
{
	UIWindow* m_window;
	FsGLESView* ms_glesView;
}

+(FsAppDelegate*) getShareAppDelegate ;


@end 
#endif /*_FS_APP_DELEGATE_H_*/




