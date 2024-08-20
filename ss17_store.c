#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
struct ticket_info{
    int ticket_no;
};
int main(){
    int fd = open("trains.txt", O_RDWR);
    ticket_info one = {10};
    int out = write(fd, &one, sizeof(ticket_info));
    if(out < 0) perror("write");
    close(fd);
}
