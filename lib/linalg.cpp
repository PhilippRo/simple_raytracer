#include <linalg.h>

#include <vec3.h>
#include <result.h>

#include<array>
#include <iostream>


math::vector::vec3 math::linalg::solve_eqn_array_3(std::array<vec3, 4> vecs)
{
    for (int j = 0; j < 3; j++){
        for (int i = 0; i < 3; i++) {
            if (i == j) {
                continue;
            } else {
                float ratio = vecs[i][j] / vecs[i][i];
                for (int k = 0; k < 4; k++){
                    vecs[k][j] -= ratio * vecs[k][i];
                }
            }
        }
    }

    for(int i = 0; i < 3; i++){
        vecs[3][i] = vecs[3][i]/vecs[i][i];
    }
    return vecs[3];
}

result<math::vector::vec3> math::linalg::check_for_collision(ray mray,
        primitives::polygons::triangle mtri)
{
    auto collision = math::linalg::solve_eqn_array_3({mtri.get_a() - mtri.get_b(),
        mtri.get_a() - mtri.get_c(), vec3() - mray.get_translation(),
        mray.get_support() - mtri.get_a() });

    // calculate the unit vectors of the triangle. This is vital to calculate a
    // proper projection on the side of the triangle, to check if the vector is
    // actually on the trianngle
    auto unit_vector_a_b = (mtri.get_b() - mtri.get_a()).normalize();
    auto unit_vector_a_c = (mtri.get_c() - mtri.get_a()).normalize();
    auto unit_vector_b_c = (mtri.get_c() - mtri.get_b()).normalize();
    auto vec_res = mray.get_support() + mray.get_translation() * collision[2];

    // calculate projections
    auto dotp_unit_a_b_res = dotp(unit_vector_a_b, vec_res);
    auto dotp_unit_a_c_res = dotp(unit_vector_a_c, vec_res);
    auto dotp_unit_b_c_res = dotp(unit_vector_b_c, vec_res);

    if (
        dotp_unit_a_b_res >= dotp(unit_vector_a_b, mtri.get_a()) &&
        dotp_unit_a_b_res <= dotp(unit_vector_a_b, mtri.get_b()) &&
        dotp_unit_a_c_res >= dotp(unit_vector_a_c, mtri.get_a()) &&
        dotp_unit_a_c_res <= dotp(unit_vector_a_c, mtri.get_c()) &&
        dotp_unit_b_c_res >= dotp(unit_vector_b_c, mtri.get_b()) &&
        dotp_unit_b_c_res <= dotp(unit_vector_b_c, mtri.get_c())) {
        return result<math::vector::vec3>{vec_res};
    } else {
        return result<math::vector::vec3>();
    }
}

result<math::vector::vec3> math::linalg::ray_plane_intersection(ray mray,
       primitives::polygons::triangle mtris)
{
    float k = 0;

    vec3 norm_vec = crossp(mtris.get_b() - mtris.get_a(), mtris.get_c() - mtris.get_a());
    vec3 point_in_plane = mtris.get_a();

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
    vec3 cb = mtris.get_b() - mtris.get_c();
    vec3 ac = mtris.get_c() - mtris.get_a();
    vec3 bc = mtris.get_c() - mtris.get_b();
    vec3 ai = point - mtris.get_a();
    vec3 bi = point - mtris.get_b();


    vec3 v = ab - cb*dotp(ab, cb)/dotp(cb, cb);
    vec3 u = bc - ac*dotp(bc, ac)/dotp(ac, ac);

    float a = 1-dotp(v, ai)/dotp(v, ab);
    float b = 1-dotp(u,bi)/dotp(u, bc);

    std::cout << a << " " << b << std::endl;

    if(a >= 0 && a <= 1 && b >= 0 && b <= 1)
    {
        return true;
    }else
    {
        return false;
    }

}

