#include "FsFaerisModule.h"
#include "sys/io/FsVFS.h"
#include "FsGlobal.h"
#include "scheduler/FsScheduler.h"
#include "stage/FsDirector.h"

#import <Foundation/Foundation.h>

NS_FS_BEGIN


class IosBundleNameFilter:public VFS::NameFilter
{
	public:
		static IosBundleNameFilter* create()
        {
            return new IosBundleNameFilter();
        }

	public:
		std::string apply(const char* name) FS_OVERRIDE
		{
			NSString* fullpath = [m_bundle pathForResource:[NSString stringWithUTF8String:name]
                                                    ofType:nil];

			if (fullpath != nil) 
			{
                return [fullpath UTF8String];

			}
			else 
			{
				//FS_TRACE_WARN("Get Bundle Path Failed(%s)",name);
			}
			return name;
		}


	protected:
		IosBundleNameFilter()
		{
			m_bundle=[NSBundle mainBundle];
			m_fileManager=[NSFileManager defaultManager];
		}

	private:
		NSBundle* m_bundle;
		NSFileManager* m_fileManager;
};




int FsFaeris_PlatformInit()
{

    NSArray* paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString* documents_dir = [paths objectAtIndex:0];
    std::string cur_path = [documents_dir UTF8String];
    
    cur_path.append("/");
    VFS::setRoot(cur_path.c_str());
    FS_TRACE_WARN("VFS Work Path Is:%s",cur_path.c_str());
    
	VFS::addFilter(IosBundleNameFilter::create());

	Global::director()->setAutoSwapBuffers(true);
	return 0;
}


NS_FS_END 

