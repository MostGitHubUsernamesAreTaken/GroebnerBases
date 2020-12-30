#include <gtest/gtest.h>
#include "../src/multinomial.hpp"

using namespace GiNaC;

// A new one of these is created for each test
class MultinomialTest : public testing::Test
{
public:
  multinomial P, Q, P1, P2;
  multinomial S1, S2, S3, S4, S5, S6;
  symbol a, b, x, y, z;
  std::vector<symbol> P_vars{z, x, b, y, a}, sorted_P_vars{a,b,x,y,z};

  virtual void SetUp()
  {
    a = symbol("a");
    b = symbol("b");
    x = symbol("x");
    y = symbol("y");
    z = symbol("z");
    // create a multinomial and make the constructor sort the variables into
    // lexicographical ordering
    P = multinomial(pow(x, 3) + pow(y, 4) + x*y, P_vars);


    P1 = x^2 - y;
    P2 = x^3 - x;
    S1 = s_polynomial(P1, P2, lexicographical);
    S2 = s_polynomial(P1, S1, lexicographical);
    S3 = s_polynomial(P2, S1, lexicographical);
    S4 = s_polynomial(x^2 - z - 1, z^2 - y - 1, lexicographical);
    S5 = s_polynomial(x^2-y^2, x^3-x+y^4, lexicographical);
    S6 = s_polynomial(x^2-y^2, x^3-x+y^4, degree_reverse_lexicographical);
  }

  virtual void TearDown()
  {
  }
};

TEST_F(MultinomialTest, testConstructor)
{
  EXPECT_EQ(std::vector<symbol>(), Q.vars());
  EXPECT_EQ(0, Q.expr());
  EXPECT_EQ(sorted_P_vars, P.vars());
  EXPECT_EQ(pow(x,3) + pow(y,4) + x*y, P.expr());
  EXPECT_THROW(multinomial(pow(x, y), {z}), std::domain_error);
}

TEST_F(MultinomialTest, testMultiplicationOverload)
{
  EXPECT_EQ(2*pow(x,3) + 2*pow(y,4) + 2*x*y, (P*2).expr());
  EXPECT_EQ(sorted_P_vars, (P*2).vars());
}


TEST_F(MultinomialTest, testSPolynomial)
{
  EXPECT_EQ(x-x*y, S1);
  EXPECT_EQ(x^2-y^2, S2);
  EXPECT_EQ(x^3-x*y, S3);
  EXPECT_EQ(x^2*y - z^3 + x^2 - z^2, S4);
  EXPECT_EQ(-x*y^2 + x - y^4, S5);
  EXPECT_EQ(-x*y^2 + x - y^4, S6);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
