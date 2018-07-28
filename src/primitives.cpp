#include "primitives.h"

using namespace primitives::polygons;

triangle::triangle()
{

  this->a = vec3(0, 0, 0);
  this->b = vec3(0, 0, 0);
  this->c = vec3(0, 0, 0);

}

triangle::triangle(vec3 _a, vec3 _b, vec3 _c)
{

  this->a = _a;
  this->b = _b;
  this->c = _c;

}

triangle::set_points(vec3 _a, vec3 _b, vec3 _c)
{

  this->a = _a;
  this->b = _b;
  this->c = _c;

}

triangle::get_a()
{
  return this->a;
}

triangle::get_b()
{
  return this->b;
}

triangle::get_c()
{
  return this->c;
}
