import os 
import sys

def Dir_toStdName(path):
	if not (path[-1]=="/" or path[-1] == "//"):
		path=path+"/"

	return path


def Dir_getFiles(path):
	path=Dir_toStdName(path)
	
	allfiles=[]
	files=os.listdir(path)

	for f in files:
		abs_path = path + f 
		if os.path.isdir(abs_path):
			sub_files=Dir_getFiles(abs_path)
			sub_files=[ f+'/'+i for i in sub_files ]
			allfiles.extend(sub_files)
		else:
			allfiles.append(f)

	
	return allfiles






class Dir:
	def __init__(self,dir_name):
		self.m_dir=Dir_toStdName(dir_name)


	def listDir(self):
		return os.listdir(self.m_dir)


	def listFiles(self):
		return Dir_getFiles(self.m_dir)


if __name__ == "__main__":
	print sys.argv
	if len(sys.argv)>=2 : 
		files_dir=sys.argv[1] 
	else: 
		files_dir="."

	d=Dir(files_dir)
	for k in d.listFiles():
		print "src/"+k
	#print d.listFiles()
	




