/*
parent process pid: 8738:
child process ppid: 8738:
[2]  + 8738 done       ./a.out
child process ppid now:1
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
  int pid;
  pid = fork();
  if(pid == 0){
    printf("child process ppid: %d:\n", getppid());
    sleep(5);
    printf("child process ppid now:%d \n", getppid());
  } else {
    printf("parent process pid: %d: \n", getpid());
    exit(0);
  }
}
