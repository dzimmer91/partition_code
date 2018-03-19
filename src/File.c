#include"file_partition.h"

int open_file_desc(char *filename, int *filedesc)
{
  *filedesc = open(filename, O_RDWR |  O_CREAT);

  if(*filedesc < 0) 
  {
    printf("\nError opening file");
    return -1;
  }else   return 1; //filedesc;
}
int close_file_desc(int *filedesc)
{
  close(*filedesc);
  return 1;
 
}


