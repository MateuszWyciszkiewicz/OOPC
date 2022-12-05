#include "Matrix.h"

Matrix::Matrix(double num)
{
    this->data = new matrixData(1, 1);
    this->data->matrix[0][0] = num;
}
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

size_t Matrix::getRefCount()
{
    return this->data->refCount;
}

Matrix::Matrix(string fileName)
{
    ifstream file;
    size_t rows, columns;
    file.open(fileName);
    if (!file.good()) {
        throw InvalidFileNameException();
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
    string input;
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < columns; j++) {
            if (file.eof()) {
                file.close();
                delete this->data;
                throw InvalidFileException();
            }
            file >> input;
            this->data->matrix[i][j] = stod(input);
            if (!file.eof() && file.fail()) {
                file.close();
                delete this->data;
                throw InvalidFileException();
            }
        }
    }
    this->data->rows = rows;
    this->data->columns = columns;

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

double Matrix::read(size_t rowIndex, size_t columnIndex) const
{
    return this->data->matrix[rowIndex][columnIndex];
}

void Matrix::write(size_t rowIndex, size_t columnIndex, double num)
{
    this->data = this->data->detach();
    this->data->matrix[rowIndex][columnIndex] = num;
}

void MatrixRef::operator=(double num)
{
    return this->matrix->write(this->rows, this->columns, num);
}

const double Matrix::operator()(size_t rowIndex, size_t columnIndex) const
{
    if (this->data->rows < rowIndex || this->data->columns < columnIndex ||
        rowIndex < 0 || columnIndex < 0) {
        throw InvalidIndexException();
    }
    return this->read(rowIndex - 1, columnIndex - 1);
}

MatrixRef Matrix::operator()(size_t rowIndex, size_t columnIndex)
{
    if (this->data->rows < rowIndex || this->data->columns < columnIndex ||
        rowIndex < 0 || columnIndex < 0) {
        throw InvalidIndexException();
    }
    return MatrixRef(this, rowIndex - 1, columnIndex - 1);
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
        throw InvalidMatrixSizeException();
    }
    this->data = this->data->detach();
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
        throw InvalidMatrixSizeException();
    }
    this->data = this->data->detach();
    for (size_t i = 1; i <= this->data->rows; i++) {
        for (size_t j = 1; j <= this->data->columns; j++) {
            this->data->matrix[i - 1][j - 1] -= m(i, j);
        }
    }
    return *this;
}

Matrix Matrix::multiplyMatrixByMatrix(const Matrix& m1, const Matrix& m2)
{
    Matrix result(m1.data->rows, m2.data->columns);
    double partialSum = 0;
    for (size_t i = 1; i <= m1.data->rows; i++) {
        for (size_t j = 1; j <= m2.data->columns; j++) {
            for (size_t k = 1; k <= m1.data->columns; k++) {
                partialSum += m1(i, k) * m2(k, j);
            }
            result(j, i) = partialSum;
            partialSum = 0;
        }
    }
    return result;
}

Matrix Matrix::multiplyMatrixByConst(const Matrix& m, double value)
{
    Matrix result(m.data->rows, m.data->columns);
    for (size_t i = 1; i <= m.data->rows; i++) {
        for (size_t j = 1; j <= m.data->columns; j++) {
            result(i, j) = value * m(i, j);
        }
    }
    return result;
}

Matrix operator*(const Matrix& m1, const Matrix& m2)
{
    if (m1.data->rows == 1 && m1.data->columns == 1) {
        return Matrix::multiplyMatrixByConst(m2, m1(1, 1));
    }
    else if (m2.data->rows == 1 && m2.data->columns == 1) {
        return Matrix::multiplyMatrixByConst(m1, m2(1, 1));
    }
    else {
        if (m1.data->columns != m2.data->rows) {
            throw InvalidMatrixSizeException();
        }
        return Matrix::multiplyMatrixByMatrix(m1, m2);
    }
}

Matrix& Matrix::operator*=(const Matrix& m)
{
    *this = *this * m;
    return *this;
}

Matrix operator+(const Matrix& m1, const Matrix& m2)
{
    if (m1.data->columns != m2.data->columns ||
        m1.data->rows != m2.data->rows) {
        throw InvalidMatrixSizeException();
    }
    Matrix result(m1);
    result += m2;
    return result;
}

Matrix operator-(const Matrix& m1, const Matrix& m2)
{
    if (m1.data->columns != m2.data->columns ||
        m1.data->rows != m2.data->rows) {
        throw InvalidMatrixSizeException();
    }
    Matrix result(m1);
    result -= m2;
    return result;
}
