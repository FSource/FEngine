python Dir.py "../../../lib/libfaeris/src"  >_files  
python Dir.py "../../../lib/lib3rdparty/glslext/src"  >>_files  
python Dir.py "../../../lib/libextends/libluaexport/src"  >>_files  
cat _files  | grep "\.h\|\.cc\|\.inl" >files
rm _files

python addheader.py

for a in `cat files` 
do 
	dos2unix $a 
	#echo $a
done 



