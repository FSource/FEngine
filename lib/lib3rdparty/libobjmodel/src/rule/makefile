main: mesh_y mesh_l  mtl_y mtl_l


mesh_y:
	bison -o ../LibObjMeshGrammer.cc --defines=../LibObjMeshGrammer.h meshgrammer.y


mesh_l:
	flex --bison-bridge --nounistd -o ../LibObjMeshScanner.cc --header-file=../LibObjMeshScanner.h  meshscanner.l  


mtl_y:
	bison  -o ../LibObjMtlGrammer.cc --defines=../LibObjMtlGrammer.h mtlgrammer.y

mtl_l:
	flex --bison-bridge --nounistd -o ../LibObjMtlScanner.cc --header-file=../LibObjMtlScanner.h  mtlscanner.l  




