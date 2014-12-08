import io 
import gzip 
import struct 
from FgzWriter import *


class FgzReader:
	def __init__(self,source):
		self.m_url=source
		self.m_stream=open(source,"rb")
		self.parsePackage()

	def parsePackage(self):
		fp=self.m_stream;
		fp.seek(0,0)
		fgz_magic_nu=fp.read(8)
		if fgz_magic_nu!=FgzMagicNumber:
			raise Exception("File \"%s\" is not Fgz Package"%(self.m_url))

		self.m_fileNu=struct.unpack("I",fp.read(4))[0]
		self.m_dataOffset=struct.unpack("I",fp.read(4))[0]

		fp.seek(self.m_dataOffset,0)

		self.m_files={}
		for i in range(0,self.m_fileNu):
			cur_file={}
			file_magic_nu=fp.read(8)
			if file_magic_nu != FgzFileMagicNumber:
				raise Exception("File \"%s\" Fgz Package damage"%(self.m_url))

			cur_file["method"]=struct.unpack("I",fp.read(4))[0]
			cur_file["compressSize"]=struct.unpack("I",fp.read(4))[0]
			cur_file["unCompressSize"]=struct.unpack("I",fp.read(4))[0]
			cur_file["crc32"]=struct.unpack("I",fp.read(4))[0]
			cur_file["filenameLength"]=struct.unpack("I",fp.read(4))[0]
			cur_file["filename"]=fp.read(cur_file["filenameLength"])
			offset=fp.tell()
			cur_file["offset"]=offset
			self.m_files[cur_file["filename"]]=cur_file

			fp.seek(offset+cur_file["compressSize"],0)




	def getFileInfo(self,filename):
		return self.m_files[filename]

	def getAllFileInfo(self):
		return self.m_files

	def printAllFileInfo(self):
		print "%s package info:files(%d)"%(self.m_url,self.m_fileNu)
		for filename in self.m_files:
			info=self.m_files[filename]

			method="unkown"
			if(info["method"]==FgzStore):
				method="store"
			elif(info["method"]==FgzDeflate):
				method="deflate"
			elif(info["method"]==FgzLzma):
				method="lzma"

			print "\tfilename:%s, method:%s, ensize:%d, unsize:%d, crc32:%d, radio:%f" %( 
										info["filename"],
										method,info["compressSize"],
										info["unCompressSize"],
										info["crc32"],
										float(info["compressSize"])/float(info["unCompressSize"]))


	def readFile(self,filename):
		info=self.m_files[filename] 
		if info is None:
			raise Exception("File \"%s\" Not Found"%(filename))

		self.m_stream.seek(info["offset"])

		ret=self.m_stream.read(info["compressSize"])
		if gzip.zlib.crc32(ret,FgzCrc32Default) != info["crc32"]:
			raise Exception("File \"%s\" Content Damage"%(filename))

		if info["method"]==FgzStore:
			return ret 
		elif info["method"]==FgzDeflate:
			ret1=gzip.zlib.decompress(ret)
			return ret1

		else:
			raise Exception("Unkown Compress Method For File \"%s\""%(filename))




if __name__=="__main__":
	fgzreader=FgzReader("tmp.fgz")
	fgzreader.printAllFileInfo()
	log=fgzreader.readFile("log.txt")
	print log 
























