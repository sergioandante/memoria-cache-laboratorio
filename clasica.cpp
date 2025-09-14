#include <iostream>
#include <vector>
#include <chrono>
using namespace std;
using namespace std::chrono;
// Función para multiplicar matrices clásicamente
void multiplicarMatrices(const vector<vector<double>>& A, const vector<vector<double>>& B, vector<vector<double>>& C, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int n; // Tamaño de la matriz (n x n)
    cout << "Ingrese el tamaño de la matriz: ";
    cin >> n;

    vector<vector<double>> A(n, vector<double>(n));
    vector<vector<double>> B(n, vector<double>(n));
    vector<vector<double>> C(n, vector<double>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            A[i][j] = i + j;
            B[i][j] = i - j;
        }

    auto inicio = high_resolution_clock::now();
    multiplicarMatrices(A, B, C, n);
    auto fin = high_resolution_clock::now();
    auto duracion = duration_cast<milliseconds>(fin - inicio);

    cout << "Tiempo de ejecución para matriz " << n << "x" << n << ": " << duracion.count() << " ms" << endl;
    return 0;
}
