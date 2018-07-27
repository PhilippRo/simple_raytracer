#pragma once


namespace math {
    namespace vector{

    /// Class for mathematical oerations with cartesian Vectors
    /// Constructor: vec3(x, y, z) @Returns vec3 with cartesain Components x, y, z
    class vec3{

    public:
        vec3();
        vec3(float _x, float _y, float _z);

        void set(float _x, float _y, float _z);
        void print();

        vec3 normalize();
        float get_norm();
        float dotp(vec3 arg);
        vec3 crossp(vec3 arg);

        vec3 operator /(float norm);

        private:
            float x, y, z;
        };

    }
}
