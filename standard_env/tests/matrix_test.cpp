#include "matrix.h"
#include "gtest/gtest.h"

TEST(MatrixTest, ConstructorAndElementAccess) {
  Matrix m(2, 3);
  EXPECT_EQ(m[0][0], 0);
  EXPECT_EQ(m[1][2], 0);

  m[0][0] = 1;
  m[1][2] = 3;
  EXPECT_EQ(m[0][0], 1);
  EXPECT_EQ(m[1][2], 3);
}

TEST(MatrixTest, CopyConstructor) {
  Matrix m1(2, 2);
  m1[0][0] = 1;
  m1[1][1] = 2;

  Matrix m2 = m1;
  EXPECT_EQ(m2[0][0], 1);
  EXPECT_EQ(m2[1][1], 2);
}

// Test the output operator
TEST(MatrixTest, OutputOperator) {
  Matrix m(2, 2);
  m[0][0] = 1;
  m[0][1] = 2;
  m[1][0] = 3;
  m[1][1] = 4;

  std::stringstream ss;
  ss << m;
  std::string expected = "1 2 \n3 4 \n";
  EXPECT_EQ(ss.str(), expected);
}

// int main(int argc, char **argv)
// {
//     testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }
