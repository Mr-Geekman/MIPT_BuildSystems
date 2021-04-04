#include "A/index.h"
#include "B/lib.h"

#include "tests.h"


TEST_F(ATestCase, AllTests) {
    ASSERT_EQ(TP::add_2(-100), -98);
    ASSERT_EQ(TP::add_2(-2), 0);
    ASSERT_EQ(TP::add_2(0), 2);
    ASSERT_EQ(TP::add_2(100), 102);
}

TEST_F(BTestCase, AllTests) {
    ASSERT_EQ(TP::add_3(-100), -97);
    ASSERT_EQ(TP::add_3(-3), 0);
    ASSERT_EQ(TP::add_3(0), 3);
    ASSERT_EQ(TP::add_3(100), 103);
}
