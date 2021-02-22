#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int     fd, result;
  size_t  size;
  char    resstring[14];
  char    name[] = "aaa.fifo";
  (void)umask(0);
	printf("write into fifo\n");

   /* Parent process */

    if ((fd = open(name, O_WRONLY)) < 0) {
      printf("Can\'t open FIFO for writting\n");
      exit(-1);
    }

    size = write(fd, "Hello, world!", 14);
	printf("wrote into fifo\n");
    if (size != 14) {
      printf("Can\'t write all string to FIFO\n");
      exit(-1);
    }
    close(fd);
    printf("WRITE INTO FIFO exit\n");

  return 0;
}

