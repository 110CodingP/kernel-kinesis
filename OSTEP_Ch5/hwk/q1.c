#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  int x=5;
  printf("The value of x is %d\n",x);
  int rc = fork();
  if (rc<0) {
    fprintf(stderr,"fork failed\n");
    exit(1);
  }
  else if (rc==0) {
    printf("Hi! I am the child. PID: %d\n",(int)getpid());
    x=4;
    printf("The value of x is %d\n",x);
  }
  else {
    printf("Hi! I am the parent. PID: %d",(int)getpid());
    x=6;
    printf("The value of x is %d\n",x);
  }

}