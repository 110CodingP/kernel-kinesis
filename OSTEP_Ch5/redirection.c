#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    int rc = fork();
    if (rc<0) {
        fprintf(stderr,"fork failed\n");
        exit(1);
    }
    else if (rc==0) {
        close(STDOUT_FILENO);
        open("./redirection.txt",O_CREAT|O_WRONLY|O_TRUNC,S_IRWXU);
        char* myargs[3];
        myargs[0] = strdup("wc");
        myargs[1] = strdup("redirection.c");
        myargs[2] = NULL;
        execvp(myargs[0],myargs);
        
    }
    else {
        int rc_wait = wait(NULL);
    }
    return 0;
}

//We need both sys/types.h and sys/stat.h for S_IRWXU to be defined

//wc: write error: Bad file descriptor resolved this error by renaming
// redirection.output to redirection.txt