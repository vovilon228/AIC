﻿#include <iostream>
#include <cmath>

using namespace std;

int Gauss(double** matrica_a, int n, double* massiv_b, double* x)
{
    int i, j, k, r;
    double c, M, max, s, ** a, * b; a = new double* [n];
    for (i = 0; i < n; i++) a[i] = new double[n];
    b = new double[n]; for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) a[i][j] = matrica_a[i][j];
    for (i = 0; i < n; i++) b[i] = massiv_b[i];
    for (k = 0; k < n; k++) {
        max = fabs(a[k][k]);
        r = k;
        for (i = k + 1; i < n; i++)
            if (fabs(a[i][k]) > max) {
                max = fabs(a[i][k]);
                r = i;
            }
        for (j = 0; j < n; j++) {
            c = a[k][j];
            a[k][j] = a[r][j];
            a[r][j] = c;
        }
        c = b[k]; b[k] = b[r]; b[r] = c; for (i = k + 1; i < n; i++) {
            for (M = a[i][k] / a[k][k], j = k; j < n; j++)
                a[i][j] -= M * a[k][j]; b[i] -= M * b[k];
        }

    }
    if (a[n - 1][n - 1] == 0) if (b[n - 1] == 0)return-1; else return-2;
    else {
        for (i = n - 1; i >= 0; i--) {
            for (s = 0, j = i + 1; j < n; j++)
                s += a[i][j] * x[j]; x[i] = (b[i] - s) / a[i][i];
        }return 0;
    } for (i = 0; i < n; i++) delete[] a[i]; delete[] a;
    delete[] b;

}

int INVERSE(double** a, int n, double** y) {
    int i, j, res; double* b, * x; b = new double[n]; x = new double[n]; for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            if (j == i)   b[j] = 1; else b[j] = 0;
        res = Gauss(a, n, b, x);
        if (res != 0) break;
        else for (j = 0; j < n; j++) {
            y[j][i] = x[j];
        }
    }
    delete[] x;
    delete[] b;
    if (res != 0) return -1;
    else return 0;
}

double determinant(double** matrica_a, int n) {
    int i, j, k, r; double c, M, max, det = 1, ** a; a = new double* [n];
    for (i = 0; i < n; i++) a[i] = new double[n]; for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) a[i][j] = matrica_a[i][j];
    for (k = 0; k < n; k++) {
        max = fabs(a[k][k]); r = k;
        for (i = k + 1; i < n; i++)
            if (fabs(a[i][k]) > max)
            {
                max = fabs(a[i][k]);  r = i;
            }
        if (r != k) det = -det;
        for (j = 0; j < n; j++) {
            c = a[k][j]; a[k][j] = a[r][j]; a[r][j] = c;
        }

        for (i = k + 1; i < n; i++)
            for (M = a[i][k] / a[k][k], j = k; j < n; j++)
                a[i][j] -= M * a[k][j];

    }
    for (i = 0; i < n; i++)
        det *= a[i][i];
    return det;

}


int main()
{

    int result, i, j, N; double** a, ** b; cout << "The size of the matrix= "; cin >> N; if (N < 0) { N *= -1; } a = new double* [N]; for (i = 0; i < N; i++)
        a[i] = new double[N]; b = new double* [N]; for (i = 0; i < N; i++)
        b[i] = new double[N]; cout << "Input Matrix: " << endl; for (i = 0; i < N; i++)
        for (j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    result = INVERSE(a, N, b); if (result == 0)
    {
        cout << "Inverse matrix: " << endl; for (i = 0; i < N; cout << endl, i++)
            for (j = 0; j < N; j++)
                cout << b[i][j] << "\t";
    }
    else  cout << "No Inverse matrix" << endl; for (i = 0; i < N; i++)

    cout << "determinant: " << determinant(a, N) << endl;

    system("pause");
    return 0;
}