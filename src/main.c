#include"file_partition.h"

int main()
{
  int fd, rtncode=0;
  open_file_desc("test.txt", &fd);
  printf("\nfd=%i",fd);
  char *txt = "this is a test of write_string_top\n";
  rtncode = write_string_top(&fd, txt, strlen(txt));

  printf("\n rtncode = %d",rtncode);
//  write_data(&fd);
//  close_file_desc(&fd);
//  fd = open_file_desc("test.txt");
  read_data(&fd);
  close_file_desc(&fd);
  return 0;
}

