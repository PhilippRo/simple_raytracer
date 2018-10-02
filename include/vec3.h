#pragma once

#include <string>

namespace math {
    namespace vector{

    /// Class for mathematical oerations with cartesian Vectors
    /// Constructor: vec3(x, y, z) @Returns vec3 with Cartesian Components x, y, z
    ///              vec3();       @Returns vec3 with Cartesian Components 0, 0, 0
    class vec3{

    public:
        vec3();
        vec3(float _x, float _y, float _z);

        void set(float _x, float _y, float _z);

        float get_x() const;
        float get_y() const;
        float get_z() const;

        void print() const;
        std::string to_str() const;

        vec3 normalize() const;
        float get_norm() const;

        vec3 operator /(float arg) const;
        vec3 operator +(vec3 arg) const;
        vec3 operator -(vec3 arg) const;
        vec3 operator *(float arg) const;
        bool operator ==(vec3 arg) const;
        bool operator !=(vec3 arg) const;
        float& operator[](int arg);

        private:
            float x, y, z;
        };
    }
}



float dotp(math::vector::vec3 arg1, math::vector::vec3 arg2);
math::vector::vec3 crossp(math::vector::vec3 arg1, math::vector::vec3 arg2);
