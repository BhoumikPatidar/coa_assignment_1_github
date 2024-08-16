#include <iostream>
#include <vector>
#include <ctime>
#include <iomanip>

using namespace std;

void multiplyMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void multiplyMatrices(const vector<vector<double>>& A, const vector<vector<double>>& B, vector<vector<double>>& C, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0.0;
            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void calculateAndPrintTime(const struct timespec& start, const struct timespec& end, const string& label) {
    double time_taken = (end.tv_sec - start.tv_sec) * 1e9;
    time_taken = (time_taken + (end.tv_nsec - start.tv_nsec)) * 1e-9;
    cout << label << fixed << time_taken << setprecision(9) << " seconds" << endl;
}

int main() {
    int sizes[] = {64, 128, 256, 512, 1024};
    
    for (int N : sizes) {
        struct timespec sys_start, sys_end, cpu_start, cpu_end;

        clock_gettime(CLOCK_MONOTONIC, &sys_start);
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &cpu_start);

        vector<vector<int>> A(N, vector<int>(N, 1));
        vector<vector<int>> B(N, vector<int>(N, 1));
        vector<vector<int>> C(N, vector<int>(N, 0));

        
        struct timespec mult_start, mult_end;
        clock_gettime(CLOCK_MONOTONIC, &mult_start);

        multiplyMatrices(A, B, C, N);

        clock_gettime(CLOCK_MONOTONIC, &mult_end);

        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &cpu_end);
        clock_gettime(CLOCK_MONOTONIC, &sys_end);

        cout << "N=" << N << ", Integer Matrix Multiplication: " << endl;
        calculateAndPrintTime(sys_start, sys_end, "Total System Time: ");
        calculateAndPrintTime(cpu_start, cpu_end, "Total CPU Time: ");
        calculateAndPrintTime(mult_start, mult_end, "Matrix Multiplication Time: ");
        
        clock_gettime(CLOCK_MONOTONIC, &sys_start);
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &cpu_start);

        vector<vector<double>> A_d(N, vector<double>(N, 1.0));
        vector<vector<double>> B_d(N, vector<double>(N, 1.0));
        vector<vector<double>> C_d(N, vector<double>(N, 0.0));



        clock_gettime(CLOCK_MONOTONIC, &mult_start);

        multiplyMatrices(A_d, B_d, C_d, N);

        clock_gettime(CLOCK_MONOTONIC, &mult_end);

        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &cpu_end);
        clock_gettime(CLOCK_MONOTONIC, &sys_end);

        cout << "N=" << N << ", Double Matrix Multiplication: " << endl;
        calculateAndPrintTime(sys_start, sys_end, "Total System Time: ");
        calculateAndPrintTime(cpu_start, cpu_end, "Total CPU Time: ");
        calculateAndPrintTime(mult_start, mult_end, "Matrix Multiplication Time: ");
    }

    return 0;
}
