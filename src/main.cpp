#include <iostream>

// #include "Vector3.h"
#include "Matrix.h"

using namespace std;

int main()
{
    Matrix A(2, 2);
    A(0, 0) = 1.0f;
    A(0, 1) = 2.0f;
    A(1, 0) = 3.0f;
    A(1, 1) = 4.0f;

    Matrix B(2, 2);
    B(0, 0) = 10.0f;
    B(0, 1) = 2.0f;
    B(1, 0) = 3.0f;
    B(1, 1) = 4.0f;


    std::cout << (A == B);
    
}