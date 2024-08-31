/*
============================================================================
Name : ss27c.c
Author : Dhruva Sharma
Descripton :Write a program to execute ls -Rl by the following system calls
c. execle

============================================================================
*/
/* ./a.out
total 368
-rw-r--r--@ 1 dhruvasharma  staff    537 Aug 29 10:28 19.c
-rw-r--r--@ 1 dhruvasharma  staff    100 Aug 30 10:15 22.txt
-rwxr-xr-x@ 1 dhruvasharma  staff  33560 Aug 30 12:39 a.out
-rw-r--r--@ 1 dhruvasharma  staff      0 Jan  1  1980 creat().txt
-rw-r--r--@ 1 dhruvasharma  staff     65 Aug 22 09:17 example.txt
-rw-r--r--@ 1 dhruvasharma  staff     71 Jan  1  1980 example_cpy.txt
-rw-r--r--@ 1 dhruvasharma  staff     30 Jan  1  1980 example_lseek.txt
-rw-r--r--@ 1 dhruvasharma  staff    368 Jan  1  1980 ss1.c
-rw-r--r--@ 1 dhruvasharma  staff    593 Jan  1  1980 ss10.c
-rw-rw-r--@ 1 dhruvasharma  staff    595 Aug  9 14:15 ss11.c
-rw-rw-r--@ 1 dhruvasharma  staff    334 Aug  9 14:20 ss12.c
-rw-rw-r--@ 1 dhruvasharma  staff    668 Aug  9 14:28 ss13.c
-rw-r--r--@ 1 dhruvasharma  staff    131 Aug 20 10:23 ss15.c
-rw-r--r--@ 1 dhruvasharma  staff    438 Aug 21 17:59 ss16_rdlock.c
-rw-r--r--@ 1 dhruvasharma  staff    532 Aug 20 10:51 ss16_wrlock.c
-rw-r--r--@ 1 dhruvasharma  staff    859 Aug 29 09:22 ss17_read.c
-rw-r--r--@ 1 dhruvasharma  staff    357 Aug 29 09:14 ss17_store.c
-rw-r--r--@ 1 dhruvasharma  staff    405 Aug 29 10:03 ss18_create.c
-rw-r--r--@ 1 dhruvasharma  staff    465 Aug 29 10:17 ss18_read.c
-rw-r--r--@ 1 dhruvasharma  staff    100 Jan  1  1980 ss2.c
-rw-r--r--@ 1 dhruvasharma  staff    197 Aug 29 10:46 ss20.c
-rw-r--r--@ 1 dhruvasharma  staff    220 Aug 29 10:51 ss21.c
-rw-r--r--@ 1 dhruvasharma  staff    439 Aug 30 10:16 ss22.c
-rw-r--r--@ 1 dhruvasharma  staff    365 Aug 30 10:21 ss23.c
-rw-r--r--@ 1 dhruvasharma  staff    434 Aug 30 10:31 ss24.c
-rw-r--r--@ 1 dhruvasharma  staff    721 Aug 30 10:46 ss25.c
-rw-r--r--@ 1 dhruvasharma  staff    520 Aug 30 10:51 ss26.c
-rw-r--r--@ 1 dhruvasharma  staff   2491 Aug 30 12:34 ss27a.c
-rw-r--r--@ 1 dhruvasharma  staff   2488 Aug 30 12:35 ss27b.c
-rw-r--r--@ 1 dhruvasharma  staff    171 Aug 30 12:39 ss27c.c
-rw-r--r--@ 1 dhruvasharma  staff    338 Jan  1  1980 ss3.c
-rw-r--r--@ 1 dhruvasharma  staff    279 Jan  1  1980 ss4.c
-rw-r--r--@ 1 dhruvasharma  staff    445 Jan  1  1980 ss5.c
-rw-r--r--@ 1 dhruvasharma  staff    341 Aug 22 08:14 ss6.c
-rw-r--r--@ 1 dhruvasharma  staff    510 Aug 22 08:34 ss7.c
-rw-r--r--@ 1 dhruvasharma  staff    503 Aug 22 09:16 ss8.c
-rw-r--r--@ 1 dhruvasharma  staff   1106 Aug 22 08:55 ss9.c
-rwxr--r--@ 1 dhruvasharma  staff      8 Aug 29 09:22 trains.txt
-rwxr--r--@ 1 dhruvasharma  staff     24 Aug 29 10:03 trains18.txt
*/
#include <stdio.h>
#include <unistd.h>

int main(){
  char *environment[] = {"PATH=/bin:/usr/bin", NULL};
  int out = execle("/bin/ls", "ls", "-Rl", NULL, environment);
}
