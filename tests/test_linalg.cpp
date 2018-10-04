#include <gtest/gtest.h>
#include <linalg.h>
#include <primitives.h>
#include <vec3.h>

using namespace math::vector;
using namespace math::linalg;
using namespace primitives::polygons;

const auto m_tri_1 = triangle(vec3(1.0, 0.0, 0.0), vec3(0.1,0.0,0.0), vec3(0.0,1.0,0.0));
const auto m_tri_2 = triangle(vec3(1.0, 0.0, 0.0), vec3(0.0,0.0,0.0), vec3(0.5,1.0,0.0));

// hits m_tri_1
const auto m_ray_1 = ray(vec3(0.0,0.0,-1.0), vec3(0.1,0.0,-1.0));
// hits m_tri_2
const auto m_ray_2 = ray(vec3(0.5,0.1, 0.5), vec3(0.0,0.0,0.0));
//parallel to m_tri_2
const auto m_ray_3 = ray(vec3(0.5,0.1, 0.0), vec3(0.0,0.0,1.0));

TEST(LinAlg, IntersectionTest1){
    auto res = ray_plane_intersection(m_ray_1, m_tri_1);

    ASSERT_TRUE(res.is_ok());
    ASSERT_EQ(res.unwrap(), vec3(0.1,0.0,0.0));
}

TEST(LinAlg, IntersectionTest2){
    auto res = ray_plane_intersection(m_ray_3, m_tri_2);

    ASSERT_FALSE(res.is_ok());
}

TEST(LinAlg, CollisionTest1){
    auto res = ray_plane_intersection(m_ray_2, m_tri_2);

    ASSERT_TRUE(res.is_ok());
    ASSERT_TRUE(is_point_in_tris(res.unwrap(), m_tri_2));
}
