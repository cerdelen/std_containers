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

    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 3);
    EXPECT_TRUE(it == mine.end());
    EXPECT_EQ(*ret, 1);
    EXPECT_TRUE(pos == ++ret);
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
    EXPECT_TRUE(pos == ++ret);
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
    EXPECT_TRUE(pos == ++ret);
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
    mine.push_back(1);
    mine.push_back(2);
    ft::list<int>::iterator pos = mine.begin();
    ft::list<int>::iterator ret = mine.insert(pos, 0, 2);
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_TRUE(it == mine.end());
    EXPECT_TRUE(ret == pos);
}

TEST_F(ListModifiersTests, count_empty_insert_into_filled_in_the_middle) {
    mine.push_back(1);
    mine.push_back(2);
    ft::list<int>::iterator pos = mine.begin();
    pos++;
    ft::list<int>::iterator ret = mine.insert(pos, (size_t)0, 2);
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_TRUE(it == mine.end());
    EXPECT_TRUE(ret == pos);
}

TEST_F(ListModifiersTests, count_empty_insert_into_filled_at_end) {
    mine.push_back(1);
    mine.push_back(2);
    ft::list<int>::iterator pos = mine.end();
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
    pos--;
    EXPECT_TRUE(ret == pos);
}

TEST_F(ListModifiersTests, count_single_insert_into_empty_at_end) {
    ft::list<int>::iterator pos = mine.end();
    ft::list<int>::iterator ret = mine.insert(pos, 1, 8);
    EXPECT_EQ(mine.size(), 1);
    EXPECT_EQ(mine.back(), 8);
    EXPECT_EQ(mine.front(), 8);
    pos--;
    EXPECT_TRUE(ret == pos);
}

TEST_F(ListModifiersTests, count_single_insert_into_filled_at_begin) {
    mine.push_back(2);
    mine.push_back(3);
    ft::list<int>::iterator pos = mine.begin();
    ft::list<int>::iterator ret = mine.insert(pos, 1, 1);
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 3);
    EXPECT_TRUE(it == mine.end());
    pos--;
    EXPECT_TRUE(ret == pos);
}

TEST_F(ListModifiersTests, count_single_insert_into_filled_in_the_middle) {
    mine.push_back(1);
    mine.push_back(3);
    ft::list<int>::iterator pos = mine.begin();
    pos++;
    ft::list<int>::iterator ret = mine.insert(pos, 1, 2);
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 3);
    EXPECT_TRUE(it == mine.end());
    pos--;
    EXPECT_TRUE(ret == pos);
}

TEST_F(ListModifiersTests, count_single_insert_into_filled_at_end) {
    mine.push_back(1);
    mine.push_back(2);
    ft::list<int>::iterator pos = mine.end();
    ft::list<int>::iterator ret = mine.insert(pos, 1, 3);
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 3);
    EXPECT_TRUE(it == mine.end());
    pos--;
    EXPECT_TRUE(ret == pos);
}

TEST_F(ListModifiersTests, count_multiple_insert_into_empty_at_begin) {
    ft::list<int>::iterator pos = mine.begin();
    ft::list<int>::iterator ret = mine.insert(pos, 2, 8);
    EXPECT_EQ(mine.size(), 2);
    EXPECT_EQ(mine.back(), 8);
    EXPECT_EQ(mine.front(), 8);
    pos--;
    pos--;
    EXPECT_TRUE(ret == pos);
}

TEST_F(ListModifiersTests, count_multiple_insert_into_empty_at_end) {
    ft::list<int>::iterator pos = mine.end();
    ft::list<int>::iterator ret = mine.insert(pos, 2, 8);
    EXPECT_EQ(mine.size(), 2);
    EXPECT_EQ(mine.back(), 8);
    EXPECT_EQ(mine.front(), 8);
    pos--;
    pos--;
    EXPECT_TRUE(ret == pos);
}

