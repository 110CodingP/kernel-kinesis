#include <stdio.h>
#include <pthread.h>

typedef struct {
    int a;
    int b;
} myarg_t;

void* mythread(void* arg) {
    myarg_t *args = (myarg_t *) arg;
    printf("%d %d\n",args->a,args->b);
    return NULL;
}

int main() {
    pthread_t thread;
    myarg_t args={10,20};
    int rc = pthread_create(&thread,NULL,mythread,&args);
    // rc is 0 if thread was created successfully otherwise there is an error
    pthread_join(thread,NULL);
    return 0;
}