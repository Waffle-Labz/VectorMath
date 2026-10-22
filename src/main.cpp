#include <iostream>
#include <cmath>
#include <sstream>
#include <stdexcept>
#include "Vector3.h"

int passed = 0;
int failed = 0;

void Test(const char* name, bool condition)
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

bool Near(float a, float b, float tolerance = 1e-5f)
{
    return std::fabs(a - b) <= tolerance;
}

bool Near(const Vector3& a, const Vector3& b,
          float tolerance = 1e-5f)
{
    return Near(a.x, b.x, tolerance) &&
           Near(a.y, b.y, tolerance) &&
           Near(a.z, b.z, tolerance);
}

int main()
{
    const Vector3 a{1.0f, 2.0f, 3.0f};
    const Vector3 b{4.0f, 5.0f, 6.0f};

    // Arithmetic
    Test("Addition", Near(a + b, Vector3{5, 7, 9}));
    Test("Subtraction", Near(a - b, Vector3{-3, -3, -3}));
    Test("Vector * scalar", Near(a * 2.0f, Vector3{2, 4, 6}));
    Test("Scalar * vector", Near(2.0f * a, Vector3{2, 4, 6}));
    Test("Division", Near(a / 2.0f, Vector3{0.5f, 1, 1.5f}));

    // Compound assignment
    Vector3 c = a;
    c += b;
    Test("operator+=", Near(c, Vector3{5, 7, 9}));

    c = a;
    c -= b;
    Test("operator-=", Near(c, Vector3{-3, -3, -3}));

    c = a;
    c *= 2.0f;
    Test("operator*=", Near(c, Vector3{2, 4, 6}));

    c = a;
    c /= 2.0f;
    Test("operator/=", Near(c, Vector3{0.5f, 1, 1.5f}));

    // Comparisons
    Test("Equality", a == Vector3{1, 2, 3});
    Test("Inequality", a != b);

    // Stream output (adjust expected string if your format differs)
    std::ostringstream output;
    output << a;
    Test("Stream output", output.str() == "(1, 2, 3)");

    // Mathematics
    Test("Magnitude", Near(a.Magnitude(), std::sqrt(14.0f)));
    Test("Magnitude squared", Near(a.MagnitudeSquared(), 14.0f));
    Test("Dot product", Near(a.Dot(b), 32.0f));
    Test("Cross product",
         Near(a.Cross(b), Vector3{-3, 6, -3}));
    Test("Distance", Near(a.DistanceTo(b), std::sqrt(27.0f)));

    Vector3 unit = a.Normalised();
    Test("Normalisation", Near(unit.Magnitude(), 1.0f));

    // Exceptions
    bool divisionThrew = false;
    try
    {
        Vector3 result = a / 0.0f;
    }
    catch (const std::exception&)
    {
        divisionThrew = true;
    }
    Test("Division by zero throws", divisionThrew);

    bool compoundDivisionThrew = false;
    try
    {
        Vector3 result = a;
        result /= 0.0f;
    }
    catch (const std::exception&)
    {
        compoundDivisionThrew = true;
    }
    Test("operator/= by zero throws", compoundDivisionThrew);

    bool normalisationThrew = false;
    try
    {
        Vector3 zero{0, 0, 0};
        Vector3 result = zero.Normalised();
    }
    catch (const std::exception&)
    {
        normalisationThrew = true;
    }
    Test("Normalising zero vector throws", normalisationThrew);

    // Summary
    std::cout << "\nPassed: " << passed
              << "\nFailed: " << failed
              << "\nTotal:  " << passed + failed << '\n';

    return failed == 0 ? 0 : 1;
}