#include <gtest/gtest.h>
#include "../src/ideal.hpp"

class IdealTest : public testing::Test
{
public:
  multinomial P1, P2, P3, P4, P5, P6;
  multinomial R1, R2, R3, R4, R5;
  ideal I1, I2, I3, I4, I5;
  indeterminate x, y, z;
  virtual void SetUp()
  {
    P1 = x^2 - y;
    P2 = x^3 - x;
    P3 = x^2 - z - 1;
    P4 = z^2 - y - 1;
    P5 = x^2 - y^2;
    P6 = x^3 - x+y^4;

    LT1 = leading_term(P1);
    LT2 = leading_term(P2);
    LT3 = leading_term(P3);
    LT4 = leading_term(P4);

    LM1 = leading_monomial(P1);
    LM2 = leading_monomial(P2);
    LM3 = leading_monomial(2*P3/3);
    LM4 = leading_monomial(-7*P4);

    RM1 = rem(P1, x-y);
    RM2 = rem(P2, x-y);

    R1 = reduce(x-x*y, {P1, P2});
    R2 = reduce(P5, {P1, P2, x-x*y});
    R3 = reduce(x, {x+y+z});
    R4 = reduce(x, {x+y^2+z});

    S1 = s_polynomial(P1, P2);
    S2 = s_polynomial(P1, S1);
    S3 = s_polynomial(P2, S1);
    S4 = s_polynomial(P3, P4);
    S5 = s_polynomial(P5, P6);
    // S6 = s_polynomial(P5, P6);

    I1 = {P1, P2};
    I2 = {x^2-2*(y^2), x*y - 3};
    I3 = {x + y, x^2 - 1, y^2 - 2*x};
    I4 = {x^2 + y^2 + z^2 - 1, x - z+2, z^2 - x*y};
    I5 = I1;
    buchbergers_algorithm(I1);
    buchbergers_algorithm(I2);
    buchbergers_algorithm(I3);
    buchbergers_algorithm(I4);
    // buchbergers_algorithm(I5, degree_reverse_lexicographical);
  }

  virtual void TearDown()
  {
  }
};

TEST_F(IdealTest, testLeadingTerm)
{
  EXPECT_EQ(x^2, LT1);
  EXPECT_EQ(x^3, LT2);
  EXPECT_EQ(x^2, LT3);
  EXPECT_EQ(-y, LT4);
}

TEST_F(IdealTest, testLeadingMonomial)
{
  EXPECT_EQ(x^2, LM1);
  EXPECT_EQ(x^3, LM2);
  EXPECT_EQ(x^2, LM3);
  EXPECT_EQ(y, LM4);
}

TEST_F(IdealTest, testRem)
{
  EXPECT_EQ(y^2-y, RM1);
  EXPECT_EQ(y^3-y, RM2);
}

TEST_F(IdealTest, testReduce)
{
  EXPECT_EQ(x-x*y, R1);
  EXPECT_EQ(y-y^2, R2);
  EXPECT_EQ(-y-z, R3);
  EXPECT_EQ(-y^2-z, R4);
}


TEST_F(IdealTest, testSPolynomial)
{
  EXPECT_EQ(x-x*y, S1);
  EXPECT_EQ(x^2-y^2, S2);
  EXPECT_EQ(x^3-x*y, S3);
  EXPECT_EQ(x^2*y - z^3 + x^2 - z^2, S4);
  EXPECT_EQ(-x*y^2 + x - y^4, S5);
  // EXPECT_EQ(-x*y^2 + x - y^4, S6); // degree_reverse_lexicographical
}

TEST_F(IdealTest, testBuchbergers_algorithm)
{
  EXPECT_EQ(ideal(x^2 - y, x*y - x, y^2 - y), I1);
  EXPECT_EQ(ideal(2*(y^4) - 9, 3*x - 2*(y^3)), I2);
  EXPECT_EQ(ideal(1), I3);
  EXPECT_EQ(ideal(12-28*z+27*(z^2)-12*(z^3)+3*(z^4), -6 + 4*y+11*z-6*(z^2)+3*(z^3),2+x-z), I4);
  // EXPECT_EQ(ideal(2*(y^3) - 3*x, x^2 - 2*(y^2), x*y - 3), I5);
}
