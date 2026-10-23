# VectorMath

A C++ mathematics library implementing 2D and 3D vectors and matrices, with support for vector arithmetic, linear algebra, and matrix transformations.

The project focuses on developing a reusable mathematical library while exploring object-oriented programming, operator overloading, numerical algorithms, and C++ design principles.

## Features

### Vector2

A class representing two-dimensional vectors.

- Vector addition and subtraction
- Scalar multiplication and division
- Compound assignment operators
- Vector comparisons
- Magnitude and squared magnitude
- Vector normalisation
- Dot product
- Distance between vectors
- Stream output
- Error handling for invalid operations

### Vector3

A class representing three-dimensional vectors, extending the functionality of `Vector2`.

- Vector addition and subtraction
- Scalar multiplication and division
- Compound assignment operators
- Vector comparisons
- Magnitude and squared magnitude
- Vector normalisation
- Dot product and cross product
- Distance between vectors
- Stream output
- Error handling for invalid operations

### Matrix

A matrix class supporting matrices with arbitrary row and column dimensions.

- Matrix construction and element access
- Matrix addition and multiplication
- Matrix compound assignment
- Identity matrix generation
- Matrix transposition
- Filling a matrix with a specified value
- Determinant calculation using Gaussian elimination with partial pivoting
- Matrix inversion using Gauss–Jordan elimination with partial pivoting
- Matrix–column-vector multiplication for supported vector dimensions
- Stream output with controlled decimal formatting

Matrices use floating-point values and row-major storage. Matrix operations validate their dimensional requirements and report invalid operations through exceptions.

## Implementation

The library uses several C++ features and numerical techniques:

- **Object-oriented design:** encapsulates vector and matrix operations in reusable classes.
- **Operator overloading:** allows mathematical expressions to use familiar syntax, such as `a + b` and `A * B`.
- **Const correctness:** marks operations that do not modify their operands as `const`.
- **References:** avoids unnecessary copies when passing vectors and matrices to operations.
- **Dynamic storage:** uses `std::vector` to store matrix elements in a contiguous, one-dimensional array.
- **Numerical algorithms:** uses Gaussian elimination for determinants and Gauss–Jordan elimination for matrix inversion.
- **Exception handling:** detects invalid operations, including incompatible dimensions and singular matrices.

### Matrix storage

Matrix elements are stored in row-major order. The element at row `r` and column `c` is located at:

```cpp
elements[r * columns + c]
```

This allows a matrix of arbitrary dimensions to be stored in a contiguous array while retaining convenient two-dimensional element access.

### Matrix inversion

The inverse is calculated using Gauss–Jordan elimination. The algorithm augments the original matrix conceptually with an identity matrix and applies row operations until the original matrix is reduced to the identity. The corresponding transformed identity matrix then contains the inverse.

Partial pivoting is used to improve numerical stability by selecting a suitable pivot row at each elimination step.

Since the library uses floating-point arithmetic, numerical results may contain small rounding errors. Consequently, numerical tests should use tolerances where exact equality is inappropriate.

## Project Structure

```text
VectorMath/
├── src/
│   ├── Vector2.h
│   ├── Vector2.cpp
│   ├── Vector3.h
│   ├── Vector3.cpp
│   ├── Matrix.h
│   ├── Matrix.cpp
│   └── main.cpp
├── build.bat
└── README.md
```

- `src/` — contains the C++ header and implementation files, including the vector and matrix classes and the main entry point.
- `build.bat` — Windows build script for compiling and running the project.
- `README.md` — project documentation.

## Requirements

- Windows
- Microsoft Visual C++ compiler (`cl`)
- C++17-compatible compiler

## Building and Running

Open a Developer Command Prompt for Visual Studio, navigate to the project directory, and compile the source files:

```bat
cl /EHsc /std:c++17 /utf-8 main.cpp Matrix.cpp Vector2.cpp Vector3.cpp /Fe:VectorMath.exe
```

Alternatively, run the provided build script if configured:

```bat
build.bat
```

The executable runs the examples and tests defined in `main.cpp`.

## Example Usage

### Vector operations

```cpp
Vector2 a(3.0f, 4.0f);
Vector2 b(1.0f, 2.0f);

Vector2 sum = a + b;
float magnitude = a.Magnitude();
float dotProduct = a.Dot(b);
```

### Matrix operations

```cpp
Matrix A(2, 2);

A(0, 0) = 1.0f;
A(0, 1) = 2.0f;
A(1, 0) = 3.0f;
A(1, 1) = 4.0f;

Matrix transposed = A.Transpose();
float determinant = A.Determinant();
Matrix inverse = A.Inverse();
```

### Matrix–vector multiplication

```cpp
Matrix A(2, 2);

A(0, 0) = 1.0f;
A(0, 1) = 2.0f;
A(1, 0) = 3.0f;
A(1, 1) = 4.0f;

Vector2 v(5.0f, 6.0f);

Vector2 result = A * v;
```

The result is the column vector `(17, 39)`.

## Limitations

- Vector dimensions are fixed by the `Vector2` and `Vector3` classes.
- Matrix–vector multiplication is limited to vector dimensions supported by the corresponding overloads.
- Floating-point arithmetic introduces rounding errors, particularly in numerical algorithms involving elimination and inversion.
- The library is intended for learning and general mathematical computations rather than high-performance scientific computing.

## Future Development

Potential extensions include:

- Additional matrix–vector multiplication overloads
- More comprehensive automated tests
- Improved numerical tolerance handling
- Additional matrix decompositions and linear algebra algorithms
- A general dynamically sized vector class

## Purpose

This project serves as an exploration of C++ software design and numerical computing. It combines reusable mathematical abstractions with practical implementation of linear algebra algorithms, providing a foundation for future programming and scientific computing projects.
