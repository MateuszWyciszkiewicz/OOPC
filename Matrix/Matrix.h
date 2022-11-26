#pragma once
#include <iostream>

using namespace std;

class InvalidIndexException {};

class Matrix {
  private:
    struct matrixData;
	matrixData *data;

  public:
	size_t index(size_t, size_t) const;
    Matrix(size_t rows, size_t columns);
    Matrix(const Matrix& base);
    ~Matrix();
};

struct Matrix::matrixData{
    size_t refCount;
	size_t rows;
	size_t columns;
	double** matrix;
    
    matrixData(size_t rwos, size_t columns);
    ~matrixData();
    };

class MatrixRef {
    private:
        Matrix* matrix;
        size_t rows;
        size_t columns;
    public:
        MatrixRef(Matrix* matrix, size_t rows, size_t columns);
        operator double() const;
        void operator=(double);
    };
