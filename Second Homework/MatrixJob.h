#pragma once

int** initMatr(int rows, int cols);
void randomizeMatr(int** matr, int rows, int cols, int start = 10, int end = 99);
void deleteMatr(int** &matr, int rows);
void resizeMatr(int**& matr, int& rows, int& cols, int newRows, int newCols);
bool add(
	int** matr1, int rows1, int cols1,
	int** matr2, int rows2, int cols2,
	int**& matrRes, int& rowsRes, int& colsRes);
bool subtract(
	int** matr1, int rows1, int cols1,
	int** matr2, int rows2, int cols2,
	int**& matrRes, int& rowsRes, int& colsRes);
bool mult(
	int** matr1, int rows1, int cols1,
	int** matr2, int rows2, int cols2,
	int**& matrRes, int& rowsRes, int& colsRes);
bool div(
	int** matr1, int rows1, int cols1,
	int** matr2, int rows2, int cols2,
	int**& matrRes, int& rowsRes, int& colsRes);// check if the matrix is square
bool multN(
	int mult,
	int** matr, int rows, int cols,
	int**& matrRes, int& rowsRes, int& colsRes);// multiply number by a matrix
void transposeMatr(int**& matr, int& rows, int& cols);