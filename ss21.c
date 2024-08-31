/*
============================================================================
Name : ss21.c
Author : Dhruva Sharma
Descripton :Write a program, call fork and print the parent and child process id.

============================================================================
*/
/*
./a.out
Parent Process pid is: 18082
Child Process pid is: 18083
*/


#include <stdio.h>
#include <unistd.h>

int main(){
  int pid;
  pid = fork();

  if(pid == 0){
    printf("Child Process pid is: %d \n", getpid());
  } else {
    printf("Parent Process pid is: %d \n", getpid());
  }
}
