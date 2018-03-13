#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<sys/types.h>
int main()
{
  int filedesc = open("/dev/sdb1", O_RDONLY);

  if(filedesc < 0) 
  {
    printf("\nError opening file");
    return 1;
  }
  int numwritten=0;
  char data[512];
  int intdata[512];
//  lseek(filedesc, 40, SEEK_SET);
  for(int i=0; i<5;i++)
  {
    numwritten = read(filedesc, intdata, 512);
    for(int j=0; j<100; j++)
    {
      data[j] = (char) intdata[j];


    }
    printf("\nnumwritten=%i data=",numwritten);
    for( int j=0;j<100;j++)
    {
      printf("%i ",intdata[j]);

    }
    printf("\n");
  }

  close(filedesc);


  return 0;
  
  









}
