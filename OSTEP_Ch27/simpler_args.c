#include <stdio.h>
#include <pthread.h>

void *mythread(void* arg) {
    long long int a = (long long int) arg;
    return (void *) a + 1;
}

int main(int argc, char* argv[]) {
    pthread_t thread;
    long long int a = 1;
    pthread_create(&thread,NULL,mythread,(void*)100);
    pthread_join(thread,(void **)&a);
    printf("%lld\n",a);
    return 0;
}

/*
  long long int is used instead of int because of size, pointer is 8 byte so is long long int but int is
  4 byte
*/