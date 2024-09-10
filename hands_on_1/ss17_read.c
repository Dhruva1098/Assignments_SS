/*
============================================================================
Name : ss17_read.c
Author : Dhruva Sharma
Descripton : Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <sys/_types/_ssize_t.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include <sys/types.h>
struct ticket_info{
    int ticket_no;
};
int main(){
    struct ticket_info info;
    int fd = open("trains.txt", O_RDWR, 0777);
    read(fd, &info , sizeof(info));
    if (fd < 0) {
        perror("open");
    }
    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();
    printf("entering cs \n");
    fcntl(fd,F_SETLKW, &lock);
    printf("current value of ticket no is %d \n press enter to update value", info.ticket_no);
    getchar();
    info.ticket_no++;
    lseek(fd, 0, SEEK_SET);
    write(fd, &info, sizeof(info));
    lock.l_type = F_UNLCK;
    fcntl(fd,F_SETLK, &lock);
    printf("out of CS \n");
    close(fd);
}
