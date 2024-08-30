/*
./a.out ls
19.c			ss18_read.c
22.txt			ss2.c
a.out			ss20.c
creat().txt		ss21.c
example.txt		ss22.c
example_cpy.txt		ss23.c
example_lseek.txt	ss24.c
ss1.c			ss25.c
ss10.c			ss26.c
ss11.c			ss3.c
ss12.c			ss4.c
ss13.c			ss5.c
ss15.c			ss6.c
ss16_rdlock.c		ss7.c
ss16_wrlock.c		ss8.c
ss17_read.c		ss9.c
ss17_store.c		trains.txt
ss18_create.c		trains18.txt
*/



#include <stdio.h>
#include <unistd.h>

int main( int argc, char *argv[]){
  int out = execvp(argv[1], &argv[1]);
  if(out < 0){
    perror("execvp");
  }
}
