#include <iostream>
#include <stdexcept>
#include "Vector3.h"

Vector3::Vector3(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

float Vector3::MagnitudeSquared() const
{
    return (pow(x, 2) + pow(y, 2) + pow(z, 2));
}

float Vector3::Magnitude() const
{
    return pow(MagnitudeSquared(), 0.5);
}

Vector3 Vector3::Normalised() const
{
    if (*this == Vector3(0, 0, 0)) throw std::domain_error("Cannot normalise a zero vector");

    return (*this / Magnitude());
}

float Vector3::Dot(const Vector3& other) const
{
    return (x * other.x + y * other.y + z * other.z);
}

Vector3 Vector3::Cross(const Vector3& other) const
{
    return Vector3(
        y * other.z - z * other.y,
        z * other.x - x * other.z,
        x * other.y - y * other.x
    );
}

float Vector3::DistanceTo(const Vector3& other) const
{
    Vector3 r = other - *this;
    return r.Magnitude();
}

Vector3 Vector3::operator+(const Vector3& other) const
{
    return Vector3(x + other.x, y + other.y, z + other.z);
}

Vector3 Vector3::operator-(const Vector3& other) const
{
    return Vector3(x - other.x, y - other.y, z - other.z);
}

Vector3 Vector3::operator*(const float& scalar) const
{
    return Vector3(x * scalar, y * scalar, z * scalar);
}

Vector3 Vector3::operator/(const float& scalar) const
{
    if (scalar == 0) throw std::invalid_argument("Cannot divide by 0");

    return Vector3(x / scalar, y / scalar, z / scalar);
}

Vector3& Vector3::operator+=(const Vector3& other)
{
    x += other.x;
    y += other.y;
    z += other.z;

    return *this;
}

Vector3& Vector3::operator-=(const Vector3& other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;

    return *this;
}

Vector3& Vector3::operator*=(const float& scalar)
{
    x *= scalar;
    y *= scalar;
    z *= scalar;

    return *this;
}

Vector3& Vector3::operator/=(const float& scalar)
{

    if (scalar == 0) throw std::invalid_argument("Cannot divide by 0");

    x /= scalar;
    y /= scalar;
    z /= scalar;

    return *this;
}

bool Vector3::operator==(const Vector3& other) const
{
    return (x == other.x) && (y == other.y) && (z == other.z);
}

bool Vector3::operator!=(const Vector3& other) const
{
    return !(*this == other);
}

Vector3 operator*(float scalar, const Vector3& v)
{
    return Vector3(v.x * scalar, v.y * scalar, v.z * scalar);
}

std::ostream& operator<<(std::ostream& os, const Vector3& v)
{
    os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return os;
}


