
#include <linalg.h>

#include <vec3.h>
#include <result.h>

#include<array>


math::vector::vec3 math::linalg::solve_eqn_array_3(std::array<vec3, 4> vecs) {
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
        primitives::polygons::triangle mtri){
    auto collision = math::linalg::solve_eqn_array_3({mtri.get_a() - mtri.get_b(),
        mtri.get_a() - mtri.get_c(), vec3() - mray.get_translation(),
        mtri.get_a() - mray.get_support()});

    if (collision[0] >= 0.0 && collision[0] <= 1.0 && collision[1] >= 0.0
        && collision[1] <= 1.0) {
        auto vec_res = mray.get_support() + mray.get_translation() * collision[2];
        return result<math::vector::vec3>{vec_res};
    } else {
        return result<math::vector::vec3>();
    }
}
