#ifndef VECTOR2_H
#define VECTOR2_H

#include <iosfwd>

class Vector2 
{
    public:
         float x;
         float y;

    public:
        Vector2(float x, float y);

        Vector2 operator+(const Vector2& other) const;
        Vector2 operator-(const Vector2& other) const;
        Vector2 operator*(const float& scalar) const;
        Vector2 operator/(const float& scalar) const;

        Vector2& operator+=(const Vector2& other);
        Vector2& operator-=(const Vector2& other);
        Vector2& operator*=(const float& scalar);
        Vector2& operator/=(const float& scalar);
        
        bool operator==(const Vector2& other) const;
        bool operator!=(const Vector2& other) const;

        float Magnitude() const;
        float MagnitudeSquared() const;
        Vector2 Normalised() const;
        float Dot(const Vector2& other) const;
        float DistanceTo(const Vector2& other) const;
        
};

Vector2 operator*(float scalar, const Vector2& v);
std::ostream& operator<<(std::ostream& os, const Vector2& v);

#endif