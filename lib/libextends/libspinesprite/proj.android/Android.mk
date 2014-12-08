LOCAL_PATH :=$(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := spinesprite_static


LOCAL_CFLAGS     :=  -I$(LOCAL_PATH)/../src \
					 -I$(LOCAL_PATH)/../../../libfaeris/src \
					 -I$(LOCAL_PATH)/../../../libfaeris/src/support  \


LOCAL_SRC_FILES :=  ../src/FsSpineExtention.cc \
					../src/FsSpineSprite.cc \
					../src/FsSpineSpriteData.cc \
					../src/FsSpineSpriteDataMgr.cc \
					../src/FsTextureAttachment.cc \
					../src/FsTextureAttachmentLoader.cc \
					../src/spine/Animation.cc \
					../src/spine/AnimationState.cc \
					../src/spine/AnimationStateData.cc \
					../src/spine/Atlas.cc \
					../src/spine/Attachment.cc \
					../src/spine/AtlasAttachmentLoader.cc \
					../src/spine/AttachmentLoader.cc \
					../src/spine/Bone.cc \
					../src/spine/BoneData.cc \
					../src/spine/extension.cc \
					../src/spine/Json.cc \
					../src/spine/RegionAttachment.cc \
					../src/spine/Skeleton.cc \
					../src/spine/SkeletonData.cc \
					../src/spine/SkeletonJson.cc \
					../src/spine/Skin.cc \
					../src/spine/Slot.cc \
					../src/spine/SlotData.cc \

					 



include $(BUILD_STATIC_LIBRARY)









