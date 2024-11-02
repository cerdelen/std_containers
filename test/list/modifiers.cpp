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

// // insert
// TEST_F(ListModifiersTests, Name) {
// }
//
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
