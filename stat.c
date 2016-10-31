#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <sys/stat.h>
#include <string.h>

int main() {
  char filename[20] = "test.txt";
  struct stat* info = (struct stat*)malloc(sizeof(struct stat));
  if(stat(filename, info) == -1) {
      printf(strerror(errno));
      return errno;
  };
  printf("Size: %d", info->st_size);
  printf("\nMode: %o", info->st_mode);
  printf("\nTime: %s", ctime(&(info->st_atime)));
  free(info);
  return 0;}
