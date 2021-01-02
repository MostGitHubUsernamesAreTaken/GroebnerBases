#include <gtest/gtest.h>

#include "multinomial_test.hpp"
#include "indets_test.hpp"
#include "monomial_test.hpp"
#include "ideal_test.hpp"

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
