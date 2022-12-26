#pragma once
#ifndef REVERSEDMATRIX_MINORS_H
#define REVERSEDMATRIX_MINORS_H
#include <iostream>
#include <cmath>

#include "Matrices.h"
#include "Functionality_matrices.h"




double matrix_det(Matrix* matrix, int n) {
    if (n == 1)
        return matrix->matrix[0][0];
    else if (n == 2)
        return matrix->matrix[0][0] * matrix->matrix[1][1] - matrix->matrix[0][1] * matrix->matrix[1][0];
    else {
        double d = 0;
        for (int k = 0; k < n; k++) {
            Matrix* m = new Matrix(n - 1, n - 1);
            for (int i = 1; i < n; i++) {
                int t = 0;
                for (int j = 0; j < n; j++) {
                    if (j == k)
                        continue;
                    m->matrix[i - 1][t] = matrix->matrix[i][j];
                    t++;
                }
            }
            d += pow(-1, k + 2) * matrix->matrix[0][k] * matrix_det(m, n - 1);
            delete m;
        }
        return d;
    }
}

Matrix* transpose(Matrix* matrix, const int& n) {
    Matrix* res = new Matrix(n, n);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            res->matrix[i][j] = matrix->matrix[j][i];
        }
    }
    return res;
}



Matrix* get_minor(Matrix* matrix, int x, int y, int size)
{
    int xCount = 0, yCount = 0;
    int i, j;
    Matrix* minor = new Matrix(size - 1, size - 1);


    for (i = 0; i < size; i++) {
        if (i != x) {
            yCount = 0;
            for (j = 0; j < size; j++) {
                if (j != y) {
                    minor->matrix[xCount][yCount] = matrix->matrix[i][j];
                    yCount++;
                }
            }
            xCount++;
        }
    }
    return minor;
}

Matrix* matrix_minor(Matrix* matrix, int size)
{
    int i, j;

    double det = matrix_det(matrix, size);

    Matrix* result = new Matrix(size, size);

    if (det > 0)
        det = -1;
    else
        det = 1;

    for (j = 0; j < size; j++) {
        for (i = 0; i < size; i++) {
            Matrix* minor = get_minor(matrix, j, i, size);
            if ((i + j) % 2 == 0)
                result->matrix[j][i] = -det * matrix_det(minor, size - 1);
            else
                result->matrix[j][i] = det * matrix_det(minor, size - 1);
            delete minor;
        }
    }
    return result;
}

Matrix* reverse_matrix(Matrix* matrix, const int& n) {
    Matrix* result = new Matrix(n, n);

    double det = matrix_det(matrix, n);
    Matrix* minor = matrix_minor(matrix, n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result->matrix[i][j] = minor->matrix[i][j] / det;
        }
    }
    delete minor;
    return transpose(result, n);
}

#endif