import string 
import os 
from ..files import Dir 
class LuaCompiler:
	def __init__(self,working_dir):
		self.m_workingDir=working_dir
		self.m_binName="luac.exe"
	
	def setBinName(self,binname):
		self.m_binName=binname

	def compile(self):
		all_files=[]
		# get all file from working_dir 
		for dname in self.m_workingDir:
			dname=Dir.Dir_toStdName(dname)
			diry=Dir.Dir(dname)
			fs=diry.listFiles()
			fs=[dname+f for f in fs]
			all_files.extend(fs)
		
		# filter *.lua files 
		all_files=[f for f in all_files if f[-4:]==".lua"]
		for f in all_files:
			fin=f 
			fout=f[0:-1]+"c"
			args=[self.m_binName,"-o",fout,fin]
			commond=string.join(args," ")
			print "compile "+f
			os.system(commond)












