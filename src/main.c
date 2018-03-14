#include"file_partition.h"

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

