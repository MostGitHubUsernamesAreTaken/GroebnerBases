#pragma once
#include <gtest/gtest.h>
#include "../src/indets.hpp"

class IndetsTest : public testing::Test
{
public:
  multinomial P1, P2;
  indet_lst I1, I2;
  indeterminate x, y, z;
  virtual void SetUp()
  {
    P1 = pow(x, 2) - y;
    P2 = pow(x, 3) - x + pow(x+y+z, 4);

    I1 = indets(P1);
    I2 = indets(P2);
  }

  virtual void TearDown()
  {
  }
};

TEST_F(IndetsTest, testIndets)
{ // GiNaC's sort only gaurantees an order at runtime
  EXPECT_EQ(GiNaC::lst({x, y}).sort(), I1);
  EXPECT_EQ(GiNaC::lst({x, y, z}).sort(), I2);
}
