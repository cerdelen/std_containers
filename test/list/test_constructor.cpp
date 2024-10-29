#include <gtest/gtest.h>
#include <list.hpp>

TEST(HelloTestm, BasicAssertions) {
    ft::list<int> a;
    EXPECT_EQ(0, a.size());
}

