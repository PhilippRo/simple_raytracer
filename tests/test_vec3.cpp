#include <gtest/gtest.h>
#include <math.h>
#include <vec3.h>

using namespace math::vector;

const vec3 expected_vec_add = vec3(2, 2, 2);
const vec3 expected_vec_sub = vec3(0, 0, 0);
const vec3 expected_vec_mul = vec3(3, 3, 3);
const vec3 expected_vec_div = vec3(0.5, 0.5, 0.5);

const float expected_dot_product = 32;
const vec3 expected_cross_product = vec3(-3, 6, -3);

const float expected_vector_x = 1;
const float expected_vector_y = 1;
const float expected_vector_z = 1;

const float expected_norm = std::sqrt(33);

const vec3 expected_normalized_vector = vec3(2/std::sqrt(33), 2/std::sqrt(33), 5/std::sqrt(33));

const float test_scalar_mul = 3;
const float test_scalar_div = 2;

const vec3 test_vector = vec3(1, 1, 1);
const vec3 test_vector_normalization = vec3(2, 2, 5);

const vec3 vec_product_test_vector1 = vec3(1, 2, 3);
const vec3 vec_product_test_vector2 = vec3(4, 5, 6);

//Comparison TEST
TEST(Vector, ComparisonTest)
{
  EXPECT_EQ(test_vector, test_vector);
  EXPECT_NE(test_vector, expected_vec_add);
}

//Addition Test
TEST(Vector, AdditionTest)
{
    vec3 result = test_vector + test_vector;
    EXPECT_EQ(expected_vec_add, result);
}

//Subtraction TEST
TEST(Vector, SubtractionTest)
{
    vec3 result = test_vector - test_vector;
    EXPECT_EQ(expected_vec_sub, result);
}

//Scalar Multiplication Test
TEST(Vector, MultiplicationTest)
{
    vec3 result = test_vector*test_scalar_mul;
    EXPECT_EQ(expected_vec_mul, result);
}

//Scalar Division Test
TEST(Vector, DivisionTest)
{
    vec3 result = test_vector / test_scalar_div;
    EXPECT_EQ(expected_vec_div, result);
}

//Dot Product Test

TEST(Vector, DotProductTest)
{
  float result = dotp(vec_product_test_vector1, vec_product_test_vector2);
  EXPECT_EQ(expected_dot_product, result);
}

//Cross Product TEST

TEST(Vector, CrossProductTest)
{
  vec3 result = crossp(vec_product_test_vector1, vec_product_test_vector2);
  EXPECT_EQ(expected_cross_product, result);
}

//Get Components Test
TEST(Vector, GetComponents)
{
  float x = test_vector.get_x();
  float y = test_vector.get_y();
  float z = test_vector.get_z();

  EXPECT_EQ(expected_vector_x, x);
  EXPECT_EQ(expected_vector_y, y);
  EXPECT_EQ(expected_vector_z, z);
}

//Norm Test
TEST(Vector, GetNormTest)
{
    float norm = test_vector_normalization.get_norm();

    EXPECT_EQ(expected_norm, norm);
}

//Normalize Test
TEST(Vector, NormalizeTest)
{
    vec3 result = test_vector_normalization.normalize();

    EXPECT_EQ(expected_normalized_vector, result);
}
