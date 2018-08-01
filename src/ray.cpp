#include <ray.h>
#include <vec3.h>

using namespace math::vector;

ray::ray(vec3 _trans, vec3 _support)
    : translation(_trans)
    , support(_support) {
}

vec3 ray::get_translation(){
    return this->translation;
}

vec3 ray::get_support(){
    return this->support;
}
