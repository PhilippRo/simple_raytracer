#pragma once

#include <vec3.h>


using namespace math::vector;

///
/// Class desinged to store information about the ray to traced.
/// It defines a line equation
///
class ray{
private:
    vec3 translation, support;

public:
    ray(vec3 _trans, vec3 _support);
    vec3 get_translation();
    vec3 get_support();

};
