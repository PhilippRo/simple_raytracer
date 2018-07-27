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
  std::cout << this->to_str() << std::endl;
}

std::string vec3::to_str()
{
  return "X: " + std::to_string(this->x) + "\n" +
         "Y: " + std::to_string(this->y) + "\n" +
         "Z: " + std::to_string(this->z);
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

vec3 vec3::crossp(vec3 arg)
{
  float x = this->y * arg.z - this->z * arg.y;
  float y = this->z * arg.x - this->x * arg.z;
  float z = this->x * arg.y - this->y * arg.x;

  vec3 vec_cross = vec3(x, y, z);

  return vec_cross;
}

///Operator override


vec3 vec3::operator /(float norm)
{
  vec3 vec_norm;
  vec_norm.x = this->x/norm;
  vec_norm.y = this->y/norm;
  vec_norm.z = this->z/norm;

  return vec_norm;
}

vec3 vec3::operator +(vec3 arg)
{
  vec3 result;

  result.x = this->x + arg.x;
  result.y = this->y + arg.y;
  result.z = this->z + arg.z;

  return result;

}

vec3 vec3::operator -(vec3 arg)
{
  vec3 result;

  result.x = this->x - arg.x;
  result.y = this->y - arg.y;
  result.z = this->z - arg.z;

  return result;

}

vec3 vec3::operator *(float arg)
{
  vec3 result;

  result.x = this->x * arg;
  result.y = this->y * arg;
  result.z = this->z * arg;

  return result;

}
