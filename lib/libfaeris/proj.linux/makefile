# Normal Information 
CC=gcc
FILE_EXT=cc

FLAGS_DEBUG= -g -Wall  -Werror -DLINUX
FLAGS_RELEASE= -O3 -Wall -Werror -DLINUX

#Project infor 
PROJECT_PATH= ../../library/linux/
PROJECT=faeris

SRC_DIR=../src
INCLUDE_DIR=-I../src \
		   	-I../../lib3rdparty/freetype/include \
		   	-I../../lib3rdparty/libpng/include \
		   	-I../../lib3rdparty/lua/include \
		   	-I../../lib3rdparty/minizip/include \
		   	-I../../lib3rdparty/tolua++/include \
		   	-I../../lib3rdparty/lua/include \
		   	-I../../lib3rdparty/zlib/include \
			-I../../lib3rdparty/curl/include \
			-I../../lib3rdparty/fmod/include \
			-I../../lib3rdparty/libjpeg/src \

#Source File 
SRC= FsGlobal.cc \
	 FsObject.cc \
	 FsFaerisModule.cc  \
	 extends/FsScriptEngine.cc \
	 stage/FsActionTarget.cc \
	 stage/action/FsAction.cc \
	 stage/action/FsMoveByAction.cc \
	 stage/action/FsMoveToAction.cc \
	 stage/action/FsPauseAction.cc \
	 stage/action/FsRotateZByAction.cc \
	 stage/action/FsRotateZToAction.cc \
	 stage/action/FsScaleByAction.cc \
	 stage/action/FsScaleToAction.cc \
	 stage/action/FsSeqAction.cc \
	 stage/entity/FsColorQuad2D.cc \
	 stage/entity/FsEntity.cc \
	 stage/entity/FsLabelBitmap.cc \
	 stage/entity/FsLabelTTF.cc \
	 stage/entity/FsParticle2DEffect.cc \
	 stage/entity/FsParticle2DEmitter.cc \
	 stage/entity/FsQuad2D.cc \
	 stage/entity/FsSprite2D.cc \
	 stage/entity/FsSprite2DData.cc \
	 stage/entity/FsVertexPolygon.cc \
	 stage/entity/FsPanel.cc \
	 stage/entity/FsButton.cc \
	 stage/layer/FsColorLayer.cc \
	 stage/layer/FsLayer.cc \
	 stage/layer/FsLayer2D.cc \
	 stage/FsDirector.cc \
	 stage/FsScene.cc \
	 sys/event/FsKeypadDispatcher.cc \
	 sys/event/FsSysDispatcher.cc \
	 sys/event/FsTouchDispatcher.cc \
	 sys/event/FsInputTextDispatcher.cc \
	 sys/io/FsFile.cc \
	 sys/io/FsSysFile.cc \
	 sys/io/FsSegFile.cc \
	 sys/io/FsMemFile.cc \
	 sys/io/FsPackage.cc \
	 sys/io/FsFgzPackage.cc \
	 sys/io/FsVFS.cc \
	 sys/io/FsZipPackage.cc \
	 sys/FsSys.cc \
	 sys/FsTimer.cc \
	 sys/FsWindow.cc \
	 sys/thread/FsMutex.cc \
	 sys/thread/FsSemaphore.cc \
	 sys/thread/FsThread.cc \
	 sys/network/FsHttpEngine.cc \
	 sys/network/FsHttpReponse.cc \
	 sys/network/FsHttpRequest.cc \
	 graphics/FsColor.cc \
	 graphics/FsFontBitmap.cc \
	 graphics/FsFontTTF.cc \
	 graphics/FsImage2D.cc \
	 graphics/FsProgram.cc \
	 graphics/FsRender.cc \
	 graphics/FsTexture2D.cc \
	 graphics/material/FsMaterial.cc \
	 graphics/material/FsColorMaterial.cc \
	 graphics/material/FsTextureMaterial.cc \
	 math/FsMathUtil.cc \
	 math/FsMatrix4.cc \
	 math/FsQuaternion.cc \
	 math/FsRect2D.cc \
	 mgr/FsFontTTFMgr.cc \
	 mgr/FsResource.cc \
	 mgr/FsResourceMgr.cc \
	 mgr/FsSprite2DDataMgr.cc \
	 mgr/FsTextureMgr.cc \
	 mgr/FsObjectMgr.cc \
	 mgr/FsProgramMgr.cc \
	 scheduler/FsScheduler.cc \
	 scheduler/FsSchedulerTarget.cc \
	 scheduler/FsTask.cc \
	 support/data/FsBase64.cc \
	 support/data/FsDeflate.cc \
	 support/data/FsEncrypt.cc \
	 support/data/FsHash.cc \
	 support/data/FsIconv.cc \
	 support/data/FsUnicode.cc \
	 support/data/FsFgzReader.cc \
	 support/data/FsZipReader.cc \
	 support/data/FsMd5.cc \
	 support/felis/sl_comment.cc \
	 support/felis/sl_double_quote_str.cc \
	 support/felis/sl_simple_str.cc \
	 support/felis/sl_single_quote_str.cc \
	 support/felis/sl_specific_symbol.cc \
	 support/felis/sl_top.cc \
	 support/felis/sl_white_space.cc \
	 support/felis/xir_file.cc \
	 support/felis/xir_grammer.cc \
	 support/felis/xir_parser.cc \
	 support/felis/xir_scanner.cc \
	 support/felis/xir_token.cc \
	 support/image/FsImageDecoder.cc \
	 support/image/FsImagePng.cc \
	 support/image/FsImageJpeg.cc \
	 support/util/FsArray.cc \
	 support/util/FsDict.cc \
	 support/util/FsInteger.cc \
	 support/util/FsLog.cc \
	 support/util/FsPathUtil.cc \
	 support/util/FsScriptUtil.cc \
	 support/util/FsSlowArray.cc \
	 support/util/FsSlowDict.cc \
	 support/util/FsString.cc \
	 media/FsAudioEngine.cc \
	 media/FsAudioPlayer.cc \


include ../../MK_BUILD_STATIC_LIB
