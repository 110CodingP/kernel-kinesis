#include <stdio.h>
#include <pthread.h>

void* mythread(void* arg) {
    printf("The thread just executed!\n");
    int a;
    return &a;
}
int main(int argc, char* argv[]) {
    pthread_t thread;
    int rc = pthread_create(&thread,NULL,mythread,NULL);
    pthread_join(thread,NULL);
    printf("%d\n",rc);
    return 0;
}