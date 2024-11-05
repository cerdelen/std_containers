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

// Insert

TEST_F(ListModifiersTests, single_insert_into_empty_at_begin) {
    ft::list<int>::iterator pos = mine.begin();
    ft::list<int>::iterator ret = mine.insert(pos, 8);
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 8);
    EXPECT_TRUE(it == mine.end());
    EXPECT_EQ(*ret, 8);
    EXPECT_TRUE(++pos == ret);
}

TEST_F(ListModifiersTests, single_insert_into_empty_at_end) {
    ft::list<int>::iterator pos = mine.end();
    ft::list<int>::iterator ret = mine.insert(pos, 8);
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 8);
    EXPECT_TRUE(it == mine.end());
    EXPECT_EQ(*ret, 8);
    EXPECT_TRUE(++pos == ret);
}

TEST_F(ListModifiersTests, single_insert_into_filled_at_begin) {
    mine.push_back(2);
    mine.push_back(3);
    ft::list<int>::iterator pos = mine.begin();
    ft::list<int>::iterator ret = mine.insert(pos, 1);
    ft::list<int>::iterator it = mine.begin();

    EXPECT_EQ(*it, 1);
    it++;
    EXPECT_EQ(*it, 2);
    it++;
    EXPECT_EQ(*it, 3);
    it++;
    EXPECT_TRUE(it == mine.end());
    EXPECT_EQ(*ret, 1);
    EXPECT_TRUE(++pos == ret);

    mine.print();
}

TEST_F(ListModifiersTests, single_insert_into_filled_in_the_middle) {
    mine.push_back(1);
    mine.push_back(3);
    ft::list<int>::iterator pos = mine.begin();
    pos++;
    ft::list<int>::iterator ret = mine.insert(pos, 2);
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 3);
    EXPECT_TRUE(it == mine.end());
    EXPECT_EQ(*ret, 2);
    EXPECT_TRUE(++pos == ret);
    mine.print();
}

TEST_F(ListModifiersTests, single_insert_into_filled_at_end) {
    mine.push_back(1);
    mine.push_back(2);
    ft::list<int>::iterator pos = mine.end();
    ft::list<int>::iterator ret = mine.insert(pos, 3);
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 3);
    EXPECT_TRUE(it == mine.end());
    EXPECT_EQ(*ret, 3);
    EXPECT_TRUE(++pos == ret);
    std::cout << "ret " << *ret << std::endl;
    std::cout << "pos " << *pos << std::endl;
    mine.print();
}

TEST_F(ListModifiersTests, count_empty_insert_into_empty_at_begin) {
    ft::list<int>::iterator pos = mine.begin();
    ft::list<int>::iterator ret = mine.insert(pos, 0, 8);
    ft::list<int>::iterator it = mine.begin();
    EXPECT_TRUE(it == mine.end());
    EXPECT_TRUE(ret == pos);
}

TEST_F(ListModifiersTests, count_empty_insert_into_empty_at_end) {
    ft::list<int>::iterator pos = mine.end();
    ft::list<int>::iterator ret = mine.insert(pos, 0, 8);
    ft::list<int>::iterator it = mine.begin();
    EXPECT_TRUE(it == mine.end());
    EXPECT_TRUE(ret == pos);
}

TEST_F(ListModifiersTests, count_empty_insert_into_filled_at_begin) {
    ft::list<int>::iterator pos = mine.begin();
    mine.push_back(1);
    mine.push_back(2);
    ft::list<int>::iterator ret = mine.insert(pos, 0, 2);
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_TRUE(it == mine.end());
    EXPECT_TRUE(ret == pos);
}

TEST_F(ListModifiersTests, count_empty_insert_into_filled_in_the_middle) {
    ft::list<int>::iterator pos = mine.begin();
    mine.push_back(1);
    mine.push_back(2);
    pos++;
    ft::list<int>::iterator ret = mine.insert(pos, 0, 2);
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_TRUE(it == mine.end());
    EXPECT_TRUE(ret == pos);
}

TEST_F(ListModifiersTests, count_empty_insert_into_filled_at_end) {
    ft::list<int>::iterator pos = mine.end();
    mine.push_back(1);
    mine.push_back(2);
    ft::list<int>::iterator ret = mine.insert(pos, 0, 2);
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_TRUE(it == mine.end());
    EXPECT_TRUE(ret == pos);
}

