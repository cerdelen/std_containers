#include "ListTestBaseFixture.hpp"

class ListNonMemberFunctionsTests : public ListTestBaseFixture { };

TEST_F(ListNonMemberFunctionsTests, equality_operator) {
    ft::list<int> mine1;
    std::list<int> orig1;

    // empty, equal in size and content
    EXPECT_EQ((mine1 == mine), (orig1 == orig));
    EXPECT_EQ((mine1 == mine), true);


    mine.push_back(5);
    orig.push_back(5);
    // unequal in size
    EXPECT_EQ((mine1 == mine), (orig1 == orig));
    EXPECT_EQ((mine1 == mine), false);

    mine1.push_back(5);
    orig1.push_back(5);
    // equal in size and content
    EXPECT_EQ((mine1 == mine), (orig1 == orig));
    EXPECT_EQ((mine1 == mine), true);

    mine1.push_back(5);
    orig1.push_back(5);
    mine.push_back(99);
    orig.push_back(99);
    //equal in size, unequal in content
    EXPECT_EQ((mine1 == mine), (orig1 == orig));
    EXPECT_EQ((mine1 == mine), false);
}

TEST_F(ListNonMemberFunctionsTests, inequality_operator) {
    ft::list<int> mine1;
    std::list<int> orig1;

    // empty, equal in size and content
    EXPECT_EQ((mine1 != mine), (orig1 != orig));
    EXPECT_EQ((mine1 != mine), false);


    mine.push_back(5);
    orig.push_back(5);
    // unequal in size
    EXPECT_EQ((mine1 != mine), (orig1 != orig));
    EXPECT_EQ((mine1 != mine), true);

    mine1.push_back(5);
    orig1.push_back(5);
    // equal in size and content
    EXPECT_EQ((mine1 != mine), (orig1 != orig));
    EXPECT_EQ((mine1 != mine), false);

    mine1.push_back(5);
    orig1.push_back(5);
    mine.push_back(99);
    orig.push_back(99);
    //equal in size, unequal in content
    EXPECT_EQ((mine1 != mine), (orig1 != orig));
    EXPECT_EQ((mine1 != mine), true);
}

// for greater/smaller operations this should be proficient.
// an equal list
// { 1 }
// { 1 }
// check 1 < 2 checking equal should be false
//
// one unequal list by size
// push_back_
// { 1, 99 }
// { 1 }
// check 1 < 2 checking equal should be false
// check 2 < 1 checking equal should be true
//
// one equal size list with unequal contents
// { 1, 99 }
// { 1, 2 }
// check 1 < 2 checking equal should be false
// check 2 < 1 checking equal should be true
TEST_F(ListNonMemberFunctionsTests, less_than_operator) {
    ft::list<int>   mine1(mine);
    std::list<int>  orig1(orig);
    EXPECT_EQ((mine < mine1), (orig < orig1));
    EXPECT_EQ((mine < mine1), false);
    EXPECT_EQ((mine1 < mine), (orig1 < orig));
    EXPECT_EQ((mine1 < mine), false);

    push_back(1);
    mine1.push_back(1);
    orig1.push_back(1);
    EXPECT_EQ((mine < mine1), (orig < orig1));
    EXPECT_EQ((mine < mine1), false);
    EXPECT_EQ((mine1 < mine), (orig1 < orig));
    EXPECT_EQ((mine1 < mine), false);

    push_back(99);
    EXPECT_EQ((mine < mine1), (orig < orig1));
    EXPECT_EQ((mine < mine1), false);
    EXPECT_EQ((mine1 < mine), (orig1 < orig));
    EXPECT_EQ((mine1 < mine), true);

    mine1.push_back(2);
    orig1.push_back(2);
    EXPECT_EQ((mine < mine1), (orig < orig1));
    EXPECT_EQ((mine < mine1), false);
    EXPECT_EQ((mine1 < mine), (orig1 < orig));
    EXPECT_EQ((mine1 < mine), true);
}

