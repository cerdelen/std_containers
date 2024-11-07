#include "ListTestBaseFixture.hpp"

class ListIteratorTests : public ListTestBaseFixture { };

// iterator
TEST_F(ListIteratorTests, conversion_iterator_to_const_iterator) {
    ft::list<int>::iterator             my_it = mine.begin();
    ft::list<int>::const_iterator       my_const_it(my_it);
    ft::list<int>::const_iterator       my_const_it2;
    my_const_it2 = my_it;
}

// TEST_F(ListIteratorTests, begin_iterator_after_construct) {
//     ft::list<int>::iterator     my_it = mine.begin();
//     std::list<int>::iterator    orig_it = orig.begin();
//
//     EXPECT_EQ(*my_it, *orig_it);
// }

TEST_F(ListIteratorTests, end_equal_begin_on_empty_list) {
    EXPECT_EQ(mine.begin(), mine.end());
}

TEST_F(ListIteratorTests, end_unequal_begin_on_not_empty_list) {
    push_back(1);
    EXPECT_NE(mine.begin(), mine.end());
}

TEST_F(ListIteratorTests, iterator_comparison_operations) {
    init_fill(3);
    ft::list<int>::iterator my_it = mine.begin();
    ft::list<int>::iterator my_it2 = mine.begin();
    my_it2++;

    std::list<int>::iterator orig_it = orig.begin();
    std::list<int>::iterator orig_it2 = orig.begin();
    orig_it2++;

    EXPECT_EQ(my_it == my_it2, orig_it == orig_it2);
    EXPECT_EQ(my_it != my_it2, orig_it != orig_it2);
}

TEST_F(ListIteratorTests, iterator_equality_after_increment) {
    push_back(2);
    ft::list<int>::iterator     my_it = mine.end();
    ft::list<int>::iterator     my_it2 = mine.end();

    my_it++;
    my_it2++;

    EXPECT_EQ(*my_it, *my_it2);
}

TEST_F(ListIteratorTests, iterator_equality_after_decrement) {
    push_back(2);
    ft::list<int>::iterator     my_it = mine.end();
    ft::list<int>::iterator     my_it2 = mine.end();

    my_it--;
    my_it2--;

    EXPECT_EQ(*my_it, *my_it2);
}

TEST_F(ListIteratorTests, begin_iterator_after_push) {
    push_back(1);
    ft::list<int>::iterator     my_it = mine.begin();
    std::list<int>::iterator    orig_it = orig.begin();

    EXPECT_EQ(*my_it, *orig_it);
}

TEST_F(ListIteratorTests, begin_iterator_after_multiple_pushes) {
    init_fill(3);
    ft::list<int>::iterator     my_it = mine.begin();
    std::list<int>::iterator    orig_it = orig.begin();

    EXPECT_EQ(*my_it, *orig_it);
}

// TEST_F(ListIteratorTests, begin_iterator_incremented_on_empty_list) {
//     ft::list<int>::iterator     my_it = mine.begin();
//     std::list<int>::iterator    orig_it = orig.begin();
//
//     increment_iterator(my_it, orig_it);
//     EXPECT_EQ(*my_it, *orig_it);
// }

TEST_F(ListIteratorTests, begin_iterator_incremented_on_filled_list) {
    init_fill(3);
    ft::list<int>::iterator     my_it = mine.begin();
    std::list<int>::iterator    orig_it = orig.begin();

    increment_iterator(my_it, orig_it, 5);
    EXPECT_EQ(*my_it, *orig_it);
}

TEST_F(ListIteratorTests, begin_iterator_looping_decremented_to_before_begin_on_filled) {
    push_back(3);
    ft::list<int>::iterator     my_it = mine.begin();
    std::list<int>::iterator    orig_it = orig.begin();

    decrement_iterator(my_it, orig_it, 4);
    EXPECT_EQ(*my_it, *orig_it);
}

TEST_F(ListIteratorTests, begin_to_end_incrementing_on_filled_list) {
    init_fill(5);
    ft::list<int>::iterator my_it = mine.begin();
    std::list<int>::iterator orig_it = orig.begin();

    while (my_it != mine.end() && orig_it != orig.end()) {
        EXPECT_EQ(*my_it, *orig_it);
        my_it++;
        orig_it++;
    }
    EXPECT_EQ(my_it, mine.end());
    EXPECT_EQ(orig_it, orig.end());
}

TEST_F(ListIteratorTests, begin_to_end_decrementing_on_filled_list) {
    init_fill(5);
    ft::list<int>::iterator my_it = mine.begin();
    std::list<int>::iterator orig_it = orig.begin();

    while (my_it != mine.end() && orig_it != orig.end()) {
        EXPECT_EQ(*my_it, *orig_it);
        my_it--;
        orig_it--;
    }
    EXPECT_EQ(my_it, mine.end());
    EXPECT_EQ(orig_it, orig.end());
}

TEST_F(ListIteratorTests, iterator_after_erase) {
    init_fill(5);
    ft::list<int>::iterator     my_it = mine.begin();
    ft::list<int>::iterator     my_it2 = mine.begin();
    std::list<int>::iterator    orig_it = orig.begin();
    std::list<int>::iterator    orig_it2 = orig.begin();
    increment_iterator(my_it2, orig_it2);

    mine.erase(my_it2);
    orig.erase(orig_it2);

    while (my_it != mine.end() && orig_it != orig.end()) {
        EXPECT_EQ(*my_it, *orig_it);
        my_it++;
        orig_it++;
    }
}


//
// // reverse_iterator
// TEST_F(ListIteratorTests, name) {
// }
//
// // const iterator
// TEST_F(ListIteratorTests, name) {
// }
//
// // reverse const iterator
// TEST_F(ListIteratorTests, name) {
// }
//
