#include <sys/time.h>
#include <iostream>
using namespace std;
int main() {
    timeval tv;
    timezone tz;
    gettimeofday(&tv,&tz);
    cout<<tv.tv_sec<<endl;
    return 0;
}