TEST_F(ListModifiersTests, count_multiple_insert_into_filled_at_begin) {
    mine.push_back(2);
    mine.push_back(3);
    ft::list<int>::iterator pos = mine.begin();
    ft::list<int>::iterator ret = mine.insert(pos, 3, 1);
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 3);
    EXPECT_TRUE(it == mine.end());
    pos--;
    pos--;
    pos--;
    EXPECT_TRUE(ret == pos);
}

TEST_F(ListModifiersTests, count_multiple_insert_into_filled_in_the_middle) {
    mine.push_back(1);
    mine.push_back(3);
    ft::list<int>::iterator pos = mine.begin();
    pos++;
    ft::list<int>::iterator ret = mine.insert(pos, 3, 2);
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 3);
    EXPECT_TRUE(it == mine.end());
    pos--;
    pos--;
    pos--;
    EXPECT_TRUE(ret == pos);
}

TEST_F(ListModifiersTests, count_multiple_insert_into_filled_at_end) {
    mine.push_back(1);
    mine.push_back(2);
    ft::list<int>::iterator pos = mine.end();
    ft::list<int>::iterator ret = mine.insert(pos, 3, 3);
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 3);
    EXPECT_EQ(*(it++), 3);
    EXPECT_EQ(*(it++), 3);
    EXPECT_TRUE(it == mine.end());
    pos--;
    pos--;
    pos--;
    EXPECT_TRUE(ret == pos);
}

// Range
//
// into empty
//      begin
//      end
//  filled
//      begin
//      middle
//      end

TEST_F(ListModifiersTests, range_empty_insert_into_empty_at_begin) {
    ft::list<int> other;
    ft::list<int>::iterator pos = mine.begin();
    ft::list<int>::iterator ret = mine.insert(pos, other.begin(), other.end());
    EXPECT_EQ(mine.size(), 0);
    EXPECT_TRUE(ret == pos);
}

TEST_F(ListModifiersTests, range_empty_insert_into_empty_at_end) {
    ft::list<int> other;
    ft::list<int>::iterator pos = mine.end();
    ft::list<int>::iterator ret = mine.insert(pos, other.begin(), other.end());
    EXPECT_EQ(mine.size(), 0);
    EXPECT_TRUE(ret == pos);
}

TEST_F(ListModifiersTests, range_empty_insert_into_filled_at_begin) {
    ft::list<int> other;
    mine.push_back(2);
    mine.push_back(3);
    ft::list<int>::iterator pos = mine.begin();
    ft::list<int>::iterator ret = mine.insert(pos, other.begin(), other.end());
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 3);
    EXPECT_TRUE(it == mine.end());
    EXPECT_TRUE(ret == pos);
}
TEST_F(ListModifiersTests, range_empty_insert_into_filled_in_the_middle) {
    ft::list<int> other;
    mine.push_back(2);
    mine.push_back(3);
    ft::list<int>::iterator pos = mine.begin();
    pos++;
    ft::list<int>::iterator ret = mine.insert(pos, other.begin(), other.end());
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 3);
    EXPECT_TRUE(it == mine.end());
    EXPECT_TRUE(ret == pos);
}

TEST_F(ListModifiersTests, range_empty_insert_into_filled_at_end) {
    ft::list<int> other;
    mine.push_back(2);
    mine.push_back(3);
    ft::list<int>::iterator pos = mine.end();
    ft::list<int>::iterator ret = mine.insert(pos, other.begin(), other.end());
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 3);
    EXPECT_TRUE(it == mine.end());
    EXPECT_TRUE(ret == pos);
}

TEST_F(ListModifiersTests, range_single_insert_into_empty_at_begin) {
    ft::list<int> other;
    other.push_back(1);
    ft::list<int>::iterator pos = mine.begin();
    ft::list<int>::iterator ret = mine.insert(pos, other.begin(), other.end());
    EXPECT_EQ(mine.size(), 1);
    EXPECT_EQ(mine.front(), 1);
    EXPECT_EQ(mine.back(), 1);
    pos--;
    EXPECT_TRUE(ret == pos);
}

