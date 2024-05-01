#ifndef MULT_H_
#define MULT_H_
#include "mainM.h";
vector<vector<long double>> matrix_multiply(vector <vector <long double>>& a, vector <vector <long double>>& b) {
    if (a.empty() || b.empty()) {
        throw invalid_argument("Матрицы пустые");
    }
    if (a[0].size() != b.size()) {
        throw invalid_argument("Матрицы не могут бть умножены");
    }

    vector<vector<long double>> c(a.size(), vector<long double>(b[0].size(), 0));

    for (size_t i = 0; i < a.size(); ++i) {
        for (size_t j = 0; j < b[0].size(); ++j) {
            for (size_t k = 0; k < a[0].size(); ++k) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return c;
}

#endif
