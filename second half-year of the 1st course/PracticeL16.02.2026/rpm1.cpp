#include <bits/stdc++.h>
using namespace std;

double **readMatrix(fstream &file, int &rows, int &colms) {
    file >> rows >> colms;
    double **matrix = new double*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new double[colms];
        for (int j = 0; j < colms; j++) {
            file >> matrix[i][j];
        }
    }
    return matrix;
}

int main() {
    int rows, colms;
    fstream in("input.txt"), out("out.txt");
    double **matrix = readMatrix(in, rows, colms);
    in.close();

    double* matrixSearch = new double[colms];
    bool* matrixSearchb = new bool[colms];
    int cand_count = 0;

    for (int j = 0; j < colms; j++) {
        double val = matrix[0][j];
        bool already = false;
        for (int k = 0; k < cand_count; k++) {
            if (matrixSearch[k] == val) {
                already = true;
                break;
            }
        }
        if (!already) {
            matrixSearch[cand_count] = val;
            matrixSearchb[cand_count] = true;
            cand_count++;
        }
    }

    for (int i = 1; i < rows; i++) {
        for (int k = 0; k < cand_count; k++) {
            if (!matrixSearchb[k]) continue;

            bool found = false;
            for (int j = 0; j < colms; j++) {
                if (matrix[i][j] == matrixSearch[k]) {
                    found = true;
                    break;
                }
            }
            if (!found) matrixSearchb[k] = false;
        }
    }

    for (int k = 0; k < cand_count; k++) {
        if (matrixSearchb[k]) {
            out << matrixSearch[k] << ' ';
        }
    }

    delete[] matrixSearch;
    delete[] matrixSearchb;
    for (int i = 0; i < rows; i++) delete[] matrix[i];
    delete[] matrix;

    out.close();
    return 0;
}

/*
Лучше перебор каждого элемента с флагом
Задача: Найти элемент(ы), которые есть в каждой строке матрицы
Самое простое решение: пройтись по каждому элементу первой строки,
сравнивая элемент в первой строке с элементами во второй, третьей и т.д. строк, 
храня при этом флаг -- если элемента нет в строке то f = 0, в конце цикла проверок если остался true, 
то выводим элемент первой строки и переходим на следующий и т.д. пока не кончаться элементы из первой строки
*/