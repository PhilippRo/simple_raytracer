#include "vector.h"

#include <iostream>
#include <cmath>

using namespace math::vector;

vec3::vec3()
{
  x = 0;
  y = 0;
  z = 0;
}

vec3::vec3(float _x, float _y, float _z)
{
  x = _x;
  y = _y;
  z = _z;
}

void vec3::set(float _x, float _y, float _z)
{
  this->x = _x;
  this->y = _y;
  this->z = _z;
}

void vec3::print()
{
  std::cout << "x: " << this->x << std::endl;
  std::cout << "y: " << this->y << std::endl;
  std::cout << "z: " << this->z << std::endl;
}

vec3 vec3::normalize()
{
  vec3 vec_norm;
  float norm = this->get_norm();

  vec_norm = *this/norm;

  return vec_norm;
}

float vec3::get_norm()
{
  return std::sqrt(this->dotp(*this));
}

float vec3::dotp(vec3 arg)
{
  return this->x*arg.x + this->y*arg.y + this->z*arg.z;
}

vec3 vec3::operator /(float norm)
{
  vec3 vec_norm;
  vec_norm.x = this->x/norm;
  vec_norm.y = this->y/norm;
  vec_norm.z = this->z/norm;

  return vec_norm;
}
