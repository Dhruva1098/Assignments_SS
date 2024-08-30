/*
cat 22.txt
this is parent proocessThis is child Process%
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
  int fd = open("22.txt", O_WRONLY);
  if(fd < 0){
    perror("open");
    return 1;
  }
  int pid = fork();
  if(pid == 0){
    char buff[50] = "This is child Process";
    write(fd, buff, sizeof(buff));
  } else {
    char buff[50] = "this is parent proocess";
    write(fd, buff, sizeof(buff));
  }
}
