#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <errno.h>
#include <sys/stat.h>
#include <string.h>

char *get_perms(int iperms) {
  char *perms = (char *)calloc(sizeof(char), 10);
  perms[9] = 0;
  int i = 2;
  for(i = 2; i >= 0; i--) {
    int perm = iperms % 8;
    iperms /= 8;
    perms[i * 3 + 2] = perm % 2 == 1 ? 'x' : '-';
    perm /= 2;
    perms[i * 3 + 1] = perm % 2 == 1 ? 'w' : '-';
    perm /= 2;
    perms[i * 3] = perm % 2 == 1 ? 'r' : '-'; // a bit bashy but it's ok
  }
  return perms;
}

void get_size(long sizeb) {
  printf("\nSize: ");
  if (sizeb < 1024){
    printf(" %ld B", sizeb);
  } 
  else if ( sizeb < 1024*1024 ){
    printf("%ld KB",sizeb/1024);
	}
  else if (sizeb < 1024*1024*1024){
    printf(" %ld MB",sizeb/1024*1024);
  } 
  else {
    printf(" %ld GB",sizeb/1024*1024*1024);
  }
  return;
} 

int main() {
  char filename[20] = "test.txt";
  struct stat* info = (struct stat*)malloc(sizeof(struct stat));
  if(stat(filename, info) == -1) {
      printf(strerror(errno));
      return errno;
  };
  long sizedd = (long)info->st_size;
  get_size(sizedd);
  printf("\nMode: %s", get_perms(info->st_mode));
  printf("\nTime: %s", ctime(&(info->st_atime)));
  free(info);
  return 0;
}
