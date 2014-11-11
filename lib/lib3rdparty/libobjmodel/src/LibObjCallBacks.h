#ifndef __USERCALLBACKS_H
#define __USERCALLBACKS_H

#include <stddef.h>



typedef int (*LibObj_AddVertexFunc)(float x, float y, float z, float weight, void *userData);
typedef int (*LibObj_AddTexelFunc)(float x, float y, void *userData);
typedef int (*LibObj_AddNormalFunc)(float x, float y, float z, void *userData);
typedef int (*LibObj_StartLineFunc)(void *userData);
typedef int (*LibObj_AddToLineFunc)(int v, size_t vt, void *userData);
typedef int (*LibObj_StartFaceFunc)(void *userData);
typedef int (*LibObj_AddToFaceFunc)(size_t v, size_t vt, size_t vn, void *userData);
typedef int (*LibObj_StartObjectFunc)(const char *name, void *userData);
typedef int (*LibObj_StartGroupFunc)(void *userData);
typedef int (*LibObj_AddGroupNameFunc)(const char *name, void *userData);
typedef int (*LibObj_RefMaterialLibFunc)(const char *filename, void *userData);
typedef int (*LibObj_UseMaterialFunc)(const char *material, void *userData);
typedef int (*LibObj_SmoothingGroupFunc)(size_t groupid, void *userData);

typedef struct tagObjParseCallbacks
{
  LibObj_AddVertexFunc onVertex;
  LibObj_AddTexelFunc onTexel;
  LibObj_AddNormalFunc onNormal;
  LibObj_StartLineFunc onStartLine;
  LibObj_AddToLineFunc onAddToLine;
  LibObj_StartFaceFunc onStartFace;
  LibObj_AddToFaceFunc onAddToFace;
  LibObj_StartObjectFunc onStartObject;
  LibObj_StartGroupFunc onStartGroup;
  LibObj_AddGroupNameFunc onGroupName;
  LibObj_RefMaterialLibFunc onRefMaterialLib;
  LibObj_UseMaterialFunc onUseMaterial;
  LibObj_SmoothingGroupFunc onSmoothingGroup;
} LibObjMeshCallbacks;


typedef int (*LibObj_AddMaterialFunc)(const char *name, void *userData);
typedef int (*LibObj_SetAmbientColorFunc)(float r, float g, float b, void *userData);
typedef int (*LibObj_SetDiffuseColorFunc)(float r, float g, float b, void *userData);
typedef int (*LibObj_SetSpecularColorFunc)(float r, float g, float b, void *userData);
typedef int (*LibObj_SetSpecularExponentFunc)(float se, void *userData);
typedef int (*LibObj_SetOpticalDensityFunc)(float d, void *userData);
typedef int (*LibObj_SetAlphaFunc)(float a, void *userData);
typedef int (*LibObj_SetIllumModelFunc)(int model, void *userData);
typedef int (*LibObj_SetAmbientTextureMapFunc)(const char *path, void *userData);
typedef int (*LibObj_SetDiffuseTextureMapFunc)(const char *path, void *userData);
typedef int (*LibObj_SetSpecularTextureMapFunc)(const char *path, void *userData);
typedef int (*LibObj_SetBumpTextureMapFunc)(const char *path, void *userData);
typedef int (*LibObj_SetAlphaTextureMapFunc)(const char *path, void *userData);

typedef struct tagMtlParseCallbacks
{
  LibObj_AddMaterialFunc onAddMaterial;
  LibObj_SetAmbientColorFunc onSetAmbientColor;
  LibObj_SetDiffuseColorFunc onSetDiffuseColor;
  LibObj_SetSpecularColorFunc onSetSpecularColor;
  LibObj_SetSpecularExponentFunc onSetSpecularExponent;
  LibObj_SetOpticalDensityFunc onSetOpticalDensity;
  LibObj_SetAlphaFunc onSetAlpha;
  LibObj_SetIllumModelFunc onSetIllumModel;
  LibObj_SetAmbientTextureMapFunc onSetAmbientTextureMap;
  LibObj_SetDiffuseTextureMapFunc onSetDiffuseTextureMap;
  LibObj_SetSpecularTextureMapFunc onSetSpecularTextureMap;
  LibObj_SetBumpTextureMapFunc onSetBumpTextureMap;
  LibObj_SetAlphaTextureMapFunc onSetAlphaTextureMap;
} LibObjMtlCallbacks;

#endif /* __USERCALLBACKS_H */
