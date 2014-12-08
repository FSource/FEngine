from libpy import *

# set the working dir 
FGZ_WORKING_DIR=["../tmp/fsources"]

# the pack name 
FGZ_PACKAGE_NAME="fdata.fgz"

# where the pack generate 
FGZ_TARGET_DIR="../tmp/assets"

# file ignore to pack 
FGZ_IGNORE_FILE_EXT=[".ogg",".wav",".db"]

# file will not compress 
FGZ_NOT_COMPRESS_FILE_EXT=[]


packer=data.FgzPacker(FGZ_WORKING_DIR,FGZ_TARGET_DIR)
packer.setPackageName(FGZ_PACKAGE_NAME)
packer.setIngoreFileExt(FGZ_IGNORE_FILE_EXT)
packer.setNotCompressFileExt(FGZ_NOT_COMPRESS_FILE_EXT)


print "packing please wait ... "
packer.pack()


reader=data.FgzReader(files.Dir.Dir_toStdName(FGZ_TARGET_DIR)+FGZ_PACKAGE_NAME)
reader.printAllFileInfo()

print 
print "packing success,press <enter> to exit"
raw_input()








