#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

  int READ = 0;
  int WRITE = 1;
  
  int up[2];
  pipe(up);

  int down[2];
  pipe(down);

 if (fork() == 0) {
   // child process
   close(up[READ]);
   close(down[WRITE]);

   int s;
   read(down[READ], &s, sizeof(s));
   printf("[C] Reading s: %d\n", s);
   s += 1;
   printf("[C] Adding one: %d\n", s);
   write(up[WRITE], &s, sizeof(s));
 } else {
   // parent process
   close(up[WRITE]);
   close(down[READ]);

   int s = 1;
   printf("[P] Writing s: %d\n", s);
   write(down[WRITE], &s, sizeof(s));

   
   read(up[READ], &s, sizeof(s));
   printf("[P] Reading s: %d\n", s);
 }
  
  return 0;
}