TEST_F(ListModifiersTests, count_single_insert_into_empty_at_begin) {
    ft::list<int>::iterator pos = mine.begin();
    ft::list<int>::iterator ret = mine.insert(pos, 1, 8);
    EXPECT_EQ(mine.size(), 1);
    EXPECT_EQ(mine.back(), 8);
    EXPECT_EQ(mine.front(), 8);
    EXPECT_TRUE(ret == mine.end());
}

TEST_F(ListModifiersTests, count_single_insert_into_empty_at_end) {
    ft::list<int>::iterator pos = mine.end();
    ft::list<int>::iterator ret = mine.insert(pos, 1, 8);
    EXPECT_EQ(mine.size(), 1);
    EXPECT_EQ(mine.back(), 8);
    EXPECT_EQ(mine.front(), 8);
}

TEST_F(ListModifiersTests, count_single_insert_into_filled_at_begin) {
    ft::list<int>::iterator pos = mine.begin();
    mine.push_back(2);
    mine.push_back(3);
    ft::list<int>::iterator ret = mine.insert(pos, 1, 1);
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 3);
    EXPECT_TRUE(it == mine.end());
}

TEST_F(ListModifiersTests, count_single_insert_into_filled_in_the_middle) {
    ft::list<int>::iterator pos = mine.end();
    mine.push_back(1);
    mine.push_back(3);
    pos++;
    ft::list<int>::iterator ret = mine.insert(pos, 1, 2);
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 3);
    EXPECT_TRUE(it == mine.end());
}

TEST_F(ListModifiersTests, count_single_insert_into_filled_at_end) {
    ft::list<int>::iterator pos = mine.end();
    mine.push_back(1);
    mine.push_back(2);
    ft::list<int>::iterator ret = mine.insert(pos, 1, 3);
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 3);
    EXPECT_TRUE(it == mine.end());
}

TEST_F(ListModifiersTests, count_multiple_insert_into_empty_at_begin) {
    ft::list<int>::iterator pos = mine.begin();
    ft::list<int>::iterator ret = mine.insert(pos, 2, 8);
    EXPECT_EQ(mine.size(), 2);
    EXPECT_EQ(mine.back(), 8);
    EXPECT_EQ(mine.front(), 8);
}

TEST_F(ListModifiersTests, count_multiple_insert_into_empty_at_end) {
    ft::list<int>::iterator pos = mine.end();
    ft::list<int>::iterator ret = mine.insert(pos, 2, 8);
    EXPECT_EQ(mine.size(), 2);
    EXPECT_EQ(mine.back(), 8);
    EXPECT_EQ(mine.front(), 8);
}

TEST_F(ListModifiersTests, count_multiple_insert_into_filled_at_begin) {
    ft::list<int>::iterator pos = mine.begin();
    mine.push_back(2);
    mine.push_back(3);
    ft::list<int>::iterator ret = mine.insert(pos, 3, 1);
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 3);
    EXPECT_TRUE(it == mine.end());
}

TEST_F(ListModifiersTests, count_multiple_insert_into_filled_in_the_middle) {
    ft::list<int>::iterator pos = mine.end();
    mine.push_back(1);
    mine.push_back(3);
    pos++;
    ft::list<int>::iterator ret = mine.insert(pos, 3, 2);
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 3);
    EXPECT_TRUE(it == mine.end());
}

TEST_F(ListModifiersTests, count_multiple_insert_into_filled_at_end) {
    ft::list<int>::iterator pos = mine.end();
    mine.push_back(1);
    mine.push_back(2);
    ft::list<int>::iterator ret = mine.insert(pos, 3, 3);
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 3);
    EXPECT_EQ(*(it++), 3);
    EXPECT_EQ(*(it++), 3);
    EXPECT_TRUE(it == mine.end());
}

TEST_F(ListModifiersTests, range_single_insert_into_empty_at_begin) {
    ft::list<int>::iterator pos = mine.begin();
    ft::list<int> other;
    other.push_back(1);
    ft::list<int>::iterator ret = mine.insert(pos, other.begin(), other.end());
    EXPECT_EQ(mine.size(), 1);
    EXPECT_EQ(mine.front(), 1);
    EXPECT_EQ(mine.back(), 1);
}

