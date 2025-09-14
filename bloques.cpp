#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;

void multiplicarMatricesBloques(const vector<vector<double>>& A, const vector<vector<double>>& B, 
                               vector<vector<double>>& C, int n, int blockSize) {
    for (int ii = 0; ii < n; ii += blockSize) {
        for (int jj = 0; jj < n; jj += blockSize) {
            for (int kk = 0; kk < n; kk += blockSize) {
                for (int i = ii; i < min(ii + blockSize, n); i++) {
                    for (int j = jj; j < min(jj + blockSize, n); j++) {
                        double sum = 0;
                        for (int k = kk; k < min(kk + blockSize, n); k++) {
                            sum += A[i][k] * B[k][j];
                        }
                        C[i][j] += sum;
                    }
                }
            }
        }
    }
}

int main() {
    int n, blockSize;
    cout << "Ingrese tamaño de la matriz: ";
    cin >> n;
    cout << "Ingrese tamaño del bloque: ";
    cin >> blockSize;

    vector<vector<double>> A(n, vector<double>(n));
    vector<vector<double>> B(n, vector<double>(n));
    vector<vector<double>> C(n, vector<double>(n, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            A[i][j] = i + j;
            B[i][j] = i - j;
        }

    auto start = high_resolution_clock::now();
    multiplicarMatricesBloques(A, B, C, n, blockSize);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);

    cout << "Tiempo de ejecucion: " << duration.count() << " ms" << endl;
    return 0;
}
