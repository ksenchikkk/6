#include <iostream>
#include <cstdlib> // для функций rand() и srand()
#include <ctime>
#include <windows.h>
#include <limits> // для функции time()

// Функция для генерации случайного числа в диапазоне от min до max
int generateRandomNumber(int min, int max) {
    return min + rand() % (max - min + 1);
}
using namespace std;
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    int N;
    cout << "Введите число N: ";
    cin >> N;
    while (N <= 0) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Пожалуйста, введите положительное число: ";
        cin >> N;
    }
    
    // Инициализация генератора случайных чисел
    srand(time(0));
    
    // Создание динамического двумерного массива
    int** matrix = new int*[N];
    for (int i = 0; i < N; i++) {
        matrix[i] = new int[N];
    }
    
    // Заполнение матрицы случайными числами
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = generateRandomNumber(1, 100);
        }
    }
    
    // Вывод исходной матрицы
    cout << "Исходная матрица:" << std::endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    // Перестановка столбцов
    for (int i = 0; i < N / 2; i++) {
        for (int j = 0; j < N; j++) {
            int temp = matrix[j][i];
            matrix[j][i] = matrix[j][N - i - 1];
            matrix[j][N - i - 1] = temp;
        }
    }
    
    // Вывод измененной матрицы
    cout << "Измененная матрица:" << std::endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << " ";
        }
            cout << std::endl;
    }
    
    // Освобождение памяти
    for (int i = 0; i < N; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    
    return 0;
}
