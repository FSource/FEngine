#include "unzipext.h"

extern unsigned int  ZEXPORT unzextGetFileOffset ( file)
	unzFile file;
{
	unsigned int  offset;
	unz_s* z_file=(unz_s*) file;
	unzOpenCurrentFile(file);




	offset= z_file->pfile_in_zip_read->pos_in_zipfile+
					z_file->pfile_in_zip_read->byte_before_the_zipfile;

	
	unzCloseCurrentFile(file);
	return offset;
}




