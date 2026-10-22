#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iosfwd>

class Matrix
{
    int rows;
    int columns;
    
    public:
        static Matrix Identity(int size);

        int size;
        bool isSquare;
        std::vector<float> elements;

        Matrix(int rows, int columns, float initialValue = 0.0);

        int Rows() const;
        int Columns() const;

        Matrix operator+(const Matrix& other) const;
        Matrix operator-(const Matrix& other) const;
        Matrix operator*(const Matrix& other) const;

        Matrix& operator+=(const Matrix& other);
        Matrix& operator-=(const Matrix& other);
        Matrix& operator*=(const Matrix& other);

        float& operator()(const int row, const int col);
        float operator()(const int row, const int col) const;

        Matrix Transpose() const;
        Matrix& TransposeInPlace();
        void Fill(float num);
};

std::ostream& operator<<(std::ostream& os, const Matrix& m);

#endif