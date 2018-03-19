#include"file_partition.h"


int write_string_top(int *filedesc, char *data, int size)
{
  int numwritten=0;
  int intdata[size];

  
  lseek((*filedesc), 0, SEEK_SET);
  numwritten = write((*filedesc), &size, sizeof(int));
  printf("\numwritten=%i",numwritten);
  for(int i=0; i<size; i++)
  {
    intdata[i] = (int) data[i];
  }
  numwritten = write((*filedesc), intdata, size*sizeof(int));

  printf("\n\nwritesize=%i \ndata=",size);
  for( int j=0;j<size;j++)  printf("%i ",intdata[j]);
  printf(";\n\n");
  for( int j=0;j<size;j++)  printf("%c",data[j]);
  printf(";\n");

  return numwritten;
}
int write_data_test(int *filedesc)
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