TEST_F(ListModifiersTests, range_single_insert_into_empty_at_end) {
    ft::list<int>::iterator pos = mine.end();
    ft::list<int> other;
    other.push_back(1);
    ft::list<int>::iterator ret = mine.insert(pos, other.begin(), other.end());
    EXPECT_EQ(mine.size(), 1);
    EXPECT_EQ(mine.front(), 1);
    EXPECT_EQ(mine.back(), 1);
}

TEST_F(ListModifiersTests, range_single_insert_into_filled_at_begin) {
    ft::list<int>::iterator pos = mine.begin();
    ft::list<int> other;
    other.push_back(1);
    mine.push_back(2);
    mine.push_back(3);
    ft::list<int>::iterator ret = mine.insert(pos, other.begin(), other.end());
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 3);
    EXPECT_TRUE(it == mine.end());
}

TEST_F(ListModifiersTests, range_single_insert_into_filled_in_the_middle) {
    ft::list<int>::iterator pos = mine.begin();
    ft::list<int> other;
    other.push_back(2);
    mine.push_back(1);
    mine.push_back(3);
    pos++;
    ft::list<int>::iterator ret = mine.insert(pos, other.begin(), other.end());
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 3);
    EXPECT_TRUE(it == mine.end());
}

TEST_F(ListModifiersTests, range_single_insert_into_filled_at_end) {
    ft::list<int>::iterator pos = mine.end();
    ft::list<int> other;
    other.push_back(3);
    mine.push_back(1);
    mine.push_back(2);
    ft::list<int>::iterator ret = mine.insert(pos, other.begin(), other.end());
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 3);
    EXPECT_TRUE(it == mine.end());
}

TEST_F(ListModifiersTests, range_multiple_insert_into_empty_at_begin) {
    ft::list<int>::iterator pos = mine.begin();
    std::list<int> other;
    other.push_back(1);
    other.push_back(2);
    ft::list<int>::iterator ret = mine.insert(pos, other.begin(), other.begin());
    EXPECT_EQ(mine.size(), 2);
    EXPECT_EQ(mine.front(), 1);
    EXPECT_EQ(mine.back(), 2);
}

TEST_F(ListModifiersTests, range_multiple_insert_into_empty_at_end) {
    ft::list<int>::iterator pos = mine.end();
    std::list<int> other;
    other.push_back(1);
    other.push_back(2);
    ft::list<int>::iterator ret = mine.insert(pos, other.begin(), other.begin());
    EXPECT_EQ(mine.size(), 2);
    EXPECT_EQ(mine.front(), 1);
    EXPECT_EQ(mine.back(), 2);
}

TEST_F(ListModifiersTests, range_multiple_insert_into_filled_at_begin) {
    ft::list<int>::iterator pos = mine.begin();
    ft::list<int> other;
    other.push_back(1);
    other.push_back(1);
    other.push_back(1);
    mine.push_back(2);
    mine.push_back(3);
    ft::list<int>::iterator ret = mine.insert(pos, other.begin(), other.end());
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 3);
    EXPECT_TRUE(it == mine.end());
}

TEST_F(ListModifiersTests, range_multiple_insert_into_filled_in_the_middle) {
    ft::list<int>::iterator pos = mine.begin();
    ft::list<int> other;
    other.push_back(2);
    other.push_back(2);
    other.push_back(2);
    mine.push_back(1);
    mine.push_back(3);
    pos++;
    ft::list<int>::iterator ret = mine.insert(pos, other.begin(), other.end());
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 3);
    EXPECT_TRUE(it == mine.end());
}

TEST_F(ListModifiersTests, range_multiple_insert_into_filled_at_end) {
    ft::list<int>::iterator pos = mine.end();
    ft::list<int> other;
    other.push_back(3);
    other.push_back(3);
    other.push_back(3);
    mine.push_back(1);
    mine.push_back(2);
    ft::list<int>::iterator ret = mine.insert(pos, other.begin(), other.end());
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 3);
    EXPECT_EQ(*(it++), 3);
    EXPECT_EQ(*(it++), 3);
    EXPECT_TRUE(it == mine.end());
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
