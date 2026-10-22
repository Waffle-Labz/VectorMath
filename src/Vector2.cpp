#include <iostream>
#include <stdexcept>
#include "Vector2.h"

Vector2::Vector2(float x, float y)
{
    this->x = x;
    this->y = y;
}

float Vector2::MagnitudeSquared() const
{
    return (pow(x, 2) + pow(y, 2));
}

float Vector2::Magnitude() const
{
    return pow(MagnitudeSquared(), 0.5);
}

Vector2 Vector2::Normalised() const
{
    if (*this == Vector2(0, 0)) throw std::domain_error("Cannot normalise a zero vector");

    return (*this / Magnitude());
}

float Vector2::Dot(const Vector2& other) const
{
    return (x * other.x + y * other.y);
}

float Vector2::DistanceTo(const Vector2& other) const
{
    Vector2 r = other - *this;
    return r.Magnitude();
}

Vector2 Vector2::operator+(const Vector2& other) const
{
    return Vector2(x + other.x, y + other.y);
}

Vector2 Vector2::operator-(const Vector2& other) const
{
    return Vector2(x - other.x, y - other.y);
}

Vector2 Vector2::operator*(const float& scalar) const
{
    return Vector2(x * scalar, y * scalar);
}

Vector2 Vector2::operator/(const float& scalar) const
{
    if (scalar == 0) throw std::invalid_argument("Cannot divide by 0");

    return Vector2(x / scalar, y / scalar);
}

Vector2& Vector2::operator+=(const Vector2& other)
{
    x += other.x;
    y += other.y;

    return *this;
}

Vector2& Vector2::operator-=(const Vector2& other)
{
    x -= other.x;
    y -= other.y;

    return *this;
}

Vector2& Vector2::operator*=(const float& scalar)
{
    x *= scalar;
    y *= scalar;
    return *this;
}

Vector2& Vector2::operator/=(const float& scalar)
{

    if (scalar == 0) throw std::invalid_argument("Cannot divide by 0");

    x /= scalar;
    y /= scalar;
    return *this;
}

bool Vector2::operator==(const Vector2& other) const
{
    return (x == other.x) && (y == other.y);
}

bool Vector2::operator!=(const Vector2& other) const
{
    return !(*this == other);
}

Vector2 operator*(float scalar, const Vector2& v)
{
    return Vector2(v.x * scalar, v.y * scalar);
}

std::ostream& operator<<(std::ostream& os, const Vector2& v)
{
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}


