#pragma once
#ifndef MATRICES_H
#define MATRICES_H

struct Matrix {

	int rows;
	int columns;
	double** matrix;

	Matrix(const int rows, const int columns) {
		this->rows = rows;
		this->columns = columns;

		matrix = new double* [rows];
		for (int i = 0; i < rows; i++) {
			matrix[i] = new double[columns];
		}

	}

	~Matrix() {
		for (int i = 0; i < rows; i++) {
			delete[] matrix[i];
		}

		delete[] matrix;

	}

	void print() {
		for (int i = 0; i < this->rows; i++) {
			for (int j = 0; j < this->columns; j++) {
				std::cout << this->matrix[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
};

#endif 

