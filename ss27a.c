/*
./a.out
total 352
-rw-r--r--@ 1 dhruvasharma  staff    537 29 Aug 10:28 19.c
-rw-r--r--@ 1 dhruvasharma  staff    100 30 Aug 10:15 22.txt
-rwxr-xr-x@ 1 dhruvasharma  staff  33464 30 Aug 12:32 a.out
-rw-r--r--@ 1 dhruvasharma  staff      0  1 Jan  1980 creat().txt
-rw-r--r--@ 1 dhruvasharma  staff     65 22 Aug 09:17 example.txt
-rw-r--r--@ 1 dhruvasharma  staff     71  1 Jan  1980 example_cpy.txt
-rw-r--r--@ 1 dhruvasharma  staff     30  1 Jan  1980 example_lseek.txt
-rw-r--r--@ 1 dhruvasharma  staff    368  1 Jan  1980 ss1.c
-rw-r--r--@ 1 dhruvasharma  staff    593  1 Jan  1980 ss10.c
-rw-rw-r--@ 1 dhruvasharma  staff    595  9 Aug 14:15 ss11.c
-rw-rw-r--@ 1 dhruvasharma  staff    334  9 Aug 14:20 ss12.c
-rw-rw-r--@ 1 dhruvasharma  staff    668  9 Aug 14:28 ss13.c
-rw-r--r--@ 1 dhruvasharma  staff    131 20 Aug 10:23 ss15.c
-rw-r--r--@ 1 dhruvasharma  staff    438 21 Aug 17:59 ss16_rdlock.c
-rw-r--r--@ 1 dhruvasharma  staff    532 20 Aug 10:51 ss16_wrlock.c
-rw-r--r--@ 1 dhruvasharma  staff    859 29 Aug 09:22 ss17_read.c
-rw-r--r--@ 1 dhruvasharma  staff    357 29 Aug 09:14 ss17_store.c
-rw-r--r--@ 1 dhruvasharma  staff    405 29 Aug 10:03 ss18_create.c
-rw-r--r--@ 1 dhruvasharma  staff    465 29 Aug 10:17 ss18_read.c
-rw-r--r--@ 1 dhruvasharma  staff    100  1 Jan  1980 ss2.c
-rw-r--r--@ 1 dhruvasharma  staff    197 29 Aug 10:46 ss20.c
-rw-r--r--@ 1 dhruvasharma  staff    220 29 Aug 10:51 ss21.c
-rw-r--r--@ 1 dhruvasharma  staff    439 30 Aug 10:16 ss22.c
-rw-r--r--@ 1 dhruvasharma  staff    365 30 Aug 10:21 ss23.c
-rw-r--r--@ 1 dhruvasharma  staff    434 30 Aug 10:31 ss24.c
-rw-r--r--@ 1 dhruvasharma  staff    721 30 Aug 10:46 ss25.c
-rw-r--r--@ 1 dhruvasharma  staff    520 30 Aug 10:51 ss26.c
-rw-r--r--@ 1 dhruvasharma  staff    143 30 Aug 12:32 ss27a.c
-rw-r--r--@ 1 dhruvasharma  staff    338  1 Jan  1980 ss3.c
-rw-r--r--@ 1 dhruvasharma  staff    279  1 Jan  1980 ss4.c
-rw-r--r--@ 1 dhruvasharma  staff    445  1 Jan  1980 ss5.c
-rw-r--r--@ 1 dhruvasharma  staff    341 22 Aug 08:14 ss6.c
-rw-r--r--@ 1 dhruvasharma  staff    510 22 Aug 08:34 ss7.c
-rw-r--r--@ 1 dhruvasharma  staff    503 22 Aug 09:16 ss8.c
-rw-r--r--@ 1 dhruvasharma  staff   1106 22 Aug 08:55 ss9.c
-rwxr--r--@ 1 dhruvasharma  staff      8 29 Aug 09:22 trains.txt
-rwxr--r--@ 1 dhruvasharma  staff     24 29 Aug 10:03 trains18.txt
*/

#include <stdio.h>
#include <unistd.h>

int main(){
  int out = execl("/bin/ls", "ls", "-Rl", NULL);
  if(out < 0){
    perror("execl");
  }
}
