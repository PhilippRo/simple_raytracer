#pragma once
#include <vector>
#include <map>
#include <iostream>

#include <linalg.h>
#include <vec3.h>
#include <primitives.h>
#include <gfx.h>


using namespace primitives::polygons;
using namespace math::vector;

class world{

private:

  std::map<int, triangle> objects;

  int next_index = 1;

  vec3 camera;
  int screen_w, screen_h;

public:

  world(int screen_w, int screen_h, vec3 camera);

  int add_object(triangle object);

  bool remove_object(int id);

  bitmap rasterize();
};
