#ifndef file_partition_h
#define file_partition_h
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

int write_data_test(int *filedesc);
int write_string_top(int *filedesc, char *data, int size);
int write_string(int *filedesc, char *data, int size);
int write_file(int *filedesc, char *file_location);

//read data from the FD
int read_data(int *filedesc);

int find_last_data(int *filedesc);
int find_file_num(int *filedesc, int filenumber);
#endif
