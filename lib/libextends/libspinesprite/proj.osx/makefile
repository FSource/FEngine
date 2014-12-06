# Normal Information 
CC=gcc
FILE_EXT=cc

FLAGS_DEBUG= -g -Wall  -Werror -DLINUX -std=c++11
FLAGS_RELEASE= -O3 -DLINUX -std=c++11

#Project infor 
PROJECT_PATH= ../../../library/osx/
PROJECT=spinesprite

SRC_DIR=../src
INCLUDE_DIR=-I../src \
			-I../../../libfaeris/src \


#Source File 
SRC=   spine/Animation.cc \
	   spine/AnimationState.cc \
	   spine/AnimationStateData.cc  \
	   spine/Atlas.cc \
	   spine/AtlasAttachmentLoader.cc \
	   spine/Attachment.cc \
	   spine/AttachmentLoader.cc \
	   spine/Bone.cc \
	   spine/BoneData.cc \
	   spine/extension.cc \
	   spine/Json.cc \
	   spine/RegionAttachment.cc \
	   spine/Skeleton.cc \
	   spine/SkeletonData.cc \
	   spine/SkeletonJson.cc \
	   spine/Skin.cc \
	   spine/Slot.cc \
	   spine/SlotData.cc \
	   FsSpineExtention.cc \
	   FsSpineSprite.cc \
	   FsSpineSpriteData.cc \
	   FsSpineSpriteDataMgr.cc \
	   FsTextureAttachment.cc \
	   FsTextureAttachmentLoader.cc \




include ../../../MK_BUILD_STATIC_LIB 

