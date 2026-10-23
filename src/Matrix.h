#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <iosfwd>

#include "Vector2.h"
#include "Vector3.h"

class Matrix
{
    int rows;
    int columns;
    
    public:
        static Matrix Identity(int size);

        bool isSquare;
        std::vector<float> elements;

        Matrix(int rows, int columns, float initialValue = 0.0);

        int Rows() const;
        int Columns() const;

        Matrix operator+(const Matrix& other) const;
        Matrix operator-(const Matrix& other) const;
        Matrix operator*(const Matrix& other) const;
        Vector2 operator*(const Vector2& vector) const;
        Vector3 operator*(const Vector3& vector) const;
        
        bool operator==(const Matrix& other) const;
        bool operator!=(const Matrix& other) const;

        Matrix& operator+=(const Matrix& other);
        Matrix& operator-=(const Matrix& other);
        Matrix& operator*=(const Matrix& other);

        float& operator()(const int row, const int col);
        float operator()(const int row, const int col) const;

        Matrix Transpose() const;
        Matrix& TransposeInPlace();
        void Fill(float num);
        float Determinant() const;
        Matrix Inverse() const;
        void Round(int decPlaces);
};

std::ostream& operator<<(std::ostream& os, const Matrix& m);

#endif