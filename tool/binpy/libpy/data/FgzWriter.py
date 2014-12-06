import io
import gzip
import struct 

FgzMagicNumber="\0FGZIP1\0"
FgzFileMagicNumber="\0FGFILE\0"

FgzStore=0x0 
FgzDeflate=0x10 
FgzLzma=0x20 

FgzCrc32Default=0xfae
FgzCompressBound=0.8 

FgzCompressDefaultLevel=6

class FgzWriter:
	def __init__(self):
		self.m_files={}
		self.m_log=""

	def addFile(self,filename,alias,method="deflate"):
		self.m_files[filename]={
						"filename":filename,
						"alias":alias,
						"method":method
						}

	def pack(self,target_file):
		self.m_log=""
		error_nu=0
		try:
			tf=open(target_file,"wb+")
		except Exception,e:
			self.m_log=e
			return False




		# --- global header party ----
		# imagic number 
		tf.write(FgzMagicNumber)

		# no can't know how many file is ok, so write zero instead,
		# at the end of pack, it will be rewrite 
		tf.write(struct.pack("I",0))

		# file data offset 
		tf.write(struct.pack("I",16))

		# ---- file party -----
		handle_files=0
		for (k,v) in self.m_files.items():
			try:
				pf=open(v["filename"],"rb")
			except Exception,msg:
				self.m_log=self.m_log+"can't open file("+v["filename"]+")for pack\n";
				error_nu=error_nu+1
				continue
			
			# get file data 
			un_data=pf.read()
			un_data_size=len(un_data)
			if un_data_size == 0:
				print("Empty File:"+v["filename"]+" ignore")
				continue

				



			un_data_crc32=gzip.zlib.crc32(un_data,FgzCrc32Default)&0xffffffff

			en_data=gzip.zlib.compress(un_data,FgzCompressDefaultLevel)
			en_data_size=len(en_data)
			en_data_crc32=gzip.zlib.crc32(en_data,FgzCrc32Default)&0xffffffff
			

			method=v["method"]
			if float(en_data_size)/float(un_data_size)>FgzCompressBound: 
				method="store"

			if method=="store": 
				tf.write(FgzFileMagicNumber)   			    # file magic number 
				tf.write(struct.pack("I",FgzStore))         # compress method 
				tf.write(struct.pack("I",un_data_size))     # compress size 
				tf.write(struct.pack("I",un_data_size))     # uncompress size 
				tf.write(struct.pack("I",un_data_crc32))    # crc32 
				tf.write(struct.pack("I",len(v["alias"])))  # filename len, use alias 
				tf.write(v["alias"])                        # file name 
				tf.write(un_data)							# file data 
				handle_files=handle_files+1

			elif method=="deflate":
				tf.write(FgzFileMagicNumber)				# file magic number 
				tf.write(struct.pack("I",FgzDeflate))		# compress method 
				tf.write(struct.pack("I",en_data_size))     # compress size 
				tf.write(struct.pack("I",un_data_size))		# uncompress size 
				tf.write(struct.pack("I",en_data_crc32))	# crc32 
				tf.write(struct.pack("I",len(v["alias"])))  # filename len,use alias 
				tf.write(v["alias"])						# filename
				tf.write(en_data)							# file data
				handle_files=handle_files+1

			elif method=="lzma":
				error_nu=error_nu+1 
				self.m_log=self.m_log+"Not FgzWriter Not Support Lzma Compress Method"

		# no error happend 
		if error_nu is 0:
			self.m_log="pack success"


		tf.seek(8,0)
		tf.write(struct.pack("I",handle_files))	# update files we handle 

		tf.flush()
		tf.close()

		return True




	def getLog(self):
		return self.m_log




if __name__=="__main__":
	files=["1.png","2.png","3.png","4.png","log.txt","sound.pk3"]
	fgzwriter=FgzWriter()
	for f in files:
		fgzwriter.addFile(f,f)

	fgzwriter.pack("tmp.fgz")
	print fgzwriter.getLog()





