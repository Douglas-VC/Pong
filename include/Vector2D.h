#ifndef PONG_VECTOR2D_H
#define PONG_VECTOR2D_H

#include <ostream>

class Vector2D {
public:
    float x;
    float y;

    Vector2D() : x{}, y{} {};
    Vector2D(float x, float y) : x{x}, y{y} {};

    Vector2D& operator+=(const Vector2D& rhs);
    Vector2D& operator-=(const Vector2D& rhs);
    Vector2D& operator*=(const Vector2D& rhs);
    Vector2D& operator/=(const Vector2D& rhs);

    friend Vector2D operator+(const Vector2D& v1, const Vector2D& v2);
    friend Vector2D operator-(const Vector2D& v1, const Vector2D& v2);
    friend Vector2D operator*(const Vector2D& v1, const Vector2D& v2);
    friend Vector2D operator/(const Vector2D& v1, const Vector2D& v2);

    Vector2D& operator+=(const float& scalar);
    Vector2D& operator-=(const float& scalar);
    Vector2D& operator*=(const float& scalar);
    Vector2D& operator/=(const float& scalar);

    friend Vector2D operator+(const Vector2D& v, const float& scalar);
    friend Vector2D operator-(const Vector2D& v, const float& scalar);
    friend Vector2D operator*(const Vector2D& v, const float& scalar);
    friend Vector2D operator/(const Vector2D& v, const float& scalar);

    friend std::ostream& operator<<(std::ostream& stream, const Vector2D& v);
};

#endif //PONG_VECTOR2D_H
