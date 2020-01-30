#include"file_partition.h"

int main()
{
  int fd, rtncode=0;
  open_file_desc("test.txt", &fd);
  printf("\nfd=%i",fd);
  char *txt = "this is a test of write_string_top\n";
  int numskip = find_last_data(&fd);

  rtncode = write_string(&fd, txt, strlen(txt));

  txt = "testing second string\n";
  rtncode = write_string(&fd, txt, strlen(txt));

  txt = "src/main.c";
  rtncode = write_file(&fd, txt);

  printf("\n rtncode = %d",rtncode);
//  write_data(&fd);
//  close_file_desc(&fd);
//  fd = open_file_desc("test.txt");

//int fsync(int fd);
  lseek(fd, 0, SEEK_SET);

  while (read_data(&fd) > 1);
  //read_data(&fd);

  close_file_desc(&fd);
  return 0;
}
