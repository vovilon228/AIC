#pragma once
#ifndef FUNCTIONALITY_MATRICES_H
#define FUNCTIONALITY_MATRICES_H

#include "Matrices.h";

Matrix* create_matrix_random_double(const int& a, const int& b) {
	Matrix* matrix = new Matrix(a, b);

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			matrix->matrix[i][j] = 10.0 + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (-10 - 10)));
		}
	}
	return matrix;
}

Matrix* create_matrix_random(const int& a, const int& b) {
	Matrix* matrix = new Matrix(a, b);

	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			matrix->matrix[i][j] = -10 + (rand() % 21);
		}
	}
	return matrix;
}

bool compare_matrices(Matrix* matrix1, Matrix* matrix2) {

	if (matrix1->rows != matrix2->rows || matrix1->columns != matrix2->columns)
		return false;

	for (int i = 0; i < matrix1->rows; i++) {
		for (int j = 0; j < matrix1->columns; j++) {
			if (abs(matrix1->matrix[i][j] - matrix2->matrix[i][j])>0.01)
				return false;
		}
	}

	return true;
}


bool check_matrices_for_multiply(Matrix* matrix1, Matrix* matrix2) {
	if ((matrix1->columns == matrix2->rows)&&(matrix1->rows>0)&&(matrix2->columns>0))
		return true;
	else
		return false;
}

Matrix* matrix_addition(Matrix* matrix1, Matrix* matrix2) {

	Matrix* matrix = new Matrix(matrix1->rows, matrix1->columns);

	for (int i = 0; i < matrix->rows; i++) {
		for (int j = 0; j < matrix->columns; j++) {
			matrix->matrix[i][j] = matrix1->matrix[i][j] + matrix2->matrix[i][j];
		}
	}

	return matrix;

}

Matrix* matrix_subtraction(Matrix* matrix1, Matrix* matrix2) {


	Matrix* matrix = new Matrix(matrix1->rows, matrix1->columns);

	for (int i = 0; i < matrix->rows; i++) {
		for (int j = 0; j < matrix->columns; j++) {
			matrix->matrix[i][j] = matrix1->matrix[i][j] - matrix2->matrix[i][j];
		}
	}

	return matrix;

}

Matrix* matrix_multiply(Matrix* matrix1, Matrix* matrix2) {

	const int n = matrix1->columns;

	Matrix* matrix = new Matrix(matrix1->rows, matrix2->columns);

	for (int i = 0; i < matrix1->rows; i++) {
		for (int j = 0; j < matrix2->columns; j++) {
			matrix->matrix[i][j] = 0;
		}
	}

	for (int k = 0; k < matrix1->rows; k++) {
		for (int i = 0; i < matrix2->columns; i++) {
			for (int j = 0; j < n; j++) {
				matrix->matrix[k][i] += matrix1->matrix[k][j] * matrix2->matrix[j][i];
			}
		}
	}

	return matrix;

}


#endif 
