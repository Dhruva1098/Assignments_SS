#include <stdio.h>
#include <fcntl.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include <sys/types.h>

struct ticket_info{
  int ticket_no;
  int train_no;
};

int main(){
  struct ticket_info info; struct flock lock;
  int fd = open("trains18.txt", O_RDWR, 0644);
  printf("Enter train number to get ticket info:");
  int train_no;
  scanf("%d", &train_no);
  lock.l_type = F_RDLCK;
  lock.l_start = (train_no - 1)*sizeof(info);
  lock.l_len = sizeof(info);


}
