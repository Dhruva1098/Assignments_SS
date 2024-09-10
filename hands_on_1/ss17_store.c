/*
============================================================================
Name : ss17_write.c
Author : Dhruva Sharma
Descripton : Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
============================================================================
*/

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
