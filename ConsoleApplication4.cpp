#include "mainM.h";
#include "PrintMatrix.h";
#include "FillMet.h";
#include "InverseMatr.h";
#include "Mult.h";

int main() {
    setlocale(0, "");
    const int max_size = 10;
    int N;

    cout << "Введите размер массива: ";
    while (!(cin >> N)) {
        cout << "Неверный формат. Введите число: ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    if (N > max_size) {
        N = max_size;
    }

    vector <vector <long double>> matrix(N, vector<long double>(N));

    cout << "\nВыберите вариант ввода матрицы: вручную (1), генератором случайных вещественных чисел (2), натуральным рядом чисел (3): ";
    int var_of_gener;
    while (!(cin >> var_of_gener)) {
        cout << "\nНеверный формат. Введите число: ";
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    if (var_of_gener == 1) {
        userInput(matrix, N);
    }
    else if (var_of_gener == 2) {
        randomInput(matrix, N);
    }
    else if (var_of_gener == 3) {
        naturalInput(matrix, N);
    }

    printMatrix(matrix, N);

    vector <vector <long double>> inverted_matrix(N, vector<long double>(N));
    inverse_matrix(matrix, N, inverted_matrix);

    cout << "\nОбратная матрица:\n";
    printMatrix(inverted_matrix, N);

    cout << "\nРезультат умнжения исходной на обратную:\n";
    vector<vector<long double>> multipl_m = matrix_multiply(matrix, inverted_matrix);
    printMatrix(multipl_m, N);

    cout << "\nРезультат умнжения обратной на исходную:\n";
    vector<vector<long double>> multipl_m1 = matrix_multiply(inverted_matrix, matrix);
    printMatrix(multipl_m1, N);


    return 0;
}


