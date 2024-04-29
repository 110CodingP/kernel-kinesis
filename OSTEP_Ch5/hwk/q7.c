#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int rc1=fork();
    int rc2=fork();
    if (rc1<0||rc2<0) {
        fprintf(stderr,"one of the forks failed!");
        exit(1);
    }
    else if (rc1==0) {

    }
    else if (rc2==0) {
        int rc_wait1= waitpid();

    }
    else {

    }
    //how do we know which process stops first?
    return 0;
}