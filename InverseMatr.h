#ifndef INVERSEMATR_H_
#define INVERSEMATR_H_
#include "mainM.h";
#include "PrintMatrix.h";

void inverse_matrix(vector <vector <long double>>& mas, int size, vector <vector <long double>>& out) {
    vector <vector <long double>> extended_matrix(size * 2, vector<long double>(size * 2));
    vector <vector <long double>> single_matrix(size, vector<long double>(size));

    //���������� ��������� �������
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) single_matrix[i][j] = 1;
            else single_matrix[i][j] = 0;
        }
    }

    //���������� ������������� �������
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            extended_matrix[i][j] = mas[i][j];
            extended_matrix[i][j + size] = single_matrix[i][j];
            long double num = extended_matrix[i][j + size];
        }
    }
    cout << "\n����������� �������:\n";
    printMatrix(extended_matrix, size, size * 2);


    //������ ��� ��������� ���� ������� ��������� �������
    for (int k = 0; k < size; k++) {
        double cf = extended_matrix[k][k];
        for (int i = 0; i < size * 2; i++) {
            extended_matrix[k][i] = extended_matrix[k][i] / cf;
        }
        for (int i = k + 1; i < size; i++) {
            double Kf = extended_matrix[i][k] / extended_matrix[k][k];
            for (int j = 0; j < size * 2; j++) {
                extended_matrix[i][j] = extended_matrix[i][j] - Kf * extended_matrix[k][j];
            }
        }
    }

    //printMatrix(extended_matrix, size, size * 2);

    //�������� ��� (��������� �������� ������� ����)
    for (int k = size - 1; k > -1; k--) //k-����� ������
    {
        for (int i = 2 * size - 1; i > -1 and extended_matrix[k][i] != -0; i--) //i-����� �������
            extended_matrix[k][i] = extended_matrix[k][i] / extended_matrix[k][k];
        for (int i = k - 1; i > -1; i--) //i-����� ��������� ������ ����� k
        {
            double Kf = extended_matrix[i][k] / extended_matrix[k][k];
            for (int j = 2 * size - 1; j > -1; j--) //j-����� ������� ��������� ������ ����� k
                extended_matrix[i][j] = extended_matrix[i][j] - extended_matrix[k][j] * Kf;
        }
    }

    //printMatrix(extended_matrix, size, size * 2);
    cout << "\n����������� �������:\n";
    printMatrix(extended_matrix, size, size * 2);

    //�������� �� ����� �������
    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            out[i][j] = extended_matrix[i][j + size];
}
#endif