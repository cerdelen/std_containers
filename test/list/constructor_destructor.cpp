#include "ListTestBaseFixture.hpp"

class ListConstructorDestructorTests : public ListTestBaseFixture { };

TEST_F(ListConstructorDestructorTests, Constructing) {
}

// TEST_F(ListConstructorDestructorTests, Constructing_default_value_for_back_front) {
//     EXPECT_EQ(orig.back(), mine.back());
//     EXPECT_EQ(orig.front(), mine.front());
// }


struct ConstructorCounter {
    static int constructions;
    static int destructions;
    ConstructorCounter() {
        constructions++;
    }
    ~ConstructorCounter() {
        destructions++;
    }
};
int ConstructorCounter::constructions = 0;
int ConstructorCounter::destructions = 0;

TEST_F(ListConstructorDestructorTests, Constructing_0_size) {
    EXPECT_EQ(orig.size(), mine.size());
}

TEST_F(ListConstructorDestructorTests, Constructing_no_unnessecary_contesnt_allocated) {
    ft::list<ConstructorCounter> l;
    EXPECT_EQ(ConstructorCounter::constructions, 0);
}

TEST_F(ListConstructorDestructorTests, copy_constructor_empty_same_size) {
    ft::list<ConstructorCounter> l;
    ft::list<ConstructorCounter> la(l);
    EXPECT_EQ(la.size(), l.size());
    EXPECT_EQ(la.size(), 0);
    EXPECT_EQ(ConstructorCounter::constructions, 0);
}

TEST_F(ListConstructorDestructorTests, copy_constructor_filled_same_size) {
    push_back(1);
    ft::list<int> mine2(mine);
    EXPECT_EQ(mine2.size(), mine.size());
    EXPECT_EQ(mine2.size(), 1);
}


TEST_F(ListConstructorDestructorTests, copy_constructor_empty_same_front_back) {
    ft::list<int> mine2(mine);
    EXPECT_EQ(mine2.size(), 0);
}

TEST_F(ListConstructorDestructorTests, copy_constructor_filled_same_front_back) {
    push_back(1);
    ft::list<int> mine2(mine);
    EXPECT_EQ(mine2.size(), 1);
    EXPECT_EQ(mine2.back(), mine.back());
    EXPECT_EQ(mine2.front(), mine.front());
}

// I am using == sign overload which is not ideal to use your own implementations
//      to test your other implementations but == is tested against original
// equal sign one itself
// equal sign empty to empty
// equal sign empty to filled
// equal sign filled to empty
// equal sign filled to filled
//          same size to same size, equal
//          same size to same size, different contents
//          same smaller to bigger size, equal contents until the bigger has more
//          same smaller to bigger size, different contents
//          same bigger to smaller size, equal contents until the bigger has more
//          same bigger to smaller size, different contents
//
TEST_F(ListConstructorDestructorTests, equal_sign_operator_on_itself) {
    mine = mine;
    EXPECT_EQ(mine.size(), 0);
    // important: == operator has to pass tests
    mine.push_back(1);
    mine = mine;
    EXPECT_EQ(mine.size(), 1);
}

TEST_F(ListConstructorDestructorTests, equal_sign_operator_empty_to_empty) {
    // important: == operator has to pass tests
    ft::list<int> mine2;
    mine2 = mine;
    EXPECT_TRUE(mine == mine2);
    EXPECT_EQ(mine.size(), 0);
    EXPECT_EQ(mine2.size(), 0);
}

TEST_F(ListConstructorDestructorTests, equal_sign_operator_empty_to_filled) {
    // important: == operator has to pass tests
    ft::list<int> mine2;
    mine.push_back(1);
    mine.push_back(2);
    mine.push_back(3);
    mine2 = mine;
    EXPECT_TRUE(mine == mine2);
}

TEST_F(ListConstructorDestructorTests, equal_sign_operator_filled_to_empty) {
    // important: == operator has to pass tests
    ft::list<int> mine2;
    mine.push_back(1);
    mine.push_back(2);
    mine.push_back(3);
    mine = mine2;
    EXPECT_TRUE(mine == mine2);
}

TEST_F(ListConstructorDestructorTests, equal_sign_operator_equal_to_equal_filled) {
    // important: == operator has to pass tests
    ft::list<int> mine2;
    mine.push_back(1);
    mine.push_back(2);
    mine.push_back(3);
    mine2.push_back(1);
    mine2.push_back(2);
    mine2.push_back(3);
    mine = mine2;
    EXPECT_TRUE(mine == mine2);
}

TEST_F(ListConstructorDestructorTests, equal_sign_operator_filled_to_filled_same_size_different_content) {
    // important: == operator has to pass tests
    ft::list<int> mine2;
    mine.push_back(1);
    mine.push_back(2);
    mine.push_back(3);
    mine2.push_back(4);
    mine2.push_back(5);
    mine2.push_back(6);
    mine = mine2;
    EXPECT_TRUE(mine == mine2);
}

TEST_F(ListConstructorDestructorTests, equal_sign_operator_filled_to_filled_smaller_to_bigger_different_content) {
    // important: == operator has to pass tests
    ft::list<int> mine2;
    mine.push_back(1);
    mine2.push_back(4);
    mine2.push_back(5);
    mine2.push_back(6);
    mine = mine2;
    EXPECT_TRUE(mine == mine2);
}

TEST_F(ListConstructorDestructorTests, equal_sign_operator_filled_to_filled_smaller_to_bigger_same_until_additional_content) {
    // important: == operator has to pass tests
    ft::list<int> mine2;
    mine.push_back(1);
    mine2.push_back(1);
    mine2.push_back(2);
    mine2.push_back(3);
    mine = mine2;
    EXPECT_TRUE(mine == mine2);
}

TEST_F(ListConstructorDestructorTests, equal_sign_operator_filled_to_filled_bigger_to_smaller_different_content) {
    // important: == operator has to pass tests
    ft::list<int> mine2;
    mine.push_back(1);
    mine2.push_back(4);
    mine2.push_back(5);
    mine2.push_back(6);
    mine2 = mine;
    EXPECT_TRUE(mine == mine2);
}

TEST_F(ListConstructorDestructorTests, equal_sign_operator_filled_to_filled_bigger_to_smaller_same_until_additional_content) {
    // important: == operator has to pass tests
    ft::list<int> mine2;
    mine.push_back(1);
    mine2.push_back(1);
    mine2.push_back(2);
    mine2.push_back(3);
    mine2 = mine;
    EXPECT_TRUE(mine == mine2);
}

