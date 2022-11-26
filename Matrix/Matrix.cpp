#include "Matrix.h"


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

Matrix::matrixData *Matrix::matrixData::detach() {
    if(refCount == 1) {
        return this;
        }
    matrixData *newMatrix = new matrixData(this -> rows, this -> columns);
    for(size_t i = 0; i < this -> rows; i++){
        copy(this -> matrix[i], this -> matrix[i] + this -> columns, newMatrix->matrix[i]);
        }
        this -> refCount--;
        return newMatrix;
    }

const double Matrix::read(size_t rows, size_t columns) const {
    return this -> data -> matrix[rows][columns];
    }

void Matrix::write(size_t rows, size_t columns, double num){
    this -> data = this -> data -> detach();
    this -> data -> matrix[rows][columns] = num;
    }
    
void MatrixRef::operator =(double num){
    return this -> matrix -> write(this -> rows, this -> columns, num);
    }

const double Matrix::operator()(size_t rows, size_t columns) const{
    return this -> read(rows-1, columns-1);
    }

MatrixRef Matrix::operator ()(size_t rows, size_t columns){
    return MatrixRef(this, rows, columns);
    }
    
MatrixRef::MatrixRef(Matrix* matrix, size_t rows, size_t columns){
        this -> matrix = matrix;
        this -> rows = rows;
        this -> columns = columns;
}

MatrixRef::operator double() const {
    return this -> matrix -> read(this -> rows, this -> columns);
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
