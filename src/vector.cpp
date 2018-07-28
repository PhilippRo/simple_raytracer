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

float vec3::get_x()
{
  return this->x;
}

float vec3::get_y()
{
  return this->y;
}

float vec3::get_z()
{
  return this->z;
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
  return std::sqrt(dotp(*this, *this));
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


///Non Member Functions

float dotp(vec3 arg1, vec3 arg2)
{
  return arg1.get_x()*arg2.get_x() + arg1.get_y()*arg2.get_y() + arg1.get_z()*arg1.get_z();
}

vec3 crossp(vec3 arg1, vec3 arg2)
{
  float x = arg1.get_y() * arg2.get_z() - arg1.get_z() * arg2.get_y();
  float y = arg1.get_z() * arg2.get_x() - arg1.get_x() * arg2.get_z();
  float z = arg1.get_x() * arg2.get_y() - arg1.get_y() * arg2.get_x();

  vec3 vec_cross = vec3(x, y, z);

  return vec_cross;
}
