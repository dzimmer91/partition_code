#include"file_partition.h"

int main()
{
  int fd, rtncode=0;
  open_file_desc("test.txt", &fd);
  printf("\nfd=%i",fd);
  char *txt = "this is a test of write_string_top\n";
  rtncode = write_string(&fd, txt, strlen(txt));

  txt = "testing second string\n";
  rtncode = write_string(&fd, txt, strlen(txt));


  printf("\n rtncode = %d",rtncode);
//  write_data(&fd);
//  close_file_desc(&fd);
//  fd = open_file_desc("test.txt");
  lseek(fd, 0, SEEK_SET);

  int numskip = find_last_data(&fd);
  printf("\n returned find_last_data numskip =%d",numskip);
  txt = "returned find_last_data numskip =2\n";
  rtncode = write_string(&fd, txt, strlen(txt));

  lseek(fd, 0, SEEK_SET);
  numskip = find_file_num(&fd, 1);
  printf("\n returned find_file_num numskip =%d",numskip);

  while (read_data(&fd) > 1);
  //read_data(&fd);

  close_file_desc(&fd);
  return 0;
}
