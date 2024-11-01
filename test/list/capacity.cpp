#include "ListTestBaseFixture.hpp"

class ListCapacityTests : public ListTestBaseFixture { };


TEST_F(ListCapacityTests, size_after_constructor) {
    EXPECT_EQ(mine.size(), orig.size());
}

TEST_F(ListCapacityTests, empty_after_constructor) {
    EXPECT_EQ(mine.empty(), orig.empty());
}

TEST_F(ListCapacityTests, capacities_after_single_push_front) {
    push_front(1);
    EXPECT_EQ(mine.size(), orig.size());
    EXPECT_EQ(mine.empty(), orig.empty());
}

TEST_F(ListCapacityTests, capacities_after_multiple_pushes_front) {
    push_front(2);
    push_front(1);
    EXPECT_EQ(mine.size(), orig.size());
    EXPECT_EQ(mine.empty(), orig.empty());
}

TEST_F(ListCapacityTests, capacities_after_single_push_back) {
    push_back(1);
    EXPECT_EQ(mine.size(), orig.size());
    EXPECT_EQ(mine.empty(), orig.empty());
}

TEST_F(ListCapacityTests, capacities_after_multiple_pushes_back) {
    push_back(1);
    push_back(2);
    EXPECT_EQ(mine.size(), orig.size());
    EXPECT_EQ(mine.empty(), orig.empty());
}

TEST_F(ListCapacityTests, capacities_after_mixed_pushes) {
    push_front(1);
    push_back(2);
    EXPECT_EQ(mine.size(), orig.size());
    EXPECT_EQ(mine.empty(), orig.empty());
}

TEST_F(ListCapacityTests, capacities_after_single_pop_front) {
    this->init_fill(3);
    pop_front();
    EXPECT_EQ(mine.size(), orig.size());
    EXPECT_EQ(mine.empty(), orig.empty());
}

TEST_F(ListCapacityTests, capacities_after_multiple_pops_front) {
    this->init_fill(3);
    pop_front();
    pop_front();
    EXPECT_EQ(mine.size(), orig.size());
    EXPECT_EQ(mine.empty(), orig.empty());
}

TEST_F(ListCapacityTests, capacities_after_single_pop_back) {
    this->init_fill(8);
    pop_back();
    EXPECT_EQ(mine.size(), orig.size());
    EXPECT_EQ(mine.empty(), orig.empty());
}

TEST_F(ListCapacityTests, capacities_after_multiple_pops_back) {
    this->init_fill(8);
    pop_back();
    pop_back();
    EXPECT_EQ(mine.size(), orig.size());
    EXPECT_EQ(mine.empty(), orig.empty());
}

TEST_F(ListCapacityTests, capacities_after_mixed_pops) {
    this->init_fill(8);
    pop_front();
    pop_back();
    EXPECT_EQ(mine.size(), orig.size());
    EXPECT_EQ(mine.empty(), orig.empty());
}

TEST_F(ListCapacityTests, capacities_after_clear) {
    this->init_fill(8);
    clear();
    EXPECT_EQ(mine.size(), orig.size());
    EXPECT_EQ(mine.empty(), orig.empty());
}

TEST_F(ListCapacityTests, capacities_after_single_reducing_resize) {
    this->init_fill(8);
    resize(3, 1);
    EXPECT_EQ(mine.size(), orig.size());
    EXPECT_EQ(mine.empty(), orig.empty());
}

TEST_F(ListCapacityTests, capacities_after_multiple_reducing_resize) {
    this->init_fill(8);
    resize(5, 1);
    resize(3, 1);
    EXPECT_EQ(mine.size(), orig.size());
    EXPECT_EQ(mine.empty(), orig.empty());
}

TEST_F(ListCapacityTests, capacities_after_single_expanding_resize) {
    this->init_fill(8);
    resize(10, 1);
    EXPECT_EQ(mine.size(), orig.size());
    EXPECT_EQ(mine.empty(), orig.empty());
}

TEST_F(ListCapacityTests, capacities_after_multiple_expanding_resize) {
    this->init_fill(8);
    resize(10, 1);
    resize(15, 1);
    EXPECT_EQ(mine.size(), orig.size());
    EXPECT_EQ(mine.empty(), orig.empty());
}

TEST_F(ListCapacityTests, capacities_after_multiple_mixed_resize) {
    this->init_fill(8);
    resize(10, 1);
    resize(5, 1);
    resize(15, 1);
    EXPECT_EQ(mine.size(), orig.size());
    EXPECT_EQ(mine.empty(), orig.empty());
}

