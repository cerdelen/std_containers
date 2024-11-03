#include "ListTestBaseFixture.hpp"

class ListNonMemberFunctionsTests : public ListTestBaseFixture { };

TEST_F(ListNonMemberFunctionsTests, equality_operator_empty_lists) {
    ft::list<int> mine1;
    std::list<int> orig1;

    EXPECT_EQ((mine == mine1), (orig == orig1));
    EXPECT_EQ((mine == mine1), true);
}

TEST_F(ListNonMemberFunctionsTests, equality_operator_one_empty_one_filled) {
    ft::list<int> mine1;
    std::list<int> orig1;

    mine1.push_back(5);
    orig1.push_back(5);

    EXPECT_EQ((mine == mine1), (orig == orig1));
    EXPECT_EQ((mine == mine1), false);
}

TEST_F(ListNonMemberFunctionsTests, equality_operator_equal_size_and_content) {
    ft::list<int> mine1;
    std::list<int> orig1;

    mine1.push_back(5);
    orig1.push_back(5);
    mine.push_back(5);
    orig.push_back(5);

    EXPECT_EQ((mine == mine1), (orig == orig1));
    EXPECT_EQ((mine == mine1), true);
}

TEST_F(ListNonMemberFunctionsTests, equality_operator_equal_size_unequal_content) {
    ft::list<int> mine1;
    std::list<int> orig1;

    mine1.push_back(5);
    orig1.push_back(5);

    mine.push_back(99);
    orig.push_back(99);

    EXPECT_EQ((mine == mine1), (orig == orig1));
    EXPECT_EQ((mine == mine1), false);
}

TEST_F(ListNonMemberFunctionsTests, in_equality_operator_empty_lists) {
    ft::list<int> mine1;
    std::list<int> orig1;

    EXPECT_EQ((mine != mine1), (orig != orig1));
    EXPECT_EQ((mine != mine1), false);
}

TEST_F(ListNonMemberFunctionsTests, in_equality_operator_one_empty_one_filled) {
    ft::list<int> mine1;
    std::list<int> orig1;

    mine1.push_back(5);
    orig1.push_back(5);

    EXPECT_EQ((mine != mine1), (orig != orig1));
    EXPECT_EQ((mine != mine1), true);
}

TEST_F(ListNonMemberFunctionsTests, in_equality_operator_equal_size_and_content) {
    ft::list<int> mine1;
    std::list<int> orig1;

    mine1.push_back(5);
    orig1.push_back(5);
    mine.push_back(5);
    orig.push_back(5);

    EXPECT_EQ((mine != mine1), (orig != orig1));
    EXPECT_EQ((mine != mine1), false);
}

TEST_F(ListNonMemberFunctionsTests, in_equality_operator_equal_size_unequal_content) {
    ft::list<int> mine1;
    std::list<int> orig1;

    mine1.push_back(5);
    orig1.push_back(5);

    mine.push_back(99);
    orig.push_back(99);

    EXPECT_EQ((mine != mine1), (orig != orig1));
    EXPECT_EQ((mine != mine1), true);
}

TEST_F(ListNonMemberFunctionsTests, equality_operator_on_self) {
    EXPECT_TRUE(mine == mine);
    mine.push_back(1);
    EXPECT_TRUE(mine == mine);
}


TEST_F(ListNonMemberFunctionsTests, inequality_operator_on_self) {
    EXPECT_FALSE(mine != mine);
    mine.push_back(1);
    EXPECT_FALSE(mine != mine);
}

// for greater/smaller operations this should be proficient.
// an equal list
// { 1 }
// { 1 }
//
// one unequal list by size
// push_back_
// { 1, 99 }
// { 1 }
//
// one equal size list with unequal contents
// { 1, 99 }
// { 1, 2 }
//
// on itself
TEST_F(ListNonMemberFunctionsTests, less_than_operator) {
    ft::list<int>   mine1(mine);
    std::list<int>  orig1(orig);
    EXPECT_EQ((mine < mine1), (orig < orig1));
    EXPECT_EQ((mine < mine1), false);
    EXPECT_EQ((mine1 < mine), (orig1 < orig));
    EXPECT_EQ((mine1 < mine), false);
    EXPECT_EQ((mine < mine), (orig < orig));
    EXPECT_EQ((mine < mine), false);

    push_back(1);
    mine1.push_back(1);
    orig1.push_back(1);
    EXPECT_EQ((mine < mine1), (orig < orig1));
    EXPECT_EQ((mine < mine1), false);
    EXPECT_EQ((mine1 < mine), (orig1 < orig));
    EXPECT_EQ((mine1 < mine), false);
    EXPECT_EQ((mine < mine), (orig < orig));
    EXPECT_EQ((mine < mine), false);

    push_back(99);
    EXPECT_EQ((mine < mine1), (orig < orig1));
    EXPECT_EQ((mine < mine1), false);
    EXPECT_EQ((mine1 < mine), (orig1 < orig));
    EXPECT_EQ((mine1 < mine), true);
    EXPECT_EQ((mine < mine), (orig < orig));
    EXPECT_EQ((mine < mine), false);

    mine1.push_back(2);
    orig1.push_back(2);
    EXPECT_EQ((mine < mine1), (orig < orig1));
    EXPECT_EQ((mine < mine1), false);
    EXPECT_EQ((mine1 < mine), (orig1 < orig));
    EXPECT_EQ((mine1 < mine), true);
    EXPECT_EQ((mine < mine), (orig < orig));
    EXPECT_EQ((mine < mine), false);
}