TEST_F(ListModifiersTests, range_single_insert_into_empty_at_end) {
    ft::list<int> other;
    other.push_back(1);
    ft::list<int>::iterator pos = mine.end();
    ft::list<int>::iterator ret = mine.insert(pos, other.begin(), other.end());
    EXPECT_EQ(mine.size(), 1);
    EXPECT_EQ(mine.front(), 1);
    EXPECT_EQ(mine.back(), 1);
    pos--;
    EXPECT_TRUE(ret == pos);
}

TEST_F(ListModifiersTests, range_single_insert_into_filled_at_begin) {
    ft::list<int> other;
    other.push_back(1);
    mine.push_back(2);
    mine.push_back(3);
    ft::list<int>::iterator pos = mine.begin();
    ft::list<int>::iterator ret = mine.insert(pos, other.begin(), other.end());
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 3);
    EXPECT_TRUE(it == mine.end());
    pos--;
    EXPECT_TRUE(ret == pos);
}

TEST_F(ListModifiersTests, range_single_insert_into_filled_in_the_middle) {
    ft::list<int> other;
    other.push_back(2);
    mine.push_back(1);
    mine.push_back(3);
    ft::list<int>::iterator pos = mine.begin();
    pos++;
    ft::list<int>::iterator ret = mine.insert(pos, other.begin(), other.end());
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 3);
    EXPECT_TRUE(it == mine.end());
    pos--;
    EXPECT_TRUE(ret == pos);
}

TEST_F(ListModifiersTests, range_single_insert_into_filled_at_end) {
    ft::list<int> other;
    other.push_back(3);
    mine.push_back(1);
    mine.push_back(2);
    ft::list<int>::iterator pos = mine.end();
    ft::list<int>::iterator ret = mine.insert(pos, other.begin(), other.end());
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 3);
    EXPECT_TRUE(it == mine.end());
    pos--;
    EXPECT_TRUE(ret == pos);
}

TEST_F(ListModifiersTests, range_multiple_insert_into_empty_at_begin) {
    std::list<int> other;
    other.push_back(1);
    other.push_back(2);
    ft::list<int>::iterator pos = mine.begin();
    ft::list<int>::iterator ret = mine.insert(pos, other.begin(), other.end());
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    pos--;
    pos--;
    EXPECT_TRUE(ret == pos);
}

TEST_F(ListModifiersTests, range_multiple_insert_into_empty_at_end) {
    std::list<int> other;
    other.push_back(1);
    other.push_back(2);
    ft::list<int>::iterator pos = mine.end();
    ft::list<int>::iterator ret = mine.insert(pos, other.begin(), other.end());
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    pos--;
    pos--;
    EXPECT_TRUE(ret == pos);
    pos--;
}

TEST_F(ListModifiersTests, range_multiple_insert_into_filled_at_begin) {
    ft::list<int> other;
    other.push_back(1);
    other.push_back(2);
    other.push_back(3);
    mine.push_back(4);
    mine.push_back(5);
    ft::list<int>::iterator pos = mine.begin();
    ft::list<int>::iterator ret = mine.insert(pos, other.begin(), other.end());
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 3);
    EXPECT_EQ(*(it++), 4);
    EXPECT_EQ(*(it++), 5);
    EXPECT_TRUE(it == mine.end());
    pos--;
    pos--;
    pos--;
    EXPECT_TRUE(ret == pos);
}

