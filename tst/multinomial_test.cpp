#include <gtest/gtest.h>
#include "../src/multinomial.h"

using namespace GiNaC;

// A new one of these is created for each test
class MultinomialTest : public testing::Test
{
public:
  multinomial P, Q;
  symbol a, b, x, y, z;

  virtual void SetUp()
  {
    a = symbol("a");
    b = symbol("b");
    x = symbol("x");
    y = symbol("y");
    z = symbol("z");
    // create a multinomial and make the constructor sort the variables into
    // lexicographical ordering
    P = multinomial(pow(x, 3) + pow(y, 4) + x*y, std::vector<symbol>({z, x, b, y, a}));
    Q = multinomial(pow(x, y), std::vector<symbol>({z}));
  }

  virtual void TearDown()
  {
  }
};

TEST_F(MultinomialTest, testConstructor)
{
  EXPECT_EQ(std::vector<symbol>({a, b, x, y, z}), P.vars());
  EXPECT_EQ(pow(x,3) + pow(y,4) + x*y, P.expr());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
