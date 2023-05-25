#include "../include/Vector2D.h"

Vector2D &Vector2D::operator+=(const Vector2D &rhs) {
    x += rhs.x;
    y += rhs.y;
    return *this;
}

Vector2D &Vector2D::operator-=(const Vector2D &rhs) {
    x -= rhs.x;
    y -= rhs.y;
    return *this;
}

Vector2D &Vector2D::operator*=(const Vector2D &rhs) {
    x *= rhs.x;
    y *= rhs.y;
    return *this;
}

Vector2D &Vector2D::operator/=(const Vector2D &rhs) {
    x /= rhs.x;
    y /= rhs.y;
    return *this;
}

Vector2D operator+(const Vector2D& v1, const Vector2D& v2) {
    return Vector2D(v1) += v2;
}

Vector2D operator-(const Vector2D& v1, const Vector2D& v2) {
    return Vector2D(v1) -= v2;
}

Vector2D operator*(const Vector2D& v1, const Vector2D& v2) {
    return Vector2D(v1) *= v2;
}

Vector2D operator/(const Vector2D& v1, const Vector2D& v2) {
    return Vector2D(v1) /= v2;
}

Vector2D &Vector2D::operator+=(const float &scalar) {
    x += scalar;
    y += scalar;
    return *this;
}

Vector2D &Vector2D::operator-=(const float &scalar) {
    x -= scalar;
    y -= scalar;
    return *this;
}

Vector2D &Vector2D::operator*=(const float &scalar) {
    x *= scalar;
    y *= scalar;
    return *this;
}

Vector2D &Vector2D::operator/=(const float &scalar) {
    x /= scalar;
    y /= scalar;
    return *this;
}

Vector2D operator+(const Vector2D& v, const float& scalar) {
    return Vector2D(v) += scalar;
}

Vector2D operator-(const Vector2D& v, const float& scalar) {
    return Vector2D(v) -= scalar;
}

Vector2D operator*(const Vector2D& v, const float& scalar) {
    return Vector2D(v) *= scalar;
}

Vector2D operator/(const Vector2D& v, const float& scalar) {
    return Vector2D(v) /= scalar;
}

std::ostream& operator<<(std::ostream& stream, const Vector2D& v) {
    stream << "(" << v.x << ", " << v.y << ")";
    return stream;
}
