# VectorMath

A lightweight vector mathematics library written in C++, developed as a practical project for learning C++ and exploring object-oriented design, operator overloading, and mathematical programming.

## Features

### Vector2

The library currently implements a two-dimensional vector type with the following functionality:

- **Arithmetic:** vector addition and subtraction, scalar multiplication and division.
- **Compound assignment:** `+=`, `-=`, `*=`, and `/=`.
- **Comparison:** equality and inequality operators.
- **Mathematical operations:** magnitude, squared magnitude, normalisation, dot product, and distance between vectors.
- **Stream output:** print vectors directly using `std::cout`.
- **Error handling:** exceptions for invalid operations, including division by zero and normalising a zero vector.

## Example

```cpp
#include <iostream>
#include "Vector2.h"

int main()
{
    Vector2 a{3.0, 4.0};
    Vector2 b{1.0, 2.0};

    Vector2 sum = a + b;
    Vector2 difference = a - b;
    Vector2 scaled = 2.0 * a;
    Vector2 normalised = a.Normalised();

    std::cout << "a: " << a << '\n';
    std::cout << "b: " << b << '\n';
    std::cout << "Sum: " << sum << '\n';
    std::cout << "Difference: " << difference << '\n';
    std::cout << "Scaled: " << scaled << '\n';
    std::cout << "Magnitude: " << a.Magnitude() << '\n';
    std::cout << "Normalised: " << normalised << '\n';
    std::cout << "Dot product: " << a.Dot(b) << '\n';
    std::cout << "Distance: " << a.DistanceTo(b) << '\n';

    return 0;
}
```

*Note: this example assumes the public interface uses the method names shown above and supports construction from two numeric coordinates.*

## Building

The project uses the Microsoft Visual C++ compiler (MSVC).

Compile the source files from a Developer Command Prompt for Visual Studio, or from a terminal where `cl` is available:

```bat
cl /EHsc /utf-8 main.cpp Vector2.cpp /Fe:VectorMath.exe
```

Replace `main.cpp` with your test file's name if it differs.

Run the resulting executable:

```bat
VectorMath.exe
```

## Testing

The project includes a test program covering arithmetic, comparisons, stream output, mathematical operations, and exception handling.

The tests use floating-point tolerances for numerical calculations to account for rounding errors.

## Project Structure

```text
VectorMath/
├── Vector2.h
├── Vector2.cpp
├── main.cpp
├── README.md
├── .gitignore
└── build.bat
```

The exact file structure may vary as the project develops.

## Planned Development

- [ ] Implement a three-dimensional `Vector3` type.
- [ ] Add three-dimensional vector operations, including the cross product.
- [ ] Expand the test suite as new functionality is added.
- [ ] Refine the library's design and documentation.

## Purpose

This project is an opportunity to develop practical C++ skills through a reusable mathematical component. It provides experience with classes and encapsulation, operator overloading, references, `const` correctness, exception handling, and testing.

The longer-term goal is to build a small, well-tested vector mathematics library that can be reused in future programming and simulation projects.