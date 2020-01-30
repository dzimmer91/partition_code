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
    intdata[i] = ( (int) data[i] ) * 5;
  }
  numwritten = write((*filedesc), intdata, size*sizeof(int));

  printf("\n\nwritesize=%i \ndata=",size);
  for( int j=0;j<size;j++)  printf("%i ",intdata[j]);
  printf(";\n\n");
  for( int j=0;j<size;j++)  printf("%c",data[j]);
  printf(";\n");

  return numwritten;
}

int write_file(int *filedesc, char *file_location)
{
  FILE *input_File;
  int filesize = 0, numwritten = 0;

  input_File = fopen(file_location, "rb");
  if (input_File == NULL) return -1;

  fseek(input_File, 0, SEEK_END);
  filesize = ftell(input_File);

  numwritten = write((*filedesc), &filesize, sizeof(int));
  if(numwritten > 0){
    printf("\numwritten=%i",numwritten);
  }else{
    printf("Error: writing file size to FD\n" );
    fclose(input_File);
    return -1;
  }
  //todo need to check to X size for writing file in blocks incase file is larger then mem;
  int intdata[filesize];
  char data;
  fseek(input_File, 0, SEEK_SET);

  for(int i=0; i<filesize; i++)
  {
    data = fgetc(input_File);
    intdata[i] = ( (int) data ) * 5;
  }
  numwritten = write((*filedesc), intdata, filesize*sizeof(int));

  //printf("\n\nwritesize=%i \ndata=",filesize);
  //for( int j=0;j<filesize;j++)  printf("%i ",intdata[j]);
  //printf(";\n\n");
  fclose(input_File);
  return numwritten;
}


int write_string(int *filedesc, char *data, int size)
{
  int numwritten=0;
  int intdata[size];


  numwritten = write((*filedesc), &size, sizeof(int));
  printf("\numwritten=%i",numwritten);
  for(int i=0; i<size; i++)
  {
    intdata[i] = ( (int) data[i] ) * 5;
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
