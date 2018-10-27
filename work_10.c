#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

int randval(){
  int randfile = open("/dev/random", O_RDONLY);
  if(randfile < 0){
    printf("Error num: %d in open, %s\n", errno, strerror(errno));
    return -1;
  }

  int buff;
  int vals = read(randfile, &buff, sizeof(buff));
  if(vals < sizeof(buff)){
    printf("Error num: %d in read, %s\n", errno, strerror(errno));
    return -1;
  }
  close(randfile);
  return buff;
}
