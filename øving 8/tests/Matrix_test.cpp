#include "Matrix.h"
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

TEST(MatrixTest, OutputOperator) {
  Matrix m(2, 2);
  m[0][0] = 1;
  m[0][1] = 2;
  m[1][0] = 3;
  m[1][1] = 4;

  std::stringstream ss;
  ss << m;
  std::string expected = "1  2  \n3  4  \n";
  EXPECT_EQ(ss.str(), expected);
}

TEST(MatrixTest, CopyConstructor) {
  Matrix original(2, 3);
  original.set(0, 0, 1.0);
  original.set(0, 1, 2.0);
  original.set(0, 2, 3.0);
  original.set(1, 0, 4.0);
  original.set(1, 1, 5.0);
  original.set(1, 2, 6.0);

  Matrix copy = original;

  for (int r = 0; r < 2; r++) {
    for (int c = 0; c < 3; c++) {
      EXPECT_EQ(original.get(r, c), copy.get(r, c));
    }
  }
}

TEST(MatrixTest, CopyAssignmentOperator) {
  Matrix original(2, 3);
  original.set(0, 0, 1.0);
  original.set(0, 1, 2.0);
  original.set(0, 2, 3.0);
  original.set(1, 0, 4.0);
  original.set(1, 1, 5.0);
  original.set(1, 2, 6.0);

  Matrix copy(2, 3);
  copy = original;

  for (int r = 0; r < 2; r++) {
    for (int c = 0; c < 3; c++) {
      EXPECT_EQ(original.get(r, c), copy.get(r, c));
    }
  }
}

TEST(MatrixTest, PlusEqualsOperator) {
  // Opprett to matriser med samme størrelse
  Matrix mat1(2, 2);
  Matrix mat2(2, 2);

  // Initialiser matrisene
  mat1.set(0, 0, 1);
  mat1.set(0, 1, 2);
  mat1.set(1, 0, 3);
  mat1.set(1, 1, 4);

  mat2.set(0, 0, 5);
  mat2.set(0, 1, 6);
  mat2.set(1, 0, 7);
  mat2.set(1, 1, 8);

  // Legg sammen mat1 og mat2, og lagre resultatet i mat1
  mat1 += mat2;

  // Sjekk at mat1 nå inneholder summen av mat1 og mat2
  EXPECT_EQ(mat1.get(0, 0), 6);
  EXPECT_EQ(mat1.get(0, 1), 8);
  EXPECT_EQ(mat1.get(1, 0), 10);
  EXPECT_EQ(mat1.get(1, 1), 12);
}

TEST(MatrixTest, MinusEqualsOperator) {
  Matrix mat1(2, 2);
  Matrix mat2(2, 2);

  mat1.set(0, 0, 5);
  mat1.set(0, 1, 7);
  mat1.set(1, 0, 9);
  mat1.set(1, 1, 11);

  mat2.set(0, 0, 1);
  mat2.set(0, 1, 2);
  mat2.set(1, 0, 3);
  mat2.set(1, 1, 4);

  mat1 -= mat2;

  EXPECT_EQ(mat1.get(0, 0), 4);
  EXPECT_EQ(mat1.get(0, 1), 5);
  EXPECT_EQ(mat1.get(1, 0), 6);
  EXPECT_EQ(mat1.get(1, 1), 7);
}

TEST(MatrixTest, MinusOperator) {
  Matrix mat1(2, 2);
  Matrix mat2(2, 2);

  mat1.set(0, 0, 5);
  mat1.set(0, 1, 7);
  mat1.set(1, 0, 9);
  mat1.set(1, 1, 11);

  mat2.set(0, 0, 1);
  mat2.set(0, 1, 2);
  mat2.set(1, 0, 3);
  mat2.set(1, 1, 4);

  Matrix result = mat1 - mat2;

  EXPECT_EQ(result.get(0, 0), 4);
  EXPECT_EQ(result.get(0, 1), 5);
  EXPECT_EQ(result.get(1, 0), 6);
  EXPECT_EQ(result.get(1, 1), 7);
}

TEST(MatrixTest, TimesEqualsOperator) {
  Matrix mat1(2, 2);
  Matrix mat2(2, 2);

  mat1.set(0, 0, 1);
  mat1.set(0, 1, 2);
  mat1.set(1, 0, 3);
  mat1.set(1, 1, 4);

  mat2.set(0, 0, 5);
  mat2.set(0, 1, 6);
  mat2.set(1, 0, 7);
  mat2.set(1, 1, 8);

  mat1 *= mat2;

  EXPECT_EQ(mat1.get(0, 0), 5);
  EXPECT_EQ(mat1.get(0, 1), 12);
  EXPECT_EQ(mat1.get(1, 0), 21);
  EXPECT_EQ(mat1.get(1, 1), 32);
}

TEST(MatrixTest, TimesOperator) {
  Matrix mat1(2, 2);
  Matrix mat2(2, 2);

  mat1.set(0, 0, 1);
  mat1.set(0, 1, 2);
  mat1.set(1, 0, 3);
  mat1.set(1, 1, 4);

  mat2.set(0, 0, 5);
  mat2.set(0, 1, 6);
  mat2.set(1, 0, 7);
  mat2.set(1, 1, 8);

  Matrix result = mat1 * mat2;

  EXPECT_EQ(result.get(0, 0), 5);
  EXPECT_EQ(result.get(0, 1), 12);
  EXPECT_EQ(result.get(1, 0), 21);
  EXPECT_EQ(result.get(1, 1), 32);
}

// int main(int argc, char **argv)
// {
//     testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }
