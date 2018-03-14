#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<sys/types.h>
#include<string.h>


//open a fd as read/write | create if file doesn't exists
int open_file_desc(char *filename, int *filedesc);
//close the open FD
int close_file_desc(int *filedesc);
//write data to the FD
int write_data(int *filedesc);
//read data from the FD
int read_data(int *filedesc);

