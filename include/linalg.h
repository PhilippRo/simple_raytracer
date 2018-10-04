#pragma once

#include <vec3.h>
#include <primitives.h>
#include <ray.h>
#include <result.h>

#include <array>

namespace math{
    namespace linalg {


        using namespace math::vector;

        ///
        /// \brief Check where ray collides with triangle plane
        /// \param mray Ray to check for collision with Triangle
        /// \param mtris Triangle which collides with ray
        /// @returns result<vec3> with packed collision point with plane. Collision pont must NOT be inside Triangle
        ///

        result<math::vector::vec3> ray_plane_intersection(ray mray,
              primitives::polygons::triangle mtris);

        ///
        /// \brief  Check if the Point given is inside a triangle
        /// \param point Point to be checked
        /// \param mtris Triangle in which the point should lay
        /// @returns bool True if point is inside triangle, False if outside Triangle
        ///

        bool is_point_in_tris(vec3 point, primitives::polygons::triangle mtris);
    }
}