TEST_F(ListModifiersTests, range_multiple_insert_into_filled_in_the_middle) {
    ft::list<int> other;
    other.push_back(2);
    other.push_back(3);
    other.push_back(4);
    mine.push_back(1);
    mine.push_back(5);
    ft::list<int>::iterator pos = mine.begin();
    pos++;
    ft::list<int>::iterator ret = mine.insert(pos, other.begin(), other.end());
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 3);
    EXPECT_EQ(*(it++), 4);
    EXPECT_EQ(*(it++), 5);
    EXPECT_TRUE(it == mine.end());
    pos--;
    pos--;
    pos--;
    EXPECT_TRUE(ret == pos);
}

TEST_F(ListModifiersTests, range_multiple_insert_into_filled_at_end) {
    ft::list<int> other;
    other.push_back(3);
    other.push_back(4);
    other.push_back(5);
    mine.push_back(1);
    mine.push_back(2);
    ft::list<int>::iterator pos = mine.end();
    ft::list<int>::iterator ret = mine.insert(pos, other.begin(), other.end());
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 3);
    EXPECT_EQ(*(it++), 4);
    EXPECT_EQ(*(it++), 5);
    EXPECT_TRUE(it == mine.end());
    pos--;
    pos--;
    pos--;
    EXPECT_TRUE(ret == pos);
}

