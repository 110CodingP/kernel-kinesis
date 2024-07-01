#include <iostream>
#include <time.h>
using namespace std;

int main() {
   clock_t tStart = clock();
   unsigned long long sum = 0;
   for (long long i=1;i<1LL<<36;i++) sum = (sum+i)%(1LL<<36);
   cout<<sum<<'\n';
   printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
   return 0;
}