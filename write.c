#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>

int main()
{
  int filedesc = open("/dev/sdb1", O_WRONLY | O_APPEND);

  if(filedesc < 0) 
  {
    printf("\nError opening file");
    return 1;
  }
  int numwritten=0;
  char data[512];
  int intdata[512];
   for(int i=0; i<sizeof(data); i++)
  {
    data[i]='\0';
  }
  strcpy(data, "data to write to file....");
  
  lseek(filedesc, 0, SEEK_SET);
 
  for(int i=0; i<sizeof(data); i++)
  {
    intdata[i] = (int) data[i];
  }


  numwritten = write(filedesc, intdata, 512);

  printf("\nnumwritten=%i \n",numwritten);


  close(filedesc);


  return 0;
  
  









}
