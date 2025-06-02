// 
// Copyright (c) 2025 Martin Hertel. All rights reserved.
// 
// This software is released under the MIT License.
// See the LICENSE file for more details.
#ifndef GEOMETRY_FACE_H
#define GEOMETRY_FACE_H

#include "Vector3D.h"
#include "Triangle.h"

namespace geometry {
    class Face {
    public:
        Face() = default;

        Face(const Vector3D &normal, const Triangle &triangle)
            : normal(normal), triangle(triangle) {}

        Vector3D normal;  // Normal vector of the face
        Triangle triangle; // Triangle that defines the face

        // Function to get a string representation of the face
        std::string toString() const {
            return "Face(normal: " + normal.toString() + ", triangle: " + triangle.toString() + ")";
        }

        // Equality operator for Face
        bool operator==(const Face &other) const {
            return normal == other.normal && triangle == other.triangle;
        }

        // Inequality operator for Face
        bool operator!=(const Face &other) const {
            return !(*this == other);
        }

        // Function to get the area of the face
        float area() const {
            return triangle.area();
        }

        // Function to get the centroid of the face
        Vector3D centroid() const {
            return triangle.centroid();
        }
    };
}

#endif //GEOMETRY_FACE_H
