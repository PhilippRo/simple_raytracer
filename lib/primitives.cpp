#include <primitives.h>

using namespace primitives::polygons;
using namespace primitives;
using namespace math::vector;

triangle::triangle()
{

  a = vec3(0, 0, 0);
  b = vec3(0, 0, 0);
  c = vec3(0, 0, 0);

  support = a;
  normal = crossp(b - a, c - a);

  mat = material(color(255, 255, 255));
}

triangle::triangle(vec3 _a, vec3 _b, vec3 _c)
{

  a = _a;
  b = _b;
  c = _c;

  support = a;
  normal = crossp(b - a, c - a);

  mat = material(color(255, 255, 255));

}

void triangle::set_points(vec3 _a, vec3 _b, vec3 _c)
{

  a = _a;
  b = _b;
  c = _c;

  support = a;
  normal = crossp(b - a, c - a);
}

void triangle::set_material(material _mat)
{
    mat = _mat;
}

material triangle::get_material()
{
    return mat;
}

vec3 triangle::get_a()
{
  return this->a;
}

vec3 triangle::get_b()
{
  return this->b;
}

vec3 triangle::get_c()
{
  return this->c;
}

vec3 triangle::get_norm()
{
    return normal;
}

vec3 triangle::get_support()
{
    return support;
}

material::material()
{
    col = color(0, 0, 0);
    alpha = 1;
    refrac = 1;
}

material::material(color _col)
{
    col = _col;
    alpha = 1;
    refrac = 1;
}

material::material(color _col, float _refrac)
{
    col = _col;
    alpha = 1;
    refrac = _refrac;
}

color material::get_color()
{
    return col;
}
