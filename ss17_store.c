#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
struct ticket_info{
    int ticket_no;
};
int main(){
    int fd = open("trains.txt", O_RDWR|O_CREAT, 0744);
    if(fd < 0){
        perror("open");
    }
    struct ticket_info one = {1};
    int out = write(fd, &one, sizeof(one));
    if(out < 0) {
        perror("write");
    }
    close(fd);
}
