#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "work_10.h"

int main() {

  printf("Generating random numbers:\n");

  int randvals[10];
  int counter = 10;

  while(counter--){
    randvals[counter] = randval();
    printf("random %d: %d\n", counter, randvals[counter]);
  }

  printf("\nWriting numbers to file...\n");

  int foo_file = open("foo.txt", O_WRONLY | O_CREAT, 0700);
  if(foo_file < 0){
    printf("Error num: %d in open, %s\n", errno, strerror(errno));
    return -1;
  }

  int foo_write = write(foo_file, randvals, sizeof(int)*10);
  if (foo_write < 0){
    printf("Error num: %d in write, %s\n", errno, strerror(errno));
    return -1;
  }
  close(foo_file);

  printf("\nReading numbers from file...\n");
  foo_file = open("foo.txt", O_RDONLY);
  if (foo_file < 0) {
    printf("Error num: %d in open, %s\n", errno, strerror(errno));
    return -1;
  }

  int readvals[10];

  int foo_read = read(foo_file, readvals, sizeof(int)*10);
  if (foo_read < 0){
    printf("Error num: %d in read, %s\n", errno, strerror(errno));
    return -1;
  }
  close(foo_file);

  printf("\nVerification that written values are the same:\n");

  counter = 10;
  while(counter--){
    printf("random %d: %d\n", counter, randvals[counter]);
  }

  return 0;
}
