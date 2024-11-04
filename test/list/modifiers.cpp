#include "ListTestBaseFixture.hpp"

class ListModifiersTests : public ListTestBaseFixture { };

// clear
TEST_F(ListModifiersTests, clear_after_constructor) {
    clear();
    quick_capacity_check();
}

TEST_F(ListModifiersTests, clear_after_pushes) {
    init_fill(8);
    clear();
    quick_capacity_check();
    init_fill(8);
    clear();
    quick_capacity_check();
}

TEST_F(ListModifiersTests, clear_after_resize_to_zero) {
    init_fill(8);
    resize(0, 0);
    clear();
    quick_capacity_check();
}

TEST_F(ListModifiersTests, clear_after_expanding_resize) {
    init_fill(8);
    resize(12, 15);
    clear();
    quick_capacity_check();
}

TEST_F(ListModifiersTests, clear_after_decreasing_resize) {
    init_fill(8);
    resize(4, 15);
    clear();
    quick_capacity_check();
}

TEST_F(ListModifiersTests, clear_after_push_and_pop) {
    push_front(1);
    pop_back();
    clear();
    quick_capacity_check();
}

// insert
// 1, 2, 3
// for each insert into empty
//      at begin and at end     -- this is done
// for each insert into filled
//      at begin, in middle at end
//
//  for count and range 1 with empty count
//                      1 with single range/count
//                      1 with more than 1 range/count
TEST_F(ListModifiersTests, count_empty_insert_into_empty_at_begin) {
    mine.insert(mine.begin(), 0, 8);
    EXPECT_EQ(mine.size(), 0);
    EXPECT_EQ(mine.back(), 0);
    EXPECT_EQ(mine.front(), 0);
}

TEST_F(ListModifiersTests, single_insert_into_empty_at_begin) {
    mine.insert(mine.begin(), 8);
    EXPECT_EQ(mine.size(), 1);
    EXPECT_EQ(mine.back(), 8);
    EXPECT_EQ(mine.front(), 8);
}

TEST_F(ListModifiersTests, count_single_insert_into_empty_at_begin) {
    mine.insert(mine.begin(), 1, 8);
    EXPECT_EQ(mine.size(), 1);
    EXPECT_EQ(mine.back(), 8);
    EXPECT_EQ(mine.front(), 8);
}

TEST_F(ListModifiersTests, range_single_insert_into_empty_at_begin) {
    ft::list<int> other;
    other.push_back(1);
    mine.insert(mine.begin(), other.begin(), other.begin());
    EXPECT_EQ(mine.size(), 1);
    EXPECT_EQ(mine.front(), 1);
    EXPECT_EQ(mine.back(), 1);
}

TEST_F(ListModifiersTests, count_multiple_insert_into_empty_at_begin) {
    mine.insert(mine.begin(), 2, 8);
    EXPECT_EQ(mine.size(), 2);
    EXPECT_EQ(mine.back(), 8);
    EXPECT_EQ(mine.front(), 8);
}

TEST_F(ListModifiersTests, range_multiple_insert_into_empty_at_begin) {
    std::list<int> other;
    other.push_back(1);
    other.push_back(2);
    mine.insert(mine.begin(), other.begin(), other.begin());
    EXPECT_EQ(mine.size(), 2);
    EXPECT_EQ(mine.front(), 1);
    EXPECT_EQ(mine.back(), 2);
}

TEST_F(ListModifiersTests, count_empty_insert_into_empty_at_end) {
    mine.insert(mine.end(), 0, 8);
    EXPECT_EQ(mine.size(), 0);
    EXPECT_EQ(mine.back(), 0);
    EXPECT_EQ(mine.front(), 0);
}

TEST_F(ListModifiersTests, single_insert_into_empty_at_end_at_end) {
    mine.insert(mine.end(), 8);
    EXPECT_EQ(mine.size(), 1);
    EXPECT_EQ(mine.back(), 8);
    EXPECT_EQ(mine.front(), 8);
}

TEST_F(ListModifiersTests, count_single_insert_into_empty_at_end) {
    mine.insert(mine.end(), 1, 8);
    EXPECT_EQ(mine.size(), 1);
    EXPECT_EQ(mine.back(), 8);
    EXPECT_EQ(mine.front(), 8);
}

TEST_F(ListModifiersTests, range_single_insert_into_empty_at_end) {
    ft::list<int> other;
    other.push_back(1);
    mine.insert(mine.end(), other.begin(), other.begin());
    EXPECT_EQ(mine.size(), 1);
    EXPECT_EQ(mine.front(), 1);
    EXPECT_EQ(mine.back(), 1);
}

TEST_F(ListModifiersTests, count_multiple_insert_into_empty_at_end) {
    mine.insert(mine.end(), 2, 8);
    EXPECT_EQ(mine.size(), 2);
    EXPECT_EQ(mine.back(), 8);
    EXPECT_EQ(mine.front(), 8);
}

TEST_F(ListModifiersTests, range_multiple_insert_into_empty_at_end) {
    std::list<int> other;
    other.push_back(1);
    other.push_back(2);
    mine.insert(mine.end(), other.begin(), other.begin());
    EXPECT_EQ(mine.size(), 2);
    EXPECT_EQ(mine.front(), 1);
    EXPECT_EQ(mine.back(), 2);
}
// // erase
// TEST_F(ListModifiersTests, Name) {
// }
//
// // push_back
// TEST_F(ListModifiersTests, Name) {
// }
//
// // pop_back
// TEST_F(ListModifiersTests, Name) {
// }
//
// // push_front
// TEST_F(ListModifiersTests, Name) {
// }
//
// // pop_front
// TEST_F(ListModifiersTests, Name) {
// }

// resize
TEST_F(ListModifiersTests, resize_empty_to_zero) {
    resize(0, 0);
    quick_capacity_check();
}

TEST_F(ListModifiersTests, resize_filled_to_zero) {
    init_fill(8);
    resize(0, 0);
    quick_capacity_check();
    front_back_compare();
}

TEST_F(ListModifiersTests, resize_empty_to_bigger) {
    resize(16, 16);
    quick_capacity_check();
    front_back_compare();
}

TEST_F(ListModifiersTests, resize_filled_to_bigger) {
    init_fill(8);
    resize(16, 16);
    quick_capacity_check();
    front_back_compare();
}

TEST_F(ListModifiersTests, resize_empty_to_bigger_no_value_givven) {
    mine.resize(16);
    orig.resize(16);
    quick_capacity_check();
    front_back_compare();
}

TEST_F(ListModifiersTests, resize_filled_to_bigger_no_value_givven) {
    init_fill(8);
    mine.resize(16);
    orig.resize(16);
    quick_capacity_check();
    front_back_compare();
}

// // swap
// TEST_F(ListModifiersTests, Name) {
// }
//
