#pragma once

#include <gtest/gtest.h>
#include "../src/monomial.hpp"

class MonomialTest : public testing::Test
{
public:
  multinomial P1, P2;
  indeterminate x, y, z;
  bool ism1, ism2, ism3, ism4;
  bool l1, l2, l3, l4, l5, l6, l7, l8;
  virtual void SetUp()
  {
    x = indeterminate("x");
    y = indeterminate("y");
    z = indeterminate("z");

    P1 = x*x - y;
    P2 = x*x*x - x + pow(x+y+z, 4);

    ism1 = is_monomial(P1);
    ism2 = is_monomial(7*x);
    ism3 = is_monomial(4*pow(x,3)*y*z);
    ism4 = is_monomial(pow(x,3)*y*z + z);

    l1 = lexicographical(x, y);
    l2 = lexicographical(z, z);
    l3 = lexicographical(x, pow(y,3));
    l4 = lexicographical(x*y*z, pow(x, 2)*y);
    l5 = lexicographical(pow(x, 4), x);
    l6 = lexicographical(pow(x, 4), 4);
    l7 = lexicographical(5, 4*x);
    l8 = lexicographical(5, 4);
  }

  virtual void TearDown()
  {
  }
};

TEST_F(MonomialTest, testIsMonomial)
{
  EXPECT_EQ(false, ism1);
  EXPECT_EQ(true, ism2);
  EXPECT_EQ(true, ism3);
  EXPECT_EQ(false, ism4);
}

TEST_F(MonomialTest, testLexicographical)
{
  EXPECT_EQ(true, l1);
  EXPECT_EQ(false, l2);
  EXPECT_EQ(true, l3);
  EXPECT_EQ(false, l4); // is sporadic
  EXPECT_EQ(true, l5);
  EXPECT_EQ(true, l6);
  EXPECT_EQ(false, l7);
  EXPECT_EQ(true, l8);
}
