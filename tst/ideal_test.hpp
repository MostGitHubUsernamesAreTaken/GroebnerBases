#include <gtest/gtest.h>
#include "../src/ideal.hpp"

class IdealTest : public testing::Test
{
public:
  multinomial P1, P2, P3, P4, P5, P6, P7, P8;
  multinomial LT1, LT2, LT3, LT4, LT5, LT6;
  multinomial LM1, LM2, LM3, LM4;
  multinomial RM1, RM2, RM3;
  multinomial R1, R2, R3, R4;
  multinomial S1, S2, S3, S4, S5, S6;
  indeterminate x, y, z;
  virtual void SetUp()
  {
    x = indeterminate("x");
    y = indeterminate("y");
    z = indeterminate("z");

    P1 = x*x - y;
    P2 = x*x*x - x;
    P3 = x*x - z - 1;
    P4 = z*z - y - 1;
    P5 = x*x - y*y;
    P6 = x*x*x - x + y*y*y*y;
    P7 = 1;
    P8 = pow(x+y,6);

    LT1 = leading_term(P1);
    LT2 = leading_term(P2);
    LT3 = leading_term(P3);
    LT4 = leading_term(P4);
    LT5 = leading_term(P7);
    LT6 = leading_term(P8);

    LM1 = leading_monomial(P1);
    LM2 = leading_monomial(P2);
    LM3 = leading_monomial(2*P3/3);
    LM4 = leading_monomial(-7*P4);

    RM1 = rem(P1, x-y);
    RM2 = rem(P2, x-y);
    RM3 = rem(4, x-y);

    R1 = reduce(x-x*y, ideal({P1, P2}));
    R2 = reduce(P5, ideal({P1, P2, x-x*y}));
    R3 = reduce(x, ideal({x+y+z}));
    R4 = reduce(x, ideal({x+y*y+z}));

    S1 = s_polynomial(P1, P2);
    S2 = s_polynomial(P1, S1);
    S3 = s_polynomial(P2, S1);
    S4 = s_polynomial(P3, P4);
    S5 = s_polynomial(P5, P6);
    S6 = s_polynomial(P5, P6);
  }

  virtual void TearDown()
  {
  }
};

class BuchbergerTest : public testing::Test
{
public:
    multinomial P1, P2;
    ideal I1, I2, I3, I4, I5;
    indeterminate x, y, z;
    virtual void SetUp()
    {
        x = indeterminate("x");
        y = indeterminate("y");
        z = indeterminate("z");

        P1 = x*x - y;
        P2 = x*x*x - x;

        I1 = ideal({P1, P2});
        I2 = ideal({x*x - 2*y*y, x*y - 3});
        I3 = ideal({x + y, x*x - 1, y*y - 2*x});
        I4 = ideal({x*x + y*y + z*z - 1, x - z+2, z*z - x*y});
        I5 = I1;
        buchbergers_algorithm(I1);
        buchbergers_algorithm(I2);
        buchbergers_algorithm(I3);
        // buchbergers_algorithm(I4); // too slow to be a reasonable test
        // buchbergers_algorithm(I5, degree_reverse_lexicographical);
    }

    virtual void TearDown()
    {
    }
};

TEST_F(IdealTest, testLeadingTerm)
{
  EXPECT_EQ(x*x, LT1);
  EXPECT_EQ(x*x*x, LT2);
  EXPECT_EQ(x*x, LT3);
  EXPECT_EQ(-y, LT4);
  EXPECT_EQ(1, LT5);
  EXPECT_EQ(x*x*x*x*x*x, LT6);
}

TEST_F(IdealTest, testLeadingMonomial)
{
  EXPECT_EQ(x*x, LM1);
  EXPECT_EQ(x*x*x, LM2);
  EXPECT_EQ(x*x, LM3);
  EXPECT_EQ(y, LM4);
}

TEST_F(IdealTest, testRem)
{
  EXPECT_EQ(y*y - y, RM1);
  EXPECT_EQ(y*y*y - y, RM2);
  EXPECT_EQ(4, RM3);
}

TEST_F(IdealTest, testReduce)
{
  EXPECT_EQ(x - x*y, R1);
  EXPECT_EQ(y - y*y, R2);
  EXPECT_EQ(-y - z, R3);
  EXPECT_EQ(-y*y - z, R4);
}

TEST_F(IdealTest, testSPolynomial)
{
  EXPECT_EQ(x-x*y, S1);
  EXPECT_EQ(x*x - y*y, S2);
  EXPECT_EQ(x*x*x - x*y, S3);
  EXPECT_EQ(-y*z - y + x*x*z*z - x*x, S4);
  EXPECT_EQ(-x*y*y + x - y*y*y*y, S5);
  // EXPECT_EQ(-x*y*y + x - y*y*y*y, S6); // degree_reverse_lexicographical
}

TEST_F(BuchbergerTest, testBuchbergers_algorithm)
{
  EXPECT_EQ(ideal({x*x - y, x*y - x, y*y - y}), I1);
  EXPECT_EQ(ideal({x - 2*y*y*y/3, y*y*y*y - field_element(9, 2)}), I2);
  EXPECT_EQ(ideal({1}), I3);
  // EXPECT_EQ(ideal({12-28*z+27*z*z-12*z*z*z+3*z*z*z*z, -6 + 4*y+11*z-6*z*z+3*z*z*z,2+x-z}), I4);
  // EXPECT_EQ(ideal(2*(y^3) - 3*x, x^2 - 2*(y^2), x*y - 3), I5);
}
