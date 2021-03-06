#pragma once
#include <gtest/gtest.h>
#include "../src/multinomial.hpp"

// A new one of these is created for each test
class MultinomialTest : public testing::Test
{
public:
  multinomial P;
  indeterminate x, y;
  bool ismX, ismP;

  virtual void SetUp()
  {
    x = indeterminate("x");
    y = indeterminate("y");
    P = multinomial(x*x*x + y*y*y*y + x*y);
    ismP = is_multinomial(multinomial(P));
    ismX = is_multinomial(sin(x));
  }

  virtual void TearDown()
  {
  }
};

TEST_F(MultinomialTest, testConstructor)
{
  EXPECT_EQ(x*x*x + y*y*y*y + x*y, P);
}

TEST_F(MultinomialTest, testIsMultinomial)
{
  EXPECT_EQ(true, ismP);
  EXPECT_EQ(false, ismX);
}
