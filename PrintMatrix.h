#ifndef PRINTMATRIX_H_
#define PRINTMATRIX_H_
#include "mainM.h";

void printMatrix(vector <vector <long double>>& mas, int size, int numCols = -1);
void printMatrix(vector <vector <long double>>& mas, int size, int numCols) {
    cout << "\nВывод матрицы:\n";
    int Elem;
    char Ch;
    // Определить количество столбцов, если не указано
    if (numCols == -1) {
        numCols = mas[0].size();
    }
    // Вывести заголовки столбцов
    for (Elem = 1; Elem <= numCols; Elem++)
        cout << setw(14) << Elem;
    cout << endl;

    int Row = 0;
    do {
        cout << Row + 1 << ":";
        Elem = 0;
        do {
            if (mas[Row][Elem] > 0.000000001) {
                cout << setw(14) << mas[Row][Elem];
            }
            else {
                cout << setw(14) << "0";
            }
            Elem++;
        } while (Elem < numCols);
        cout << endl;
        Row++;
    } while (Row < size);

    cin.get(Ch);
}

#endif