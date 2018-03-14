#include"file_partition.h"

int read_data(int *filedesc)
{
  int numwritten=0;
  char data[512];
  int intdata[512];
  lseek(*filedesc, 0, SEEK_SET);
  numwritten = read(*filedesc, intdata, 512);
  for(int j=0; j<100; j++)
  {
    data[j] = (char) intdata[j];
  }
  printf("\nnumwritten=%i data=",numwritten);
  for( int j=0;j<100;j++)  printf("%i ",intdata[j]);
  printf("\n");
  for( int j=0;j<100;j++)  printf("%c",data[j]);
  printf("\n");
  return 1;

}