// // erase
// empty does not work as it segfaults on real implementation
//      why does it fail, well prerequisite is input iteratores are dereferencable
//      otherwhise it would be linear to size of list operation instead of constant (or linear to size of to be deleted)
// 1 single erase
//  filled
//      begin
TEST_F(ListModifiersTests, erase_single_at_begin) {
    mine.push_back(1);
    mine.push_back(2);
    mine.push_back(3);
    ft::list<int>::iterator pos = mine.begin();
    ft::list<int>::iterator ret = mine.erase(pos);
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 3);
    EXPECT_TRUE(it == mine.end());
    EXPECT_EQ(*ret, 2);
}
//      middle
TEST_F(ListModifiersTests, erase_single_in_middle) {
    mine.push_back(1);
    mine.push_back(2);
    mine.push_back(3);
    ft::list<int>::iterator pos = mine.begin();
    pos++;
    ft::list<int>::iterator ret = mine.erase(pos);
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 3);
    EXPECT_TRUE(it == mine.end());
    EXPECT_EQ(*ret, 3);
}
//      end
TEST_F(ListModifiersTests, erase_single_at_end) {
    mine.push_back(1);
    mine.push_back(2);
    mine.push_back(3);
    ft::list<int>::iterator pos = mine.begin();
    pos++;
    pos++;
    ft::list<int>::iterator ret = mine.erase(pos);
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_TRUE(it == mine.end());
    EXPECT_TRUE(ret == mine.end());
}
//          one that erases whole
TEST_F(ListModifiersTests, erase_single_on_size_one_list) {
    mine.push_back(1);
    ft::list<int>::iterator pos = mine.begin();
    ft::list<int>::iterator ret = mine.erase(pos);
    ft::list<int>::iterator it = mine.begin();
    EXPECT_TRUE(it == mine.end());
    EXPECT_TRUE(ret == mine.end());
}
//
// 2 range erase
//  filled
//      empty erase range
TEST_F(ListModifiersTests, erase_range_empty_on_empty_list) {
    ft::list<int>::iterator ret = mine.erase(mine.begin(), mine.end());
    ft::list<int>::iterator it = mine.begin();
    EXPECT_TRUE(it == mine.end());
    EXPECT_TRUE(ret == mine.end());
}
//          begin to begin
TEST_F(ListModifiersTests, erase_range_empty_on_filled_list_begin_to_begin) {
    mine.push_back(1);
    mine.push_back(2);
    mine.push_back(3);
    ft::list<int>::iterator pos = mine.begin();
    ft::list<int>::iterator ret = mine.erase(pos, pos);
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 3);
    EXPECT_TRUE(it == mine.end());
    EXPECT_TRUE(ret == pos);
}
//          middle to middle
TEST_F(ListModifiersTests, erase_range_empty_on_filled_list_middle_to_middle) {
    mine.push_back(1);
    mine.push_back(2);
    mine.push_back(3);
    ft::list<int>::iterator pos = mine.begin();
    pos++;
    ft::list<int>::iterator ret = mine.erase(pos, pos);
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 3);
    EXPECT_TRUE(it == mine.end());
    EXPECT_TRUE(ret == pos);
}
//          end to end
TEST_F(ListModifiersTests, erase_range_empty_on_filled_list_end_to_end) {
    mine.push_back(1);
    mine.push_back(2);
    mine.push_back(3);
    ft::list<int>::iterator pos = mine.begin();
    pos++;
    pos++;
    ft::list<int>::iterator ret = mine.erase(pos, pos);
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 3);
    EXPECT_TRUE(it == mine.end());
    EXPECT_TRUE(ret == pos);
}
//      single erase range
//          at begin
TEST_F(ListModifiersTests, erase_range_single_on_filled_list_at_begin) {
    mine.push_back(1);
    mine.push_back(2);
    mine.push_back(3);
    ft::list<int>::iterator pos = mine.begin();
    ft::list<int>::iterator ret = mine.erase(pos, ++pos);
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 3);
    EXPECT_TRUE(it == mine.end());
    EXPECT_TRUE(ret == pos);
}
//          in middle
TEST_F(ListModifiersTests, erase_range_single_on_filled_list_in_the_middle) {
    mine.push_back(1);
    mine.push_back(2);
    mine.push_back(3);
    ft::list<int>::iterator pos = mine.begin();
    pos++;
    ft::list<int>::iterator ret = mine.erase(pos, ++pos);
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 3);
    EXPECT_TRUE(it == mine.end());
    EXPECT_TRUE(ret == pos);
}
//          at end
TEST_F(ListModifiersTests, erase_range_single_on_filled_list_at_the_end) {
    mine.push_back(1);
    mine.push_back(2);
    mine.push_back(3);
    ft::list<int>::iterator pos = mine.begin();
    pos++;
    pos++;
    ft::list<int>::iterator ret = mine.erase(pos, ++pos);
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_TRUE(it == mine.end());
    EXPECT_TRUE(ret == pos);
}
//          one that erases whole
TEST_F(ListModifiersTests, erase_range_single_that_erases_whole_list) {
    mine.push_back(1);
    ft::list<int>::iterator pos = mine.begin();
    ft::list<int>::iterator ret = mine.erase(pos, ++pos);
    ft::list<int>::iterator it = mine.begin();
    EXPECT_TRUE(it == mine.end());
    EXPECT_TRUE(ret == pos);
}
//      range erase
//          at begin to middle
TEST_F(ListModifiersTests, erase_range_multiple_on_filled_list_begin_to_middle) {
    mine.push_back(1);
    mine.push_back(2);
    mine.push_back(3);
    mine.push_back(4);
    ft::list<int>::iterator pos = mine.begin();
    ft::list<int>::iterator ret = mine.erase(pos, ++(++pos));
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 3);
    EXPECT_EQ(*(it++), 4);
    EXPECT_TRUE(it == mine.end());
    EXPECT_TRUE(ret == pos);
}
//          in middle to middle
TEST_F(ListModifiersTests, erase_range_multiple_on_filled_list_middle_to_middle) {
    mine.push_back(1);
    mine.push_back(2);
    mine.push_back(3);
    mine.push_back(4);
    ft::list<int>::iterator pos = mine.begin();
    pos++;
    ft::list<int>::iterator ret = mine.erase(pos, ++(++pos));
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 4);
    EXPECT_TRUE(it == mine.end());
    EXPECT_TRUE(ret == pos);
}
TEST_F(ListModifiersTests, erase_range_multiple_on_filled_list_middle_to_end) {
    mine.push_back(1);
    mine.push_back(2);
    mine.push_back(3);
    mine.push_back(4);
    ft::list<int>::iterator pos = mine.begin();
    pos++;
    pos++;
    ft::list<int>::iterator ret = mine.erase(pos, mine.end());
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_TRUE(it == mine.end());
    EXPECT_TRUE(ret == mine.end());
}
TEST_F(ListModifiersTests, erase_range_multiple_that_erases_whole_list) {
    mine.push_back(1);
    mine.push_back(2);
    mine.push_back(3);
    mine.push_back(4);
    ft::list<int>::iterator pos = mine.begin();
    ft::list<int>::iterator ret = mine.erase(pos, mine.end());
    ft::list<int>::iterator it = mine.begin();
    EXPECT_TRUE(it == mine.end());
    EXPECT_TRUE(ret == mine.end());
}
//          in middle to end
//
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

