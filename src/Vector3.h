#ifndef VECTOR3_H
#define VECTOR3_H

#include <iosfwd>

class Vector3 
{
    public:
         float x;
         float y;
         float z;

    public:
        Vector3(float x, float y, float z);

        Vector3 operator+(const Vector3& other) const;
        Vector3 operator-(const Vector3& other) const;
        Vector3 operator*(const float& scalar) const;
        Vector3 operator/(const float& scalar) const;

        Vector3& operator+=(const Vector3& other);
        Vector3& operator-=(const Vector3& other);
        Vector3& operator*=(const float& scalar);
        Vector3& operator/=(const float& scalar);
        
        bool operator==(const Vector3& other) const;
        bool operator!=(const Vector3& other) const;

        float Magnitude() const;
        float MagnitudeSquared() const;
        Vector3 Normalised() const;
        float Dot(const Vector3& other) const;
        Vector3 Cross(const Vector3& other) const;
        float DistanceTo(const Vector3& other) const;
        
};

Vector3 operator*(float scalar, const Vector3& v);
std::ostream& operator<<(std::ostream& os, const Vector3& v);

#endif