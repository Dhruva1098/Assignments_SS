#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

struct ticket_info{
  int ticket_no;
  int train_no;
};

int main(){
  int fd = open ("trains18.txt", O_RDWR | O_CREAT, 0744);
  if(fd < 0){
    perror("open");
  }
  struct ticket_info one = {1,1}, two = {1,2}, three = {1,3};
  
  write(fd, &one, sizeof(one));
  write(fd, &two, sizeof(two));
  write(fd, &three, sizeof(three));

  close(fd);
}
