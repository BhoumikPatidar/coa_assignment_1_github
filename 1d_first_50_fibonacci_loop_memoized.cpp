#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<long long>first_50_fibonacci(50);
    struct timespec start,end;
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&start);
    first_50_fibonacci[0]=0;
    first_50_fibonacci[1]=1;
    for (int i=2;i<50;i++){
        first_50_fibonacci[i]=first_50_fibonacci[i-1]+first_50_fibonacci[i-2];
    }
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID,&end);
    double time_taken=(end.tv_sec-start.tv_sec)+(end.tv_nsec-start.tv_nsec)/1e9;
    cout<<"Time taken: "<<time_taken<<" seconds";
    return 0;
}