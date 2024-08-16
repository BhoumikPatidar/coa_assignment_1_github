#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

long long fib(int n){
    if (n<=1) return n;
    return fib(n-1)+fib(n-2);
}

int main(){
    struct timespec start,end;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&start);
    for (int i=0;i<50;i++){
        cout<<fib(i)<<endl;
    }
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&end);
    long long sec_time=(end.tv_sec-start.tv_sec);
    long long nsec_time=(end.tv_nsec-start.tv_nsec)/1e9;
    double time_taken=sec_time+nsec_time;
    cout<<"Time taken: "<<time_taken<<" seconds";
    return 0;
}