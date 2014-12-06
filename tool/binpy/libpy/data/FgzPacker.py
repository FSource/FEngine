from FgzWriter import FgzWriter
from ..files import Dir

class FgzPacker:
	def __init__(self,working_dir,target_dir):
		self.m_workingDir=[]
		for d in working_dir:
			self.m_workingDir.append(Dir.Dir_toStdName(d))

		self.m_targetDir=Dir.Dir_toStdName(target_dir)
		self.m_packageName="fdata.fgz"

		self.m_ignoreFileExt=[]
		self.m_notCompressFileExt=[]

	
	def setPackageName(self,name):
		self.m_packageName=name 

	def setIngoreFileExt(self,exts):
		self.m_ignoreFileExt=exts 

	def setNotCompressFileExt(self,exts):
		self.m_notCompressFileExt=exts

	def ingoreFile(self,filename):
		for ext in self.m_ignoreFileExt:
			if filename.endswith(ext):
				return True 

		return False

	def notCompressFile(self,filename):
		for ext in self.m_notCompressFileExt:
			if filename.endswith(ext):
				return True 

		return False






	def pack(self):
		pack_files=[]
		for d in self.m_workingDir:
			diry=Dir.Dir(d)
			all_files=diry.listFiles()
			all_files=[f for f in all_files if not self.ingoreFile(f) ]
			pack_files.append({"dir":d,"files":all_files})


		writer=FgzWriter()
		for info in pack_files:
			dirname=info["dir"]
			files=info["files"]

			for f in files:
				if self.notCompressFile(f):
					method="store"
				else:
					method="deflate"

				file_name=dirname+f
				writer.addFile(file_name,f,method)

		package_path=self.m_targetDir+self.m_packageName
		writer.pack(package_path)








