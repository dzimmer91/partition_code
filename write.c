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

int write_data(int *filedesc)
{
  int numwritten=0;
  char data[512];
  int intdata[512];
   for(int i=0; i<sizeof(data); i++)
  {
    data[i]='\0';
  }
  strcpy(data, "data to write to file....");
  
  lseek((*filedesc), 0, SEEK_SET);
 
  for(int i=0; i<sizeof(data); i++)
  {
    intdata[i] = (int) data[i];
  }


  numwritten = write((*filedesc), intdata, 512);

  printf("\nnumwritten=%i \n",numwritten);
  return 1;
}
int close_file_desc(int *filedesc)
{
  close(*filedesc);
  return 1;
 
}

int main()
{
  int fd;
  open_file_desc("test.txt", &fd);
  printf("\nfd=%i",fd);
  write_data(&fd);
//  close_file_desc(&fd);
//  fd = open_file_desc("test.txt");
  read_data(&fd);
  close_file_desc(&fd);
  return 0;
}

