
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
        /// solves an system of linear equations with the gussian algorithm
        /// @returns a vector soving (vec[0] vec[1] vec[2]) * return = vec[3]
        ///
        vec3 solve_eqn_array_3(std::array<vec3, 4> vecs);

        ///
        /// check if ray collides with a primitive
        ///
        result<vec3> check_for_collision(ray mray, 
            primitives::polygons::triangle mtri );
    }
}
