#ifndef VECTOR2_H
#define VECTOR2_H

#include <iosfwd>

class Vector2 {

    public:
         double x;
         double y;

    public:
        Vector2(double x, double y);

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

        double Magnitude() const;
        double MagnitudeSquared() const;
        Vector2 Normalised() const;
        double Dot(const Vector2& other) const;
        double DistanceTo(const Vector2& other) const;
        
};

Vector2 operator*(double scalar, const Vector2& v);
std::ostream& operator<<(std::ostream& os, const Vector2& v);

#endif