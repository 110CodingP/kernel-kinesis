#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main() {
  int rc = fork();
  if (rc<0) {
    fprintf(stderr,"fork failed\n");
    exit(1);
  }
  else if (rc==0) {
    int rc2= fork();
    if (rc2<0) {
        fprintf(stderr,"fork failed\n");
        exit(1);
    }
    printf("hello!\n");
    char* myargs[2];
    myargs[0]=strdup("ls");
    myargs[1]=NULL;
    execvp(myargs[0],myargs);
  }
  else {
    int rc_wait = wait(NULL);
    printf("goodbye!\n");
  }

}