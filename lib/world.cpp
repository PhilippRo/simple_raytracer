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

bool world::manipulate_object(int id, int mode, float param)
{
    if(mode == 1 || mode == 2 || mode == 3)
    {
        vec3 a = objects.at(id).get_a();
        vec3 b = objects.at(id).get_b();
        vec3 c = objects.at(id).get_c();

        vec3 offset = vec3();
        offset[mode] = param;

        objects.at(id).set_points(a + offset, b + offset, c + offset);
        return true;
    }else
    {
        return false;
    }
}

bool world::remove_object(int id)
{
    objects.erase(id);

    return true;
}

bitmap world::rasterize()
{
    std::vector <ray> rays;
    bitmap picture{screen_w, screen_h};

    vec3 supp = camera;

    for(int x = 0; x < picture.get_width(); x++)
    {
        for(int y = 0; y < picture.get_height(); y++)
        {
            vec3 screen = vec3(-1+2*(float)x/screen_w, -1+2*(float)y/screen_h, 0);
            vec3 trans =  camera - screen ;

            ray screen_ray = ray(trans, supp);
            rays.push_back(screen_ray);

            for(std::map <int, triangle>::iterator it = objects.begin(); it != objects.end(); ++it)
            {

                result<vec3> point = math::linalg::ray_plane_intersection(screen_ray, it->second);

                if(point.is_ok())
                {
                    if(math::linalg::is_point_in_tris(point.unwrap(), it->second))

                    {
                        picture.set_pixel(x, y, it->second.get_material().get_color()); /// \todo Change Color to Material
                    }
                }
            }
        }
    }

    return picture;
}
