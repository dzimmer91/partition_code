#include"file_partition.h"



int read_data(int *filedesc)
{
  int readsize=0, size=0;

  readsize = read(*filedesc, &size, sizeof(int));
  if(readsize < 1){
    printf("\nread_data readsize=%d",readsize);
    return -1;
  }
  printf("\nread_data Size=%d",size);
  char data[size];
  int intdata[size];
  for(int i=0; i<sizeof(data); i++)
  {
    data[i]='\0';
  }
  readsize = read(*filedesc, intdata, size*sizeof(int));
  for(int j=0; j<size; j++)
  {
    data[j] = (char) intdata[j];
  }
  printf("\n\nreadsize=%i \ndata=",readsize);
  for( int j=0;j<size;j++)  printf("%i ",intdata[j]);
  printf(";\n\n");
  for( int j=0;j<size;j++)  printf("%c",data[j]);
  printf(";\n");
  return size;

}


int read_data_test(int *filedesc)
{
  int readsize=0;
  char data[512];
  int intdata[512];
  lseek(*filedesc, 0, SEEK_SET);
  readsize = read(*filedesc, intdata, 512);
  for(int j=0; j<100; j++)
  {
    data[j] = (char) intdata[j];
  }
  printf("\nreadsize=%i data=",readsize);
  for( int j=0;j<100;j++)  printf("%i ",intdata[j]);
  printf("\n");
  for( int j=0;j<100;j++)  printf("%c",data[j]);
  printf("\n");
  return 1;

}
