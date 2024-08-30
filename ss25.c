/*
child process 1, pid:9693
child process 2, pid:9694
waiting for child 9694 to finish
child process 3, pid:9695
parent process is finished%
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
  int pid1,pid2,pid3, stat;
  pid1 = fork();
  if(pid1 == 0){
    printf("child process 1, pid:%d \n", getpid());
    sleep(2);
    exit(0);
  }
  pid2 = fork();
   if(pid2 == 0){
    printf("child process 2, pid:%d \n", getpid());
    sleep(4);
    exit(0);
  } 
  pid3 = fork();
  if(pid3 == 0){
    printf("child process 3, pid:%d \n", getpid());
    sleep(2);
    exit(0);
  } 
  printf("waiting for child %d to finish\n", pid2);
  waitpid(pid2, &stat, 0);
  printf("parent process is finished");
}
