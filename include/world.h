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

///
/// \brief World Class to arrange objects and Camera in 3D-Space
///

class world{

private:

  std::map<int, triangle> objects;

  int next_index = 1;

  vec3 camera;
  int screen_w, screen_h;

public:

  world(int screen_w, int screen_h, vec3 camera);

  int add_object(triangle object);

  bool manipulate_object(int id, int mode, float param); ///\todo Use Function Pointer to manipulate Tris

  bool remove_object(int id);

  bitmap rasterize();
};
