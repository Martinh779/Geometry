// 
// Copyright (c) 2025 Martin Hertel. All rights reserved.
// 
// This software is released under the MIT License.
// See the LICENSE file for more details.
#ifndef GEOMETRY_VECTOR3D_H
#define GEOMETRY_VECTOR3D_H

#include <valarray>
#include <string>

namespace geometry {

    class Vector3D {
    public:
        float x;
        float y;
        float z;

        Vector3D(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}

        Vector3D operator+(const Vector3D &other) const {
            return {x + other.x, y + other.y, z + other.z};
        }

        Vector3D operator-(const Vector3D &other) const {
            return {x - other.x, y - other.y, z - other.z};
        }

        Vector3D operator*(float scalar) const {
            return {x * scalar, y * scalar, z * scalar};
        }

        Vector3D operator/(float scalar) const {
            return {x / scalar, y / scalar, z / scalar};
        }

        bool operator==(const Vector3D &other) const {
            return x == other.x && y == other.y && z == other.z;
        }

        [[nodiscard]] Vector3D cross(const Vector3D &other) const {
            return {
                y * other.z - z * other.y,
                z * other.x - x * other.z,
                x * other.y - y * other.x
            };
        }

        [[nodiscard]] float dot(const Vector3D &other) const {
            return x * other.x + y * other.y + z * other.z;
        }

        [[nodiscard]] float length() const {
            return std::sqrt(x * x + y * y + z * z);
        }

        Vector3D normalize() const {
            float len = length();
            if (len == 0) return {0, 0, 0}; // Avoid division by zero
            return {x / len, y / len, z / len};
        }

        [[nodiscard]] std::string toString() const {
            return "Vector3D(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
        }
    };

}

#endif //GEOMETRY_VECTOR3D_H