TEST_F(ListNonMemberFunctionsTests, greater_than_operator) {
    ft::list<int>   mine1(mine);
    std::list<int>  orig1(orig);
    EXPECT_EQ((mine > mine1), (orig > orig1));
    EXPECT_EQ((mine > mine1), false);
    EXPECT_EQ((mine1 > mine), (orig1 > orig));
    EXPECT_EQ((mine1 > mine), false);

    push_back(1);
    mine1.push_back(1);
    orig1.push_back(1);
    EXPECT_EQ((mine > mine1), (orig > orig1));
    EXPECT_EQ((mine > mine1), false);
    EXPECT_EQ((mine1 > mine), (orig1 > orig));
    EXPECT_EQ((mine1 > mine), false);

    push_back(99);
    EXPECT_EQ((mine > mine1), (orig > orig1));
    EXPECT_EQ((mine > mine1), true);
    EXPECT_EQ((mine1 > mine), (orig1 > orig));
    EXPECT_EQ((mine1 > mine), false);

    mine1.push_back(2);
    orig1.push_back(2);
    EXPECT_EQ((mine > mine1), (orig > orig1));
    EXPECT_EQ((mine > mine1), true);
    EXPECT_EQ((mine1 > mine), (orig1 > orig));
    EXPECT_EQ((mine1 > mine), false);
}

TEST_F(ListNonMemberFunctionsTests, less_than_or_equal_operator) {
    ft::list<int>   mine1(mine);
    std::list<int>  orig1(orig);
    EXPECT_EQ((mine <= mine1), (orig <= orig1));
    EXPECT_EQ((mine <= mine1), true);
    EXPECT_EQ((mine1 <= mine), (orig1 <= orig));
    EXPECT_EQ((mine1 <= mine), true);

    push_back(1);
    mine1.push_back(1);
    orig1.push_back(1);
    EXPECT_EQ((mine <= mine1), (orig <= orig1));
    EXPECT_EQ((mine <= mine1), true);
    EXPECT_EQ((mine1 <= mine), (orig1 <= orig));
    EXPECT_EQ((mine1 <= mine), true);

    push_back(99);
    EXPECT_EQ((mine <= mine1), (orig <= orig1));
    EXPECT_EQ((mine <= mine1), false);
    EXPECT_EQ((mine1 <= mine), (orig1 <= orig));
    EXPECT_EQ((mine1 <= mine), true);

    mine1.push_back(2);
    orig1.push_back(2);
    EXPECT_EQ((mine <= mine1), (orig <= orig1));
    EXPECT_EQ((mine <= mine1), false);
    EXPECT_EQ((mine1 <= mine), (orig1 <= orig));
    EXPECT_EQ((mine1 <= mine), true);
}


TEST_F(ListNonMemberFunctionsTests, greater_than_or_equal_operator) {
    ft::list<int>   mine1(mine);
    std::list<int>  orig1(orig);
    EXPECT_EQ((mine >=  mine1), (orig >=  orig1));
    EXPECT_EQ((mine >=  mine1), true);
    EXPECT_EQ((mine1 >=  mine), (orig1 >=  orig));
    EXPECT_EQ((mine1 >=  mine), true);

    push_back(1);
    mine1.push_back(1);
    orig1.push_back(1);
    EXPECT_EQ((mine >=  mine1), (orig >=  orig1));
    EXPECT_EQ((mine >=  mine1), true);
    EXPECT_EQ((mine1 >=  mine), (orig1 >=  orig));
    EXPECT_EQ((mine1 >=  mine), true);

    push_back(99);
    EXPECT_EQ((mine >=  mine1), (orig >=  orig1));
    EXPECT_EQ((mine >=  mine1), true);
    EXPECT_EQ((mine1 >=  mine), (orig1 >=  orig));
    EXPECT_EQ((mine1 >=  mine), false);

    mine1.push_back(2);
    orig1.push_back(2);
    EXPECT_EQ((mine >=  mine1), (orig >=  orig1));
    EXPECT_EQ((mine >=  mine1), true);
    EXPECT_EQ((mine1 >=  mine), (orig1 >=  orig));
    EXPECT_EQ((mine1 >=  mine), false);
}

