#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main() {
    close(STDOUT_FILENO);
    open("./input.txt",O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
    int rc = fork();
    if (rc<0) {
        fprintf(stderr,"fork failed\n");
        exit(1);
    }
    else if (rc==0) {
        printf("Hi I am the child. PID: %d\n",(int)getpid());
    }
    else {
        printf("Hi I am the parent. PID: %d\n",(int)getpid());
    }
    return 0;
}
//O_Creat etc. were not turning blue just because didn't write ./
//input.txt