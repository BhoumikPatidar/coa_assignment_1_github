#include <iostream>
#include <vector>
#include <ctime>
using namespace std;


long long fib(int n){
    if (n==1){
        return 0;
    }
    if (n==2){
        return 1;
    }
    long long fib1=0;
    long long fib2=1;
    for (int i=3;i<=n;i++){
        long long temp=fib2;
        fib2=fib1+fib2;
        fib1=temp;
    }
    return fib2;
}

int main(){
    struct timespec start,end;

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&start);
    for (int i=0;i<50;i++){
        cout<<fib(i+1)<<endl;
    }
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&end);
    long long sec_time=(end.tv_sec-start.tv_sec);
    long long nsec_time=(end.tv_nsec-start.tv_nsec);
    double time_taken=sec_time+nsec_time*1e-9;
    cout<<"Time taken: "<<time_taken<<" seconds";
    return 0;
}

