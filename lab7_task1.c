#include <sys/types.h>

#include <sys/ipc.h>

#include <sys/shm.h>

#include <stdio.h>

#include <errno.h>

#include <stdlib.h>

int main()

{

  char     *array;   

  int     shmid;     

  char    pathname[] = "lab7_task2.c";
  key_t   key;     
  
int file_size = 0;
int *int_f;
FILE *file;
file = fopen(pathname, "r");

fseek(file, 0L, SEEK_END);
file_size = ftell(file);
rewind(file);

  if ((key = ftok(pathname,0)) < 0) {

    printf("Can\'t generate key\n");

    exit(-1);

  }

  if ((shmid = shmget(key, 3*sizeof(int), 0666|IPC_CREAT|IPC_EXCL)) < 0) {

    if (errno != EEXIST) {

      printf("Can\'t create shared memory\n");

      exit(-1);

    } else {

      if ((shmid = shmget(key, 3*sizeof(int), 0)) < 0) {

        printf("Can\'t find shared memory\n");

        exit(-1);

      }

    }

  }

  if ((int_f = (int *)shmat(shmid, NULL, 0)) == (int *)(-1)) {

    printf("Can't attach shared memory\n");

    exit(-1);

  }

*int_f = file_size;
array = (char*)(int_f + 1);
for (int i = 0; i < file_size; i++) array[i] = fgetc(file);
fclose(file);

  if (shmdt(int_f) < 0) {
    printf("Can't detach shared memory\n");
    exit(-1);
  }

  return 0;

}

