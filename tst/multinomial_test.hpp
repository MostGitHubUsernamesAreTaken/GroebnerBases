#pragma once 
#include <gtest/gtest.h>
#include "../src/multinomial.hpp"

using namespace GiNaC;

// A new one of these is created for each test
class MultinomialTest : public testing::Test
{
public:
  multinomial P, Q, P1, P2;
  symbol x, y;
  ex X;
  bool ismX, ismP;

  virtual void SetUp()
  {
    x = symbol("x");
    y = symbol("y");
    // create a multinomial and make the constructor sort the variables into
    // lexicographical ordering
    P = multinomial(pow(x, 3) + pow(y, 4) + x*y);
    ismP = is_multinomial(multinomial(pow(x, 3) + pow(y, 4) + x*y));
    ismX = is_multinomial(sin(x));
  }

  virtual void TearDown()
  {
  }
};

TEST_F(MultinomialTest, testConstructor)
{
  EXPECT_EQ(pow(x,3) + pow(y,4) + x*y, P);
}

TEST_F(MultinomialTest, testIsMultinomial)
{
  EXPECT_EQ(true, ismP);
  EXPECT_EQ(false, ismX);
}
