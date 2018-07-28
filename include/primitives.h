#pragma once

namespace prmitives{
  namespace polygons{


    class triangle{

    public:

      triangle();
      triangle(vec3 _a, vec3 _b, vec3_c);

      void set_points(vec3 _a, vec3 _b, vec3 _c);

      vec3 get_a();
      vec3 get_b();
      vec3 get_c();

    private:

      vec3 a, b, c;

    };
  }
}
