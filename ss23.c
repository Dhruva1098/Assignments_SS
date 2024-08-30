/*
dhruvasharma      8291   0.0  0.0        0      0 s000  ZN   10:20am   0:00.00 <defunct>
* */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
  int pid;
  pid = fork();
  if(pid == 0) {
    printf("child Process \n");
    exit(0);
  } else {
    printf("parent process \n");
    sleep(20);
    printf("exiting parent process \n");
  }
}
