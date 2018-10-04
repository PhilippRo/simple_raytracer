#include <linalg.h>
#include <vec3.h>
#include <result.h>

#include <array>
#include <iostream>

result<math::vector::vec3> math::linalg::ray_plane_intersection(ray mray,
       primitives::polygons::triangle mtris)
{
    float k = 0;

    vec3 norm_vec = mtris.get_norm();
    vec3 point_in_plane = mtris.get_support();

    vec3 w = point_in_plane - mray.get_support();

    if(dotp(mray.get_translation(), norm_vec) == 0)
    {
        return result<math::vector::vec3>();
    }else
    {
        k = dotp(w, norm_vec)/dotp(mray.get_translation(), norm_vec);
        vec3 vec_res = mray.get_support() + mray.get_translation()*k;

        return result<math::vector::vec3>{vec_res};
    }

}

bool math::linalg::is_point_in_tris(vec3 point, primitives::polygons::triangle mtris)
{
    vec3 ab = mtris.get_b() - mtris.get_a();
    vec3 bc = mtris.get_c() - mtris.get_b();
    vec3 ca = mtris.get_a() - mtris.get_c();
    vec3 cb = mtris.get_b() - mtris.get_c();
    vec3 ba = mtris.get_a() - mtris.get_b();
    vec3 ac = mtris.get_c() - mtris.get_a();

    vec3 ai = point - mtris.get_a();
    vec3 bi = point - mtris.get_b();
    vec3 ci = point - mtris.get_c();


    vec3 v = ab - cb*dotp(ab, cb)/dotp(cb, cb);
    vec3 u = bc - ac*dotp(bc, ac)/dotp(ac, ac);
    vec3 w = ca - ba*dotp(ca, ba)/dotp(ba, ba);

    float a = 1-dotp(v, ai)/dotp(v, ab);
    float b = 1-dotp(u,bi)/dotp(u, bc);
    float c = 1-dotp(w, ci)/dotp(w, ca);

    //std::cout << a << " " << b << " " << c << std::endl;

    if(a >= 0 && a <= 1 && b >= 0 && b <= 1 && c >= 0 && c <= 1)
    {
        return true;
    }else
    {
        return false;
    }

}

