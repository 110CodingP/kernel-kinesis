#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    int x,y;
} myret_t;

void* mythread(void* arg) {
    myret_t* rvals = malloc(sizeof(myret_t));
    rvals->x = 1;
    rvals->y = 2;
    return (void *) rvals;
}

int main(int argc, char* argv[]) {
    pthread_t thread;
    myret_t *rvals;
    pthread_create(&thread,NULL,mythread,NULL);
    pthread_join(thread,(void**) &rvals);
    printf("%d %d\n",rvals->x,rvals->y);
    free(rvals);
    return 0;
}
/*
  argc is 1 + number of arguments passed
  argc refers to argument count and argv for argument vector
*/