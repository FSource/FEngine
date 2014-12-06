main: md5mesh_y md5mesh_l  md5anim_y md5anim_l



md5mesh_y: 
	bison -o ../md5mesh_grammer.cc --defines=../md5mesh_grammer.h  md5mesh_grammer.y 

md5mesh_l:
	flex --bison-bridge --nounistd -o ../md5mesh_scanner.cc --header-file=../md5mesh_scanner.h md5mesh_scanner.l 


md5anim_y:
	bison  -o ../md5anim_grammer.cc --defines=../md5anim_grammer.h md5anim_grammer.y 


md5anim_l:
	flex --bison-bridge --nounistd -o ../md5anim_scanner.cc --header-file=../md5anim_scanner.h md5anim_scanner.l 
 

