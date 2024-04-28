#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>//?

int main() {
  printf("hello (pid:%d) \n", (int) getpid());//pid means process id
  int rc = fork();
  if (rc<0) {
    //fork failed
    fprintf(stderr,"fork failed\n");
    exit(1);
  }
  else if (rc==0) {
    //?
    printf("child (pid:%d)\n",(int) getpid());
  }
  else {
    //?
    printf("parent of %d (pid: %d)\n", rc, (int) getpid());
  }
  return 0;
}
