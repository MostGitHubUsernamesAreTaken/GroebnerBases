#include <gtest/gtest.h>
#include "../src/multinomial.h"

using namespace GiNaC;

// A new one of these is created for each test
class MultinomialTest : public testing::Test
{
public:
  multinomial P, Q;
  symbol a, b, x, y, z;
  std::vector<symbol> P_vars{z, x, b, y, a}, sorted_P_vars{a,b,x,y,z};
  std::vector<symbol> Q_vars{z};

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
  }

  virtual void TearDown()
  {
  }
};

TEST_F(MultinomialTest, testConstructor)
{
  EXPECT_EQ(sorted_P_vars, P.vars());
  EXPECT_EQ(pow(x,3) + pow(y,4) + x*y, P.expr());
  EXPECT_THROW(multinomial(pow(x, y), Q_vars), std::domain_error);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