TEST_F(ListNonMemberFunctionsTests, greater_than_operator) {
    ft::list<int>   mine1(mine);
    std::list<int>  orig1(orig);
    EXPECT_EQ((mine > mine1), (orig > orig1));
    EXPECT_EQ((mine > mine1), false);
    EXPECT_EQ((mine1 > mine), (orig1 > orig));
    EXPECT_EQ((mine1 > mine), false);
    EXPECT_EQ((mine > mine), (orig > orig));
    EXPECT_EQ((mine > mine), false);

    push_back(1);
    mine1.push_back(1);
    orig1.push_back(1);
    EXPECT_EQ((mine > mine1), (orig > orig1));
    EXPECT_EQ((mine > mine1), false);
    EXPECT_EQ((mine1 > mine), (orig1 > orig));
    EXPECT_EQ((mine1 > mine), false);
    EXPECT_EQ((mine > mine), (orig > orig));
    EXPECT_EQ((mine > mine), false);

    push_back(99);
    EXPECT_EQ((mine > mine1), (orig > orig1));
    EXPECT_EQ((mine > mine1), true);
    EXPECT_EQ((mine1 > mine), (orig1 > orig));
    EXPECT_EQ((mine1 > mine), false);
    EXPECT_EQ((mine > mine), (orig > orig));
    EXPECT_EQ((mine > mine), false);

    mine1.push_back(2);
    orig1.push_back(2);
    EXPECT_EQ((mine > mine1), (orig > orig1));
    EXPECT_EQ((mine > mine1), true);
    EXPECT_EQ((mine1 > mine), (orig1 > orig));
    EXPECT_EQ((mine1 > mine), false);
    EXPECT_EQ((mine > mine), (orig > orig));
    EXPECT_EQ((mine > mine), false);
}

TEST_F(ListNonMemberFunctionsTests, less_than_or_equal_operator) {
    ft::list<int>   mine1(mine);
    std::list<int>  orig1(orig);
    EXPECT_EQ((mine <= mine1), (orig <= orig1));
    EXPECT_EQ((mine <= mine1), true);
    EXPECT_EQ((mine1 <= mine), (orig1 <= orig));
    EXPECT_EQ((mine1 <= mine), true);
    EXPECT_EQ((mine <= mine), (orig <= orig));
    EXPECT_EQ((mine <= mine), true);

    push_back(1);
    mine1.push_back(1);
    orig1.push_back(1);
    EXPECT_EQ((mine <= mine1), (orig <= orig1));
    EXPECT_EQ((mine <= mine1), true);
    EXPECT_EQ((mine1 <= mine), (orig1 <= orig));
    EXPECT_EQ((mine1 <= mine), true);
    EXPECT_EQ((mine <= mine), (orig <= orig));
    EXPECT_EQ((mine <= mine), true);

    push_back(99);
    EXPECT_EQ((mine <= mine1), (orig <= orig1));
    EXPECT_EQ((mine <= mine1), false);
    EXPECT_EQ((mine1 <= mine), (orig1 <= orig));
    EXPECT_EQ((mine1 <= mine), true);
    EXPECT_EQ((mine <= mine), (orig <= orig));
    EXPECT_EQ((mine <= mine), true);

    mine1.push_back(2);
    orig1.push_back(2);
    EXPECT_EQ((mine <= mine1), (orig <= orig1));
    EXPECT_EQ((mine <= mine1), false);
    EXPECT_EQ((mine1 <= mine), (orig1 <= orig));
    EXPECT_EQ((mine1 <= mine), true);
    EXPECT_EQ((mine <= mine), (orig <= orig));
    EXPECT_EQ((mine <= mine), true);
}


TEST_F(ListNonMemberFunctionsTests, greater_than_or_equal_operator) {
    ft::list<int>   mine1(mine);
    std::list<int>  orig1(orig);
    EXPECT_EQ((mine >=  mine1), (orig >=  orig1));
    EXPECT_EQ((mine >=  mine1), true);
    EXPECT_EQ((mine1 >=  mine), (orig1 >=  orig));
    EXPECT_EQ((mine1 >=  mine), true);
    EXPECT_EQ((mine >= mine), (orig >= orig));
    EXPECT_EQ((mine >= mine), true);

    push_back(1);
    mine1.push_back(1);
    orig1.push_back(1);
    EXPECT_EQ((mine >=  mine1), (orig >=  orig1));
    EXPECT_EQ((mine >=  mine1), true);
    EXPECT_EQ((mine1 >=  mine), (orig1 >=  orig));
    EXPECT_EQ((mine1 >=  mine), true);
    EXPECT_EQ((mine >= mine), (orig >= orig));
    EXPECT_EQ((mine >= mine), true);

    push_back(99);
    EXPECT_EQ((mine >=  mine1), (orig >=  orig1));
    EXPECT_EQ((mine >=  mine1), true);
    EXPECT_EQ((mine1 >=  mine), (orig1 >=  orig));
    EXPECT_EQ((mine1 >=  mine), false);
    EXPECT_EQ((mine >= mine), (orig >= orig));
    EXPECT_EQ((mine >= mine), true);

    mine1.push_back(2);
    orig1.push_back(2);
    EXPECT_EQ((mine >=  mine1), (orig >=  orig1));
    EXPECT_EQ((mine >=  mine1), true);
    EXPECT_EQ((mine1 >=  mine), (orig1 >=  orig));
    EXPECT_EQ((mine1 >=  mine), false);
    EXPECT_EQ((mine >= mine), (orig >= orig));
    EXPECT_EQ((mine >= mine), true);
}

