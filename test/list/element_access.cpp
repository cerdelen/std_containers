#include "ListTestBaseFixture.hpp"

class ListElementAccessTests : public ListTestBaseFixture { };

TEST_F(ListElementAccessTests, single_front_after_single_push_front) {
    push_front(123);
    EXPECT_EQ(mine.front(), orig.front());
}

TEST_F(ListElementAccessTests, single_front_after_multiple_push_front) {
    push_front(123);
    push_front(124);
    EXPECT_EQ(mine.front(), orig.front());
}

TEST_F(ListElementAccessTests, single_front_after_single_push_back) {
    push_back(123);
    EXPECT_EQ(mine.front(), orig.front());
}

TEST_F(ListElementAccessTests, single_front_after_multiple_push_back) {
    push_back(123);
    push_back(124);
    EXPECT_EQ(mine.front(), orig.front());
}

TEST_F(ListElementAccessTests, single_front_after_multiple_mixed_push) {
    push_back(123);
    push_front(124);
    EXPECT_EQ(mine.front(), orig.front());
}

TEST_F(ListElementAccessTests, single_back_after_single_push_front) {
    push_front(123);
    EXPECT_EQ(mine.back(), orig.back());
}

TEST_F(ListElementAccessTests, single_back_after_multiple_push_front) {
    push_front(123);
    push_front(124);
    EXPECT_EQ(mine.back(), orig.back());
}

TEST_F(ListElementAccessTests, single_back_after_single_push_back) {
    push_back(123);
    EXPECT_EQ(mine.back(), orig.back());
}

TEST_F(ListElementAccessTests, single_back_after_multiple_push_back) {
    push_back(123);
    push_back(124);
    EXPECT_EQ(mine.back(), orig.back());
}

TEST_F(ListElementAccessTests, single_back_after_multiple_mixed_push) {
    push_back(123);
    push_front(124);
    EXPECT_EQ(mine.back(), orig.back());
}

// Mixed
TEST_F(ListElementAccessTests, mixed_front_back_after_reducing_resize) {
    this->init_fill(8);
    resize(5, 1);
    EXPECT_EQ(mine.front(), orig.front());
    EXPECT_EQ(mine.back(), orig.back());
}

TEST_F(ListElementAccessTests, mixed_front_back_after_expanding_resize) {
    this->init_fill(8);
    resize(15, 1);
    EXPECT_EQ(mine.front(), orig.front());
    EXPECT_EQ(mine.back(), orig.back());
}

TEST_F(ListElementAccessTests, mixed_front_back_after_mixed_resize) {
    this->init_fill(8);
    resize(10, 1);
    resize(5, 1);
    resize(15, 1);
    EXPECT_EQ(mine.front(), orig.front());
    EXPECT_EQ(mine.back(), orig.back());
}

