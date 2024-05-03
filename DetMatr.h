#ifndef DETMATR_H_
#define DETMATR_H_
#include "mainM.h";
long double det_rec(vector <vector <long double>> mas, int size, int col) {
    if (size == 1)
        return mas[0][0];
    long double det = 0;
    int k = 1;
    long double m;
    vector <vector <long double>> matrix_temp(size - 1, vector<long double>(size - 1));

    for (int a = 0; a < size; ++a) {
        for (int i = 1; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                if (j < a) {
                    matrix_temp[i - 1][j] = mas[i][j];
                }
                else {
                    if (j > a)
                        matrix_temp[i - 1][j - 1] = mas[i][j];
                }
            }
        }

        m = mas[0][a] * k * det_rec(matrix_temp, size - 1, col);
        k = -k;
        det += m;
    }
    return det;
}
#endif
