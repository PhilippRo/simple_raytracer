#include <linalg.h>

#include <vec3.h>
#include <result.h>

#include<array>


math::vector::vec3 math::linalg::solve_eqn_array_3(std::array<vec3, 4> vecs)
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; i < 3; i++){
            if (i == j) {
                continue;
            } else {
                float ratio = vecs[i][j] / vecs[i][i];
                for (int k = 0; k < 4; k++){
                    if (i == k ) {
                        continue;
                    } else{
                        vecs[k][j] += ratio * vecs[k][i];
                    }
                }
            }
        }
    }
    return vecs[3];
}

result<math::vector::vec3> math::linalg::check_for_collision(ray mray,
        primitives::polygons::triangle mtri)
{
    auto collision = math::linalg::solve_eqn_array_3({mtri.get_a() - mtri.get_b(),
        mtri.get_a() - mtri.get_c(), vec3() - mray.get_translation(),
        mtri.get_a() - mray.get_support()});

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
