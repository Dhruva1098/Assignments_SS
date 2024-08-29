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
