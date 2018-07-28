#pragma once

#include <string>

namespace math {
    namespace vector{

    /// Class for mathematical oerations with cartesian Vectors
    /// Constructor: vec3(x, y, z) @Returns vec3 with cartesain Components x, y, z
    ///              vec3();       @Returns vec3 with Cartesain Components 0, 0, 0
    class vec3{

    public:
        vec3();
        vec3(float _x, float _y, float _z);

        void set(float _x, float _y, float _z);
        float get_x();
        float get_y();
        float get_z();

        void print();
        std::string to_str();

        vec3 normalize();
        float get_norm();

        vec3 operator /(float arg);
        vec3 operator +(vec3 arg);
        vec3 operator -(vec3 arg);
        vec3 operator *(float arg);

        private:
            float x, y, z;
        };
    }
}



float dotp(math::vector::vec3 arg1, math::vector::vec3 arg2);
math::vector::vec3 crossp(math::vector::vec3 arg1, math::vector::vec3 arg2);
