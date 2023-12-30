#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <windows.h>
#include <limits> 

int generateRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    int N;
    cout << "Введите число: ";
    cin >> N;
    while (N <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Число должно быть положительным: ";
        cin >> N;
    }
    
    srand(time(0));
    int** matrix = new int*[N];
    for (int i = 0; i < N; i++) {
        matrix[i] = new int[N];
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = generateRandomNumber(1, 100);
        }
    }

    cout << "Исходная матрица:" << std::endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < N / 2; i++) {
        for (int j = 0; j < N; j++) {
            int temp = matrix[j][i];
            matrix[j][i] = matrix[j][N - i - 1];
            matrix[j][N - i - 1] = temp;
        }
    }

    cout << "Измененная матрица:" << std::endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
            cout << std::endl;
    }

    for (int i = 0; i < N; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    
    return 0;
}
