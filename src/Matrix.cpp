#include "Matrix.h"
#include <stdexcept>
#include <vector>
#include <iostream>
#include <cmath>
#include <utility>
#include <iomanip>
#include <sstream>
#include <string>
#include "Vector2.h"
#include "Vector3.h"

Matrix::Matrix(int rows, int columns, float initialValue)
{
    if (rows <= 0 || columns <= 0) throw std::invalid_argument("Dimensions are invalid");

    this->rows = rows;
    this->columns = columns;
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

void Matrix::Round(int decimalPlaces)
{
    if (decimalPlaces < 0)
        throw std::invalid_argument("Decimal places cannot be negative.");

    float factor = std::pow(10.0f, decimalPlaces);

    for (float& element : elements)
    {
        element = std::round(element * factor) / factor;
    }
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

    for (int i = 0; i < elements.size(); i++)
    {
        elements[i] += other.elements[i];
    }

    return *this;
}

Matrix& Matrix::operator-=(const Matrix& other)
{
    if (rows != other.rows || columns != other.columns) throw std::invalid_argument("Cannot add Matrices with different dimensions");

    for (int i = 0; i < elements.size(); i++)
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

    return *this;
}

bool Matrix::operator==(const Matrix& other) const
{
    if ((rows != other.Rows()) || (columns != other.Columns()))
        return false;

    for (int i = 0; i < elements.size(); i++)
    {
        if (elements[i] != other.elements[i])
            return false;
    }

    return true;
}

bool Matrix::operator!=(const Matrix& other) const
{
    return !(*this == other);
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

    return *this;
}

void Matrix::Fill(float num)
{
    for (int i = 0; i < elements.size(); i++)
    {
        elements[i] = num;
    }
}

float Matrix::Determinant() const
{
    if (!isSquare)
        throw std::invalid_argument("Determinant requires a square matrix.");

    Matrix G = *this;
    float sign = 1.0f;
    float factor;
    int pivotRow;

    for (int i = 0; i < rows; ++i)
    {
        // Find the row with the largest absolute pivot.
        pivotRow = i;

        for (int r = i + 1; r < rows; ++r)
        {
            if (std::abs(G(r, i)) >
                std::abs(G(pivotRow, i)))
            {
                pivotRow = r;
            }
        }

        // A zero pivot means the determinant is zero.
        if (G(pivotRow, i) == 0.0f)
        {
            return 0.0f;
        }

        // Swap rows if necessary.
        if (pivotRow != i)
        {
            for (int c = 0; c < columns; ++c)
            {
                std::swap(G(i, c), G(pivotRow, c));
            }

            sign = -sign;
        }

        // Eliminate entries below the pivot.
        for (int r = i + 1; r < rows; ++r)
        {
            factor = G(r, i) / G(i, i);

            for (int c = i; c < columns; ++c)
            {
                G(r, c) -= factor * G(i, c);
            }

            G(r, i) = 0.0f;
        }
    }

    // The determinant is the signed product of the diagonal.
    float determinant = sign;

    for (int i = 0; i < rows; ++i)
    {
        determinant *= G(i, i);
    }

    return determinant;
}

Matrix Matrix::Inverse() const
{
    float det = Determinant();

    if (det == 0.0f)
        throw std::invalid_argument("Matrix is singular");

    // Use Gauss-Jordan Elimination
    Matrix G_J = *this;
    Matrix inverse = Identity(rows);

    for (int i = 0; i < rows; ++i)
    {
        // Find the row with the largest absolute pivot.
        int pivotRow = i;

        for (int r = i + 1; r < rows; ++r)
        {
            if (std::abs(G_J(r, i)) >
                std::abs(G_J(pivotRow, i)))
            {
                pivotRow = r;
            }
        }

        // Swap rows in both matrices.
        if (pivotRow != i)
        {
            for (int c = 0; c < columns; ++c)
            {
                std::swap(G_J(i, c), G_J(pivotRow, c));
                std::swap(inverse(i, c), inverse(pivotRow, c));
            }
        }

        // Scale the pivot row so the pivot becomes 1.
        float pivot = G_J(i, i);

        for (int c = 0; c < columns; ++c)
        {
            G_J(i, c) /= pivot;
            inverse(i, c) /= pivot;
        }

        // Eliminate the pivot column in every other row.
        for (int r = 0; r < rows; ++r)
        {
            if (r == i)
            {
                continue;
            }

            float factor = G_J(r, i);

            for (int c = 0; c < columns; ++c)
            {
                G_J(r, c) -= factor * G_J(i, c);
                inverse(r, c) -= factor * inverse(i, c);
            }
        }
    }

    return inverse;
}

Vector2 Matrix::operator*(const Vector2& vector) const
{
    if (rows != 2 || columns != 2)
        throw std::invalid_argument("Matrix must be 2x2 to multiply by Vector2");

    Vector2 result(0.0f, 0.0f);

    result.x = (*this)(0, 0) * vector.x
             + (*this)(0, 1) * vector.y;

    result.y = (*this)(1, 0) * vector.x
             + (*this)(1, 1) * vector.y;

    return result;
}

Vector3 Matrix::operator*(const Vector3& vector) const
{
    if (rows != 3 || columns != 3)
        throw std::invalid_argument("Matrix must be 2x2 to multiply by Vector2");

    Vector3 result(0.0f, 0.0f, 0.0f);

    result.x = (*this)(0, 0) * vector.x
             + (*this)(0, 1) * vector.y
             + (*this)(0, 2) * vector.z;

    result.y = (*this)(1, 0) * vector.x
             + (*this)(1, 1) * vector.y
             + (*this)(1, 2) * vector.z;

    result.z = (*this)(2, 0) * vector.x
             + (*this)(2, 1) * vector.y
             + (*this)(2, 2) * vector.z;

    return result;
}

std::ostream& operator<<(std::ostream& os, const Matrix& m)
{
    const int rows = m.Rows();
    const int cols = m.Columns();

    // Preserve the stream's formatting settings.
    std::ios oldState(nullptr);
    oldState.copyfmt(os);

    os << "[ ";

    for (int i = 0; i < rows; i++)
    {
        if (i != 0)
            os << "  ";

        for (int j = 0; j < cols; j++)
        {
            float element = m.elements[i * cols + j];

            // Prevent negative zero when displaying small values.
            if (std::abs(element) < 0.0005f)
                element = 0.0f;

            std::ostringstream value;
            value << std::fixed << std::setprecision(3) << element;

            std::string number = value.str();

            // Remove unnecessary trailing zeros.
            while (number.find('.') != std::string::npos &&
                number.back() == '0')
            {
                number.pop_back();
            }

            if (!number.empty() && number.back() == '.')
                number.pop_back();

            os << number << ", ";
        }

        if (i != rows - 1)
            os << '\n';
    }

    os << "]" << '\n';

    os.copyfmt(oldState);
    return os;
}