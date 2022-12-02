#pragma once
#include <iostream>

using namespace std;

class MatrixRef;
class InvalidIndexException {};

class Matrix {
  private:
	struct matrixData;
	matrixData* data;

	const double read(size_t rows, size_t columns) const;
	void write(size_t rows, size_t columns, double num);

  public:
	friend class MatrixRef;
	Matrix(size_t rows, size_t columns);
	Matrix(const Matrix& base);
	~Matrix();

	MatrixRef operator()(size_t rows, size_t columns);
	const double operator()(size_t rows, size_t columns) const;
    
    Matrix operator =(const Matrix& base);
    
    friend bool operator==(const Matrix& m1, const Matrix& m2);
    friend bool operator!=(const Matrix& m1, const Matrix& m2);
};

struct Matrix::matrixData {
	size_t refCount;
	size_t rows;
	size_t columns;
	double** matrix;

	matrixData(size_t rows, size_t columns);
	~matrixData();
	matrixData* detach();
};

class MatrixRef {
  private:
	Matrix* matrix;
	size_t rows;
	size_t columns;

  public:
	MatrixRef(Matrix* matrix, size_t rows, size_t columns);
	operator double() const;
	void operator=(double num);
};
