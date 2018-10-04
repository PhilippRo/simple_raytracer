#include<gtest/gtest.h>

#include <array>

#include<mat.h>

using namespace math;

TEST(Matrix, AccessTest){
    mat<2, int> m_mat{std::array<std::array<int,2>,2>{{{1,2},{3,4}}}};
    ASSERT_EQ(m_mat.at(0,0), 1);
    ASSERT_EQ(m_mat.at(0,1), 3);
    ASSERT_EQ(m_mat.at(1,0), 2);
    ASSERT_EQ(m_mat.at(1,1), 4);
}

TEST(Matrix, MatMulTest){
    mat<2, int> m_mat_a{std::array<std::array<int,2>,2>{{{1,2},{3,4}}}};
    mat<2, int> m_mat_b{std::array<std::array<int,2>,2>{{{1,1},{1,0}}}};
    auto res = m_mat_a * m_mat_b;

    ASSERT_EQ(res.at(0,0), 4);
    ASSERT_EQ(res.at(0,1), 1);
    ASSERT_EQ(res.at(1,0), 6);
    ASSERT_EQ(res.at(1,1), 2);
}
