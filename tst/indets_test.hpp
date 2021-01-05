#pragma once
#include <gtest/gtest.h>
#include "../src/indets.hpp"

class IndetsTest : public testing::Test
{
public:
  multinomial P1, P2;
  indet_lst I1, I2, I1res, I2res;
  indeterminate x, y, z;
  virtual void SetUp()
  {
    P1 = x*x - y;
    P2 = x*x*x - x + pow(x+y+z, 4);

    I1 = indets(P1);
    I2 = indets(P2);
    I1res = {x, y};
    I2res = {x, y, z};
  }

  virtual void TearDown()
  {
  }
};

TEST_F(IndetsTest, testIndets)
{ // GiNaC's sort only gaurantees an order at runtime
  EXPECT_EQ(I1res.sort(), I1);
  EXPECT_EQ(I2res.sort(), I2);
}
