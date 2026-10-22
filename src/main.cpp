#include <iostream>

// #include "Vector3.h"
#include "Matrix.h"

using namespace std;

int main()
{
    Matrix A(2, 3);

    A(0, 0) = 1; A(0, 1) = 2; A(0, 2) = 3;
    A(1, 0) = 4; A(1, 1) = 5; A(1, 2) = 6;

    // Matrix T = A.Transpose();

    cout << A.TransposeInPlace().TransposeInPlace();

    // A.Fill(9.0);

    // cout << A;
}