#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/wait.h>

int main() {
    int i=0;
    int rc = fork();
    if (rc<0) {
        fprintf(stderr,"fork failed\n");
        exit(1);
    }
    else if (rc==0) {
        close(STDOUT_FILENO);
        open("./input2.txt",O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
        printf("Hi I am the child. PID: %d\n",(int)getpid());
        i++;
        printf("%d\n",i);
    }
    else {
        int rc_wait=wait(NULL);
        printf("Hi I am the parent. PID: %d\n",(int)getpid());
        i+=2;
        printf("%d\n",i);
    }
    return 0;
}
//O_Creat etc. were not turning blue just because didn't write ./
//input.txt
//strange output!