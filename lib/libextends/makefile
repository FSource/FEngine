DIR=  libspinesprite \
	  libluaexport \
	

osx:
	for d in $(DIR) ;do \
		echo compile $$d ... ; \
		make MK_DEBUG=1 -C $$d/proj.osx >>/dev/null ;\
	done 
	for d in $(DIR) ;do \
		echo compile $$d ... ; \
		make  -C $$d/proj.osx >>/dev/null ;\
	done 


main:
	for d in $(DIR) ;do \
		echo compile $$d ... ; \
		make MK_DEBUG=1 -C $$d/proj.linux >>/dev/null ;\
	done 


debug:
	for d in $(DIR) ;do \
		echo compile $$d ... ; \
		make MK_DEBUG=1 -C $$d/proj.linux >>/dev/null ;\
	done 

release: 
	for d in $(DIR) ;do \
		echo compile $$d ... ; \
		make -C $$d/proj.linux >>/dev/null ;\
	done 

clean:
	for d in $(DIR) ;do \
		echo clean $$d ... ; \
		make clean -C $$d/proj.linux >>/dev/null ;\
		make clean MK_DEBUG=1 -C $$d/proj.linux >>/dev/null ;\
	done 





