#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  int pid = (int)getpid();
  int rc = fork();
  if (rc<0) {
    fprintf(stderr,"fork failed\n");
    exit(1);
  }
  else if (rc==0) {
    int rc_wait = waitpid(pid,NULL,WNOHANG);
    printf("hello I am %d!\n",(int)getpid());
  }
  else {
    //int rc_wait = wait(NULL); //hence wait returns process id of child
    //printf("%d\n",rc_wait);
    printf("goodbye I am %d!\n",(int)getpid());
  }
}