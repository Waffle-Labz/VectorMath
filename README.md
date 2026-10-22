# VectorMath

A lightweight vector mathematics library written in C++, implementing two-dimensional and three-dimensional vectors. This project explores mathematical programming, operator overloading, class design, exception handling, and testing.

## Features

### Vector2

A two-dimensional vector type with the following functionality:

- **Arithmetic:** vector addition and subtraction, scalar multiplication and division.
- **Compound assignment:** `+=`, `-=`, `*=`, and `/=`.
- **Comparison:** equality and inequality operators.
- **Magnitude:** calculate the vector's magnitude and squared magnitude.
- **Normalisation:** obtain a unit vector in the same direction.
- **Dot product:** calculate the scalar product of two vectors.
- **Distance:** calculate the Euclidean distance between two vectors.
- **Stream output:** print vectors directly using `std::cout`.
- **Error handling:** exceptions for invalid operations, including division by zero and normalising a zero vector.

### Vector3

A three-dimensional vector type with the corresponding arithmetic, comparison, and mathematical functionality, extended to three dimensions.

Additional functionality includes:

- **Three-dimensional magnitude and normalisation.**
- **Dot product:** calculate the scalar product of two 3D vectors.
- **Cross product:** calculate a vector perpendicular to two input vectors.
- **Distance:** calculate the Euclidean distance between two vectors in 3D space.

## Examples

### Vector2

```cpp
#include <iostream>
#include "Vector2.h"

int main()
{
    Vector2 a{3.0f, 4.0f};
    Vector2 b{1.0f, 2.0f};

    std::cout << "a: " << a << '\n';
    std::cout << "Sum: " << a + b << '\n';
    std::cout << "Difference: " << a - b << '\n';
    std::cout << "Scaled: " << 2.0f * a << '\n';
    std::cout << "Magnitude: " << a.Magnitude() << '\n';
    std::cout << "Normalised: " << a.Normalised() << '\n';
    std::cout << "Dot product: " << a.Dot(b) << '\n';
    std::cout << "Distance: " << a.DistanceTo(b) << '\n';

    return 0;
}
```

### Vector3

```cpp
#include <iostream>
#include "Vector3.h"

int main()
{
    Vector3 a{1.0f, 2.0f, 3.0f};
    Vector3 b{4.0f, 5.0f, 6.0f};

    std::cout << "a: " << a << '\n';
    std::cout << "Sum: " << a + b << '\n';
    std::cout << "Magnitude: " << a.Magnitude() << '\n';
    std::cout << "Normalised: " << a.Normalised() << '\n';
    std::cout << "Dot product: " << a.Dot(b) << '\n';
    std::cout << "Cross product: " << a.Cross(b) << '\n';
    std::cout << "Distance: " << a.DistanceTo(b) << '\n';

    return 0;
}
```

The examples assume the public interfaces use the method names shown above.

## Building

The project uses the Microsoft Visual C++ compiler (MSVC).

Compile the relevant source files from a Developer Command Prompt for Visual Studio, or a terminal where `cl` is available.

For `Vector2`:

```bat
cl /EHsc /utf-8 main.cpp Vector2.cpp /Fe:VectorMath.exe
```

For `Vector3`:

```bat
cl /EHsc /utf-8 main.cpp Vector3.cpp /Fe:VectorMath.exe
```

If your test program is named `tests.cpp`, replace `main.cpp` with `tests.cpp`.

Run the executable:

```bat
VectorMath.exe
```

Compile only the source files needed for the chosen executable. If both vector implementations are used, include both `Vector2.cpp` and `Vector3.cpp`.

## Testing

The project includes a test program for checking the behaviour of the vector implementations.

Tests cover:

- Arithmetic and compound assignment operators.
- Equality and inequality.
- Stream output.
- Magnitude and squared magnitude.
- Normalisation.
- Dot and cross products, where applicable.
- Distance calculations.
- Exception handling for invalid operations.

Numerical tests use floating-point tolerances where appropriate to account for rounding errors.

## Future Development

Potential improvements include:

- Refactoring shared functionality to reduce duplication between `Vector2` and `Vector3`.
- Expanding test coverage for edge cases and numerical behaviour.
- Improving the library's interface and documentation.
- Reusing the vector types in future mathematical, simulation, or graphics projects.

## Purpose

VectorMath is a practical C++ learning project focused on implementing reusable mathematical types. It provides experience with class design, operator overloading, references, `const` correctness, numerical calculations, exception handling, and testing.

The goal is to develop a clear, maintainable vector mathematics library that can be reused in future programming and simulation projects.