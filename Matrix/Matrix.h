#pragma once
#include <iostream>
#include <fstream>

using namespace std;

class MatrixRef;
class InvalidIndexException {};
class InvalidMatrixSizeException{};
class InvalidFileException {};
class InvalidFileNameException {};

class Matrix {
  private:
	struct matrixData;
	matrixData* data;

	const double read(size_t rows, size_t columns) const;
	void write(size_t rows, size_t columns, double num);
    
    static Matrix multiplyMatrixByConst(const Matrix &m, double value);
    static Matrix multiplyMatrixByMatrix(const Matrix &m1, const Matrix &m2);
  public:
	friend class MatrixRef;
    Matrix(double num);
	Matrix(size_t rows, size_t columns);
	Matrix(const Matrix& base);
    Matrix(string filename);
	~Matrix();
    
	MatrixRef operator()(size_t rowIndex, size_t columnIndex);
	const double operator()(size_t rowIndex, size_t columnIndex) const;
    
    Matrix operator =(const Matrix& base);
    
    friend bool operator==(const Matrix& m1, const Matrix& m2);
    friend bool operator!=(const Matrix& m1, const Matrix& m2);
    
    friend ostream& operator <<(ostream& out, const Matrix& m);
    
    Matrix& operator+=(const Matrix& m);
    Matrix& operator-=(const Matrix& m);
    Matrix& operator*=(const Matrix& m);
   
   friend Matrix operator+(const Matrix& m1, const Matrix& m2);
   friend Matrix operator-(const Matrix& m1, const Matrix& m2);
   friend Matrix operator*(const Matrix &m1, const Matrix &m2);
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
