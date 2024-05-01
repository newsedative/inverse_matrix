#ifndef FILLMET_H_
#define FILLMET_H_
#include "mainM.h";

void userInput(vector <vector <long double>>& mas, int size) {
    cout << "\n¬ведите " << size << " стpок по " << size << " чисел:\n";
    int Elem = 0;
    char Ch;
    while (Elem < size) {
        cout << Elem + 1 << ": ";
        int Row = 0;
        while (Row < size) {
            cin >> mas[Row][Elem];
            Row++;
        }
        do
            cin.get(Ch);
        while (Ch != '\n');
        Elem = Elem + 1;
    }
    cout << endl;
}

void randomInput(vector <vector <long double>>& mas, int size) {
    srand(time(0));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            mas[i][j] = rand() % 100;
        }
    }
}

void naturalInput(vector <vector <long double>>& mas, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            mas[i][j] = i * size + j + 1;
        }
    }
}
#endif