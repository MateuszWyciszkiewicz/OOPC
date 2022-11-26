#include "Matrix.h"

/*
size_t Matrix::index(size_t column, size_t row) {
	if(column >= this -> columns || row >= this -> rwos || rows < 0 || column <
0){ throw InvalidIndexException();
		}
		return
	}

*/
Matrix::Matrix(size_t rows, size_t columns)
{
	this->data = new matrixData(rows, columns);
}

Matrix::matrixData::matrixData(size_t rows, size_t columns)
{
	this->rows = rows;
	this->columns = columns;
	this->matrix = (double**)malloc(this->rows * sizeof(double*));
	if (this->matrix == NULL) {
		abort();
	}
	for (size_t i = 0; i < this->rows; i++) {
		this->matrix[i] = (double*)malloc(this->columns * sizeof(double));
		if (this->matrix[i] == NULL) {
			abort();
		}
	}
	this->refCount = 1;
}
Matrix::Matrix(const Matrix& base)
{
	base.data->refCount++;
	this->data = base.data;
}

Matrix::~Matrix()
{
	if (--this->data->refCount == 0) {
        delete this -> data;
	}
}
Matrix::matrixData::~matrixData()
{
	for (size_t i = 0; i < this->rows; i++) {
		free(this->matrix[i]);
	}
	free(this->matrix);
}
