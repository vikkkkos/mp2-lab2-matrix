#include "pch.h"
#include "../sample_utmatrix/utmatrix.h"



TEST(TMatrix, can_create_matrix_with_positive_length)
{
    ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
    ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
    ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
    TMatrix<int> m(5);

    ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
    TMatrix<int> m(2), k = m;

    EXPECT_EQ(m, k);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
    TMatrix<int> m(5), k(m);

    k[1][1] = 0;

    EXPECT_EQ(m, k);
}

TEST(TMatrix, can_get_size)
{
    TMatrix<int> m(5);

    EXPECT_EQ(m.GetSize(), 5);
}

TEST(TMatrix, can_set_and_get_element)
{
    TMatrix<int> m(5);

    m[1][1] = 5;
    m[1][2] = 10;

    EXPECT_EQ(m[1][1], 5);
    EXPECT_EQ(m[1][2], 10);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
    TMatrix<int> m(5);

    ASSERT_ANY_THROW(m[-1][1] = 5;);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
    TMatrix<int> m(5);

    ASSERT_ANY_THROW(m[5][5] = 5;);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
    TMatrix<int> m(5);

    m[2][2] = 4;
    m[1][1] = 5;

    m = m;

    EXPECT_EQ(m[2][2], 4);
    EXPECT_EQ(m[1][1], 5);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
    TMatrix<int> m(5), m2(5);

    m[2][2] = 4;
    m[1][1] = 5;

    m2 = m;

    EXPECT_EQ(m2[2][2], 4);
    EXPECT_EQ(m2[1][1], 5);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
    TMatrix<int> m(5), m2(10);

    m2 = m;

    EXPECT_EQ(m2.GetSize(), 5);
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
    TMatrix<int> m(5), m2(10);

    m[2][2] = 4;
    m[1][1] = 5;

    m2 = m;

    EXPECT_EQ(m2[2][2], 4);
    EXPECT_EQ(m2[1][1], 5);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
    TMatrix<int> m(5), m2(7);

    m[2][2] = 4;
    m[1][1] = 5;
    m2 = m;
    EXPECT_TRUE(m2 == m);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
    TMatrix<int> m(5);

    EXPECT_TRUE(m == m);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
    TMatrix<int> m(2), m2(3);
    EXPECT_FALSE(m == m2);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
    TMatrix<int> m1(2), m2(2), m3(3);

    m1[0][0] = 2;
    m1[1][1] = 3;
    m1[0][1] = 4;
    m2[1][1] = 2;
    m2[0][0] = 3;
    m2[0][1] = 4;

    m3 = m2 + m1;

    EXPECT_EQ(m3[0][0], 5);
    EXPECT_EQ(m3[1][1], 5);
    EXPECT_EQ(m3[0][1], 8);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
    TMatrix<int> m1(3), m2(2);

    m1[0][0] = 2;
    m1[1][1] = 3;
    m1[0][1] = 4;
    m2[1][1] = 2;
    m2[0][0] = 3;
    m2[0][1] = 4;

    ASSERT_ANY_THROW(m2 + m1);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
    TMatrix<int> m1(2), m2(2), m3(3);

    m1[0][0] = 3;
    m1[1][1] = 3;
    m1[0][1] = 4;
    m2[1][1] = 2;
    m2[0][0] = 3;
    m2[0][1] = 4;

    m3 = m2 - m1;

    EXPECT_EQ(m3[0][0], 0);
    EXPECT_EQ(m3[1][1], -1);
    EXPECT_EQ(m3[0][1], 0);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
    TMatrix<int> m1(3), m2(2);

    m1[0][0] = 2;
    m1[1][1] = 3;
    m1[0][1] = 4;
    m2[1][1] = 2;
    m2[0][0] = 3;
    m2[0][1] = 4;

    ASSERT_ANY_THROW(m2 - m1);
}