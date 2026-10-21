#include <iostream>
#include <cmath>
#include <sstream>
#include <stdexcept>
#include "Vector2.h"

int passed = 0;
int failed = 0;

void Test(const std::string& name, bool condition)
{
    if (condition)
    {
        std::cout << "[PASS] " << name << '\n';
        ++passed;
    }
    else
    {
        std::cout << "[FAIL] " << name << '\n';
        ++failed;
    }
}

bool NearlyEqual(float a, float b, float tolerance = 1e-5f)
{
    return std::fabs(a - b) <= tolerance;
}

bool NearlyEqual(const Vector2& a, const Vector2& b,
                 float tolerance = 1e-5f)
{
    return NearlyEqual(a.x, b.x, tolerance) &&
           NearlyEqual(a.y, b.y, tolerance);
}

int main()
{
    const Vector2 a{3.0f, 4.0f};
    const Vector2 b{1.0f, 2.0f};

    // 1. Arithmetic operators
    Test("Addition", NearlyEqual(a + b, Vector2{4.0f, 6.0f}));
    Test("Subtraction", NearlyEqual(a - b, Vector2{2.0f, 2.0f}));
    Test("Vector * scalar", NearlyEqual(a * 2.0, Vector2{6.0f, 8.0f}));
    Test("Scalar * vector", NearlyEqual(2.0 * a, Vector2{6.0f, 8.0f}));
    Test("Division by scalar", NearlyEqual(a / 2.0f, Vector2{1.5f, 2.0f}));

    // 2. Compound assignment operators
    Vector2 c{3.0f, 4.0f};
    c += b;
    Test("Addition assignment", NearlyEqual(c, Vector2{4.0f, 6.0f}));

    c = {3.0f, 4.0f};
    c -= b;
    Test("Subtraction assignment", NearlyEqual(c, Vector2{2.0f, 2.0f}));

    c = {3.0f, 4.0f};
    c *= 2.0f;
    Test("Multiplication assignment", NearlyEqual(c, Vector2{6.0f, 8.0f}));

    c = {3.0f, 4.0f};
    c /= 2.0f;
    Test("Division assignment", NearlyEqual(c, Vector2{1.5f, 2.0f}));

    // 3. Comparison operators
    Test("Equal vectors", a == Vector2{3.0f, 4.0f});
    Test("Unequal vectors", a != b);
    Test("Equal vectors compare false for !=", !(a != Vector2{3.0f, 4.0f}));

    // 4. Stream output
    std::ostringstream output;
    output << a;
    Test("Stream output", output.str() == "(3, 4)");

    // 5. Mathematical methods
    Test("Magnitude", NearlyEqual(a.Magnitude(), 5.0f));
    Test("Magnitude squared", NearlyEqual(a.MagnitudeSquared(), 25.0f));
    Test("Normalisation",
         NearlyEqual(a.Normalised(), Vector2{0.6f, 0.8f}));
    Test("Dot product", NearlyEqual(a.Dot(b), 11.0f));
    Test("Distance", NearlyEqual(a.DistanceTo(b), std::sqrt(8.0f)));

    // 6. Exceptions
    bool divisionThrew = false;
    try
    {
        Vector2 result = a / 0.0f;
    }
    catch (const std::exception&)
    {
        divisionThrew = true;
    }
    Test("Division by zero throws", divisionThrew);

    bool compoundDivisionThrew = false;
    try
    {
        Vector2 result = a;
        result /= 0.0f;
    }
    catch (const std::exception&)
    {
        compoundDivisionThrew = true;
    }
    Test("Division assignment by zero throws", compoundDivisionThrew);

    bool normalisationThrew = false;
    try
    {
        Vector2 zero{0.0f, 0.0f};
        Vector2 result = zero.Normalised();
    }
    catch (const std::exception&)
    {
        normalisationThrew = true;
    }
    Test("Normalising zero vector throws", normalisationThrew);

    // 7. Summary
    std::cout << "\n-------------------------\n";
    std::cout << "Passed: " << passed << '\n';
    std::cout << "Failed: " << failed << '\n';
    std::cout << "Total:  " << passed + failed << '\n';

    return failed == 0 ? 0 : 1;
}