// create 2 lists ... swap them ... check with iterator they are changed but stayed the same?
// // swap
TEST_F(ListModifiersTests, swap_size_correctness) {
    ft::list<int> other;
    mine.push_back(1);
    mine.push_back(2);
    mine.push_back(3);
    other.push_back(4);
    other.push_back(5);
    other.push_back(6);
    other.push_back(7);

    mine.swap(other);

    EXPECT_EQ(mine.size(), 4);
    EXPECT_EQ(other.size(), 3);
}

TEST_F(ListModifiersTests, swap_contents_are_correct) {
    ft::list<int> other;
    mine.push_back(1);
    mine.push_back(2);
    mine.push_back(3);
    other.push_back(4);
    other.push_back(5);
    other.push_back(6);
    other.push_back(7);
    mine.swap(other);

    ft::list<int>::const_iterator it = mine.begin();
    ft::list<int>::const_iterator other_it = other.begin();
    EXPECT_EQ(*(it++), 4);
    EXPECT_EQ(*(it++), 5);
    EXPECT_EQ(*(it++), 6);
    EXPECT_EQ(*(it++), 7);
    EXPECT_TRUE(it == mine.end());
    EXPECT_EQ(*(other_it++), 1);
    EXPECT_EQ(*(other_it++), 2);
    EXPECT_EQ(*(other_it++), 3);
    EXPECT_TRUE(other_it == other.end());
}

TEST_F(ListModifiersTests, swap_iterator_remain_valid) {
    ft::list<int> other;
    mine.push_back(1);
    mine.push_back(2);
    mine.push_back(3);
    other.push_back(4);
    other.push_back(5);
    other.push_back(6);
    other.push_back(7);
    ft::list<int>::const_iterator it = mine.begin();
    ft::list<int>::const_iterator other_it = other.begin();
    mine.swap(other);

    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 3);
    EXPECT_TRUE(it == other.end());
    EXPECT_EQ(*(other_it++), 4);
    EXPECT_EQ(*(other_it++), 5);
    EXPECT_EQ(*(other_it++), 6);
    EXPECT_EQ(*(other_it++), 7);
    EXPECT_TRUE(other_it == mine.end());
}

struct Counter {
    static int constructions;
    static int destructions;
    Counter() {
        constructions++;
    }
    ~Counter() {
        destructions++;
    }
};
int Counter::constructions = 0;
int Counter::destructions = 0;

// struct t_construct_counter{
//     static int count;
//     t_construct_counter(){
//         count++;
//     };
// } s_construct_counter;
TEST_F(ListModifiersTests, swap_no_additional_constructs) {
    ft::list<Counter>  other;
    ft::list<Counter>   other2;
    other2.push_back(Counter());
    other2.push_back(Counter());
    other2.push_back(Counter());
    other.push_back(Counter());
    other.push_back(Counter());
    other.push_back(Counter());
    other.push_back(Counter());
    int construct_count = Counter::constructions;
    int destruct_count = Counter::destructions;
    other2.swap(other);

    EXPECT_EQ(Counter::constructions, construct_count);
    EXPECT_EQ(Counter::destructions, destruct_count);
}

