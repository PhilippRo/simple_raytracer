#include <gtest/gtest.h>
#include <linalg.h>
#include <primitives.h>
#include <vec3.h>

using namespace math::vector;
using namespace math::linalg;
using namespace primitives::polygons;

const auto m_tri_1 = triangle(vec3(1.0, 0.0, 0.0), vec3(0.1,0.0,0.0), vec3(0.0,1.0,0.0));
const auto m_tri_2 = triangle(vec3(1.0, 0.0, 0.0), vec3(0.0,1.0,0.0), vec3(0.0,0.0,1.0));

// hits m_tri_1
const auto m_ray_1 = ray(vec3(0.1,0.0,-1.0), vec3(0.0,0.0,-1.0));
// hits m_tri_2
const auto m_ray_2 = ray(vec3(0.0,0.0,0.0), vec3(0.5,0.1, 0.5));

TEST(LinAlg, CollisionTest1){
    auto res = check_for_collision(m_ray_1, m_tri_1);
    ASSERT_TRUE(res.is_ok());
    ASSERT_EQ(res.unwrap(), vec3(0.1,0.0,0.0)) << res.unwrap().get_x() << " "
        << res.unwrap().get_y() << " " << res.unwrap().get_z() << " expected 0.1 0 0";
}

TEST(LinAlg, CollisionTest2){
    auto res = check_for_collision(m_ray_2, m_tri_2);
    ASSERT_TRUE(res.is_ok());
    ASSERT_EQ(res.unwrap(), vec3(0.5,0.1,0.5));
}

TEST(LinAlg, CollisionTest3){
    auto res = check_for_collision(m_ray_1, m_tri_2);
    ASSERT_TRUE(!res.is_ok());
}

TEST(LinAlg, SolveEqnArrayTest1)
{
    // define some vectors v, w, u, z
    vec3 v {1.0 ,0.0, 0.0};
    vec3 w {0.0, 1.0, 0.0};
    vec3 u {0.0, 0.0, 1.0};

    // define some constants
   float a = 1;
   float b = 3;
   float c = 2;

   auto result_vec = solve_eqn_array_3({v, w, u, v*a + w*b + u*c});
   ASSERT_EQ(result_vec, vec3(a,b,c)) << result_vec.to_str();
}

TEST(LinAlg, SolveEqnArrayTest2)
{
    // define some vectors v, w, u, z
    vec3 v {1.0 ,1.0, 0.0};
    vec3 w {0.0, 1.0, 1.0};
    vec3 u {0.0, 0.0, 1.0};

    // define some constants
   float a = 1;
   float b = 3;
   float c = 2;

   auto result_vec = solve_eqn_array_3({v, w, u, v*a + w*b + u*c});
   ASSERT_EQ(result_vec, vec3(a,b,c)) << result_vec.to_str();
}
