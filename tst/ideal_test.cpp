#include <gtest/gtest.h>
#include "../src/ideal.hpp"

class IdealTest : public testing::Test
{
public:
  multinomial P1, P2;
  ideal I1, I2, I3, I4, I5;
  indeterminate x, y, z;
  virtual void SetUp()
  {

    P1 = x^2 - y;
    P2 = x^3 - x;
    S1 = s_polynomial(P1, P2, lexicographical);
    S2 = s_polynomial(P1, S1, lexicographical);
    S3 = s_polynomial(P2, S1, lexicographical);
    S4 = s_polynomial(x^2 - z - 1, z^2 - y - 1, lexicographical);
    S5 = s_polynomial(x^2-y^2, x^3-x+y^4, lexicographical);
    S6 = s_polynomial(x^2-y^2, x^3-x+y^4, degree_reverse_lexicographical);

    I1 = {x^2 - y, x^3 - x};
    I2 = {x^2-2*(y^2), x*y - 3};
    I3 = {x + y, x^2 - 1, y^2 - 2*x};
    I4 = {x^2 + y^2 + z^2 - 1, x - z+2, z^2 - x*y};
    I5 = I1;
    buchbergers_algorithm(I1);
    buchbergers_algorithm(I2);
    buchbergers_algorithm(I3);
    buchbergers_algorithm(I4);
    buchbergers_algorithm(I5, degree_reverse_lexicographical);
  }

  virtual void TearDown()
  {
  }
};

TEST_F(IdealTest, testSPolynomial)
{
  EXPECT_EQ(x-x*y, S1);
  EXPECT_EQ(x^2-y^2, S2);
  EXPECT_EQ(x^3-x*y, S3);
  EXPECT_EQ(x^2*y - z^3 + x^2 - z^2, S4);
  EXPECT_EQ(-x*y^2 + x - y^4, S5);
  EXPECT_EQ(-x*y^2 + x - y^4, S6);
}

TEST_F(IdealTest, testBuchbergers_algorithm)
{
  EXPECT_EQ(ideal(x^2 - y, x*y - x, y^2 - y), I1);
  EXPECT_EQ(ideal(2*(y^4) - 9, 3*x - 2*(y^3)), I2);
  EXPECT_EQ(ideal(1), I3);
  EXPECT_EQ(ideal(12-28*z+27*(z^2)-12*(z^3)+3*(z^4), -6 + 4*y+11*z-6*(z^2)+3*(z^3),2+x-z), I4);
  EXPECT_EQ(ideal(2*(y^3) - 3*x, x^2 - 2*(y^2), x*y - 3), I5);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
