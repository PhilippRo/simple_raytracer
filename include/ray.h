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
    ///
    /// \brief Constructor for Ray
    /// \param _trans Propagation Direction of the Ray
    /// \param _support Origin Point of Ray
    ///
    ray(vec3 _trans, vec3 _support);

    ///
    /// \brief Returns Propagation Direction
    /// \return vec3 Vector in Direction of Propagation
    ///
    vec3 get_translation();

    ///
    /// \brief Returns Origin Point
    /// \return vec3 Vector to the Origin Point of the Ray
    ///
    vec3 get_support();

};
