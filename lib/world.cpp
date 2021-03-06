#include "world.h"

using namespace primitives::polygons;
using namespace math::vector;

world::world(int _screen_w, int _screen_h, vec3 _camera)
{
  camera = _camera;
  screen_h = _screen_h;
  screen_w = _screen_w;
}

int world::add_object(triangle object)
{
  objects.insert(std::pair<int, triangle>(next_index, object));

  next_index ++;

  return next_index-1;
}

bool world::remove_object(int id)
{
    objects.erase(id);

    return true;
}

bitmap world::rasterize()
{
    std::vector <ray> rays;
    bitmap picture = bitmap(screen_w, screen_h);

    for(int x = 0; x < screen_w; x++)
    {
        for(int y = 0; y < screen_h; y++)
        {
            vec3 screen = vec3(-1+2*(float)x/screen_w, -1+2*(float)y/screen_h, 0);
            vec3 trans =  camera - screen ;
            vec3 supp = camera;

            ray screen_ray = ray(trans, supp);
            rays.push_back(screen_ray);

            for(std::map <int, triangle>::iterator it = objects.begin(); it != objects.end(); ++it)
            {

                result<vec3> point = math::linalg::ray_plane_intersection(screen_ray, it->second);

                if(math::linalg::is_point_in_tris(point.unwrap(), it->second))

                {
                    picture.set_pixel(x, y, color(255, 255, 255)); //TODO: Change Color to Material
                }
            }
        }
    }

    return picture;
}
