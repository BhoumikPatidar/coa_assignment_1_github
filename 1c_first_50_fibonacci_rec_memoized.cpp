#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

long long fib(int n,vector<long long>&first_50_fibonacci){
    if (n==0) return first_50_fibonacci[n]= 0;
    if (n==1) return first_50_fibonacci[n]= 1;
    if (first_50_fibonacci[n]!=-1){
        return first_50_fibonacci[n];
    }
    return first_50_fibonacci[n]=fib(n-1,first_50_fibonacci)+fib(n-2,first_50_fibonacci);
}

int main(){
    vector<long long>first_50_fibonacci(50,-1);
    struct timespec start,end;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&start);
    fib(49,first_50_fibonacci);
    for (auto it:first_50_fibonacci){
        cout<<it<<endl;
    }
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&end);
    double time_taken=(end.tv_sec-start.tv_sec)+(end.tv_nsec-start.tv_nsec)/1e9;
    cout<<"Time taken: "<<time_taken<<" seconds";
    return 0;
}