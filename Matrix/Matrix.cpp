#include "Matrix.h"

Matrix::Matrix(size_t rows, size_t columns)
{
	this->data = new matrixData(rows, columns);
}

Matrix::matrixData::matrixData(size_t rows, size_t columns)
{
	this->rows = rows;
	this->columns = columns;
	this->matrix = new double*[rows];
	for (size_t i = 0; i < this->rows; i++) {
		this->matrix[i] = new double[columns]();
	}
	this->refCount = 1;
}
Matrix::Matrix(const Matrix& base)
{
	base.data->refCount++;
	this->data = base.data;
}

Matrix::Matrix(string fileName)
{
	ifstream file;
	size_t rows, columns;
	file.open(fileName);
	if (!file.good()) {
		throw new InvalidFileException();
	}
	if (!file.eof()) {
		file >> rows;
		file >> columns;
		if (file.fail() && !file.eof()) {
			file.close();
			throw InvalidFileException();
		}
	}
	this->data = new matrixData(rows, columns);

	for (size_t i = 1; i <= rows; i++) {
		for (size_t j = 1; j <= columns; j++) {
			if (file.eof()) {
				file.close();
				throw InvalidFileException();
			}
            file >> this -> data -> matrix[i][j];
            if (!file.eof() && file.fail()) {
			file.close();
			throw InvalidFileException();
		}
		}
	}
	file.close();
}

Matrix::matrixData* Matrix::matrixData::detach()
{
	if (refCount == 1) {
		return this;
	}
	matrixData* newMatrix = new matrixData(this->rows, this->columns);
	for (size_t i = 0; i < this->rows; i++) {
		copy(this->matrix[i], this->matrix[i] + this->columns,
			 newMatrix->matrix[i]);
	}
	this->refCount--;
	return newMatrix;
}

const double Matrix::read(size_t rowIndex, size_t columnIndex) const
{
	if (this->data->rows < rowIndex || this->data->columns < columnIndex ||
		rowIndex < 0 || columnIndex < 0) {
		throw new InvalidMatrixSizeException;
	}
	return this->data->matrix[rowIndex][columnIndex];
}

void Matrix::write(size_t rowIndex, size_t columnIndex, double num)
{
	if (this->data->rows < rowIndex || this->data->columns < columnIndex ||
		rowIndex < 0 || columnIndex < 0) {
		throw new InvalidMatrixSizeException;
	}
	this->data = this->data->detach();
	this->data->matrix[rowIndex][columnIndex] = num;
}

void MatrixRef::operator=(double num)
{
	return this->matrix->write(this->rows, this->columns, num);
}

const double Matrix::operator()(size_t rows, size_t columns) const
{
	return this->read(rows - 1, columns - 1);
}

MatrixRef Matrix::operator()(size_t rows, size_t columns)
{
	return MatrixRef(this, rows - 1, columns - 1);
}

MatrixRef::MatrixRef(Matrix* matrix, size_t rows, size_t columns)
{
	this->matrix = matrix;
	this->rows = rows;
	this->columns = columns;
}

MatrixRef::operator double() const
{
	return this->matrix->read(this->rows, this->columns);
}

Matrix::~Matrix()
{
	if (--this->data->refCount == 0) {
		delete this->data;
	}
}
Matrix::matrixData::~matrixData()
{
	for (size_t i = 0; i < this->rows; i++) {
		delete[] this->matrix[i];
	}
	delete[] this->matrix;
}

bool operator==(const Matrix& m1, const Matrix& m2)
{
	if (m1.data->columns != m2.data->columns ||
		m1.data->rows != m2.data->rows) {
		return false;
	}
	for (size_t i = 1; i <= m1.data->rows; i++) {
		for (size_t j = 1; j <= m1.data->columns; j++) {
			if (m1(i, j) != m2(i, j)) {
				return false;
			}
		}
	}
	return true;
}

bool operator!=(const Matrix& m1, const Matrix& m2)
{
	return !(m1 == m2);
}

Matrix Matrix::operator=(const Matrix& base)
{
	if (this != &base) {
		++base.data->refCount;
		if (--data->refCount == 0) {
			delete data;
		}
		data = base.data;
	}
	return *this;
}

ostream& operator<<(ostream& out, const Matrix& m)
{
	for (size_t i = 1; i <= m.data->rows; i++) {
		for (size_t j = 1; j <= m.data->columns; j++) {
			out << m(i, j);
			out << "  ";
		}
		out << "\n";
	}
	return out;
}

Matrix& Matrix::operator+=(const Matrix& m)
{
	if (this->data->columns != m.data->columns ||
		this->data->rows != m.data->rows) {
		throw new InvalidMatrixSizeException();
	}
	for (size_t i = 1; i <= this->data->rows; i++) {
		for (size_t j = 1; j <= this->data->columns; j++) {
			this->data->matrix[i - 1][j - 1] += m(i, j);
		}
	}
	return *this;
}

Matrix& Matrix::operator-=(const Matrix& m)
{
	if (this->data->columns != m.data->columns ||
		this->data->rows != m.data->rows) {
		throw new InvalidMatrixSizeException();
	}
	for (size_t i = 1; i <= this->data->rows; i++) {
		for (size_t j = 1; j <= this->data->columns; j++) {
			this->data->matrix[i - 1][j - 1] -= m(i, j);
		}
	}
	return *this;
}
/*
Matrix& Matrix::operator*=(const Matrix& m){
	if (this -> data -> columns != m.data->rows){
		throw new InvalidMatrixSizeException();
		}
	for (size_t i = 1; i <= this->data->rows; i++) {
		for (size_t j = 1; j <= this->data->columns; j++) {
			this -> data -> matrix[i-1][j-1] -= m(i, j);
		}
	}
	return *this;
	}
	* */

Matrix operator+(const Matrix& m1, const Matrix& m2)
{
	if (m1.data->columns != m2.data->columns ||
		m1.data->rows != m2.data->rows) {
		throw new InvalidMatrixSizeException();
	}
	Matrix result(m1.data->columns, m1.data->rows);
	for (size_t i = 1; i <= m1.data->rows; i++) {
		for (size_t j = 1; j <= m1.data->columns; j++) {
			result(i, j) = m1(i, j) + m2(i, j);
		}
	}
	return result;
}

Matrix operator-(const Matrix& m1, const Matrix& m2)
{
	if (m1.data->columns != m2.data->columns ||
		m1.data->rows != m2.data->rows) {
		throw new InvalidMatrixSizeException();
	}
	Matrix result(m1.data->columns, m1.data->rows);
	for (size_t i = 1; i <= m1.data->rows; i++) {
		for (size_t j = 1; j <= m1.data->columns; j++) {
			result(i, j) = m1(i, j) - m2(i, j);
		}
	}
	return result;
}
