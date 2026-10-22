#include "Matrix.h"
#include <stdexcept>
#include <vector>
#include <iostream>

Matrix::Matrix(int rows, int columns, float initialValue)
{
    if (rows <= 0 || columns <= 0) throw std::invalid_argument("Dimensions are invalid");

    this->rows = rows;
    this->columns = columns;
    this->size = rows * columns;
    this->isSquare = (rows == columns);
    this->elements = std::vector<float>(rows * columns, initialValue);
}

Matrix Matrix::Identity(int size)
{
    Matrix I(size, size);

    for (int i = 0; i < size; i++)
    {
        I.elements[i * size + i] = 1;
    }

    return I;
}

int Matrix::Rows() const
{
    return rows;
}

int Matrix::Columns() const
{
    return columns;
}

Matrix Matrix::operator+(const Matrix& other) const
{
    Matrix R = *this;

    return (R += other);
}

Matrix Matrix::operator-(const Matrix& other) const
{
    Matrix R = *this;

    return (R -= other);
}

Matrix Matrix::operator*(const Matrix& other) const
{
    Matrix R =  *this;

    return (R *= other);
}

Matrix& Matrix::operator+=(const Matrix& other)
{
    if (rows != other.rows || columns != other.columns) throw std::invalid_argument("Cannot add Matrices with different dimensions");

    for (int i = 0; i < size; i++)
    {
        elements[i] += other.elements[i];
    }

    return *this;
}

Matrix& Matrix::operator-=(const Matrix& other)
{
    if (rows != other.rows || columns != other.columns) throw std::invalid_argument("Cannot add Matrices with different dimensions");

    for (int i = 0; i < size; i++)
    {
        elements[i] -= other.elements[i];
    }

    return *this;
}

Matrix& Matrix::operator*=(const Matrix& other)
{
    if (columns != other.rows) throw std::invalid_argument("Cannot multiply two matrices with different inner dimensions");

    Matrix R(rows, other.columns);

    for (int r = 0; r < rows; ++r)
    {
        for (int c = 0; c < other.columns; ++c)
        {
            for (int k = 0; k < columns; ++k)
            {
                R(r, c) += (*this)(r, k) * other(k, c);
            }
        }
    }

    rows = R.Rows();
    columns = R.Columns();
    elements = R.elements;
    size = R.size;

    return *this;
}

float& Matrix::operator()(const int row, const int col)
{
    if (row >= rows || col >= columns) throw std::out_of_range("Matrix index out of range");

    return elements[row * columns + col];
}

float Matrix::operator()(const int row, const int col) const
{
    if (row >= rows || col >= columns) throw std::out_of_range("Matrix index out of range");

    return elements[row * columns + col];
}

Matrix Matrix::Transpose() const
{
    Matrix R(columns, rows);

    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c < columns; c++)
        {
            R(c, r) = (*this)(r, c);
        }
    }

    return R;
}

Matrix& Matrix::TransposeInPlace()
{
    Matrix R = Transpose();

    rows = R.Rows();
    columns = R.Columns();
    elements = R.elements;
    size = R.size;

    return *this;
}

void Matrix::Fill(float num)
{
    for (int i = 0; i < size; i++)
    {
        elements[i] = num;
    }
}

std::ostream& operator<<(std::ostream& os, const Matrix& m)
{
    const int rows = m.Rows();
    const int cols = m.Columns();

    os << "[ ";
    
    for (int i = 0; i < rows; i++)
    {
        if (i != 0) os << "  ";

        for (int j = 0; j < cols; j++)
        {
            os << m.elements[i*cols + j] << ", ";
        }
        if (i != rows - 1) os << std::endl;
    }

    os << "]" << std::endl;

    return os;
}