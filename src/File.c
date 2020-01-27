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

int find_last_data(int *filedesc)
{
  int readsize = 0, size = 0, numskipped = 0;
  while(1){

    readsize = read(*filedesc, &size, sizeof(int));
    if(readsize > 0){
      lseek(*filedesc, sizeof(int)*size, SEEK_CUR);
      ++numskipped;
    }
    else{
      return numskipped;
    }
  }
}

int find_file_num(int *filedesc, int filenumber)
{
  int readsize = 0, size = 0, numskipped = 0;
  while(1){

    readsize = read(*filedesc, &size, sizeof(int));
    if(readsize > 0 && numskipped < filenumber){
      lseek(*filedesc, sizeof(int)*size, SEEK_CUR);
      ++numskipped;
    }
    else{
      lseek(*filedesc, sizeof(int)*-1, SEEK_CUR);
      return numskipped;
    }
  }
}
