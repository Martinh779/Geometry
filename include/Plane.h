// 
// Copyright (c) 2025 Martin Hertel. All rights reserved.
// 
// This software is released under the MIT License.
// See the LICENSE file for more details.
#ifndef GEOMETRY_PLANE_H
#define GEOMETRY_PLANE_H

namespace geometry {

    class Plane {
    public:
        Plane() = default;

        Plane(const Vector3D &normal, float d) : normal(normal), d(d) {}

        Vector3D normal; // Normal vector of the plane
        float d;         // Distance from the origin

        // Function to get a string representation of the plane
        std::string toString() const {
            return "Plane(normal: " + normal.toString() + ", d: " + std::to_string(d) + ")";
        }

        // Function to check if a point is on the plane
        bool contains(const Vector3D &point) const {
            return normal.dot(point) + d == 0;
        }

        // Function to get the distance from a point to the plane
        float distanceToPoint(const Vector3D &point) const {
            return (normal.dot(point) + d) / normal.length();
        }

        // Function to get the intersection point of a line and the plane
        Vector3D intersection(const Vector3D &linePoint, const Vector3D &lineDirection) const {
            float t = -(normal.dot(linePoint) + d) / normal.dot(lineDirection);
            return linePoint + lineDirection * t;
        }

        // Equality operator for Plane
        bool operator==(const Plane &other) const {
            return normal == other.normal && d == other.d;
        }
    };
}

#endif //GEOMETRY_PLANE_H
