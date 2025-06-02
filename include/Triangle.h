// 
// Copyright (c) 2025 Martin Hertel. All rights reserved.
// 
// This software is released under the MIT License.
// See the LICENSE file for more details.
#ifndef GEOMETRY_TRIANGLE_H
#define GEOMETRY_TRIANGLE_H

#include "Vector3D.h"

namespace geometry {
    class Triangle {
    public:
        Vector3D v1;
        Vector3D v2;
        Vector3D v3;

        Triangle() = default;

        Triangle(const Vector3D &v1, const Vector3D &v2, const Vector3D &v3)
            : v1(v1), v2(v2), v3(v3) {}

        [[nodiscard]] Vector3D normal() const {
            Vector3D edge1 = v2 - v1;
            Vector3D edge2 = v3 - v1;
            return edge1.cross(edge2).normalize();
        }

        [[nodiscard]] std::string toString() const {
            return "Triangle(" + v1.toString() + ", " + v2.toString() + ", " + v3.toString() + ")";
        }

        bool operator==(const Triangle &other) const {
            return (v1 == other.v1 && v2 == other.v2 && v3 == other.v3) ||
                   (v1 == other.v2 && v2 == other.v3 && v3 == other.v1) ||
                   (v1 == other.v3 && v2 == other.v1 && v3 == other.v2);
        }

        bool operator!=(const Triangle &other) const {
            return !(*this == other);
        }

        [[nodiscard]] float area() const {
            Vector3D edge1 = v2 - v1;
            Vector3D edge2 = v3 - v1;
            return 0.5f * edge1.cross(edge2).length();
        }

        [[nodiscard]] Vector3D centroid() const {
            return (v1 + v2 + v3) / 3.0f;
        }
    };
}

#endif //GEOMETRY_TRIANGLE_H
