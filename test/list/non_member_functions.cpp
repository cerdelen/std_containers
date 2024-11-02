#include "ListTestBaseFixture.hpp"

class ListNonMemberFunctionsTests : public ListTestBaseFixture { };

TEST_F(ListNonMemberFunctionsTests, equality_operator) {
    ft::list<int> mine1;
    std::list<int> orig1;
    EXPECT_EQ((mine1 == mine), (orig1 == orig));

    push_back(1);
    EXPECT_EQ((mine1 == mine), (orig1 == orig));

    push_front(2);
    EXPECT_EQ((mine1 == mine), (orig1 == orig));

    mine.push_back(99);
    orig.push_back(99);
    EXPECT_EQ((mine1 == mine), (orig1 == orig));
}

TEST_F(ListNonMemberFunctionsTests, inequality_operator) {
    ft::list<int> mine1;
    std::list<int> orig1;
    EXPECT_EQ((mine1 != mine), (orig1 != orig));

    push_back(1);
    EXPECT_EQ((mine1 != mine), (orig1 != orig));

    push_front(2);
    EXPECT_EQ((mine1 != mine), (orig1 != orig));

    mine.push_back(99);
    orig.push_back(99);
    EXPECT_EQ((mine1 != mine), (orig1 != orig));
}

TEST_F(ListNonMemberFunctionsTests, less_than_operator) {
    init_fill(3);
    ft::list<int>   mine1(mine);
    std::list<int>  orig1(orig);

    push_back(1);
    mine.push_back(1);
    orig.push_back(1);
    EXPECT_EQ((mine1 < mine), (orig1 < orig));

    mine.push_back(99);
    orig.push_back(99);
    EXPECT_EQ((mine1 < mine), (orig1 < orig));

    mine1.push_back(0);
    orig1.push_back(0);
    EXPECT_EQ((mine1 < mine), (orig1 < orig));
    EXPECT_EQ((mine < mine1), (orig < orig1));
}

TEST_F(ListNonMemberFunctionsTests, greater_than_operator) {
    init_fill(3);
    ft::list<int>   mine1(mine);
    std::list<int>  orig1(orig);

    push_back(1);
    mine.push_back(1);
    orig.push_back(1);
    EXPECT_EQ((mine1 > mine), (orig1 > orig));

    mine.push_back(99);
    orig.push_back(99);
    EXPECT_EQ((mine1 > mine), (orig1 > orig));

    mine1.push_back(0);
    orig1.push_back(0);
    EXPECT_EQ((mine1 > mine), (orig1 > orig));
    EXPECT_EQ((mine > mine1), (orig > orig1));
}

TEST_F(ListNonMemberFunctionsTests, less_than_or_equal_operator) {
    init_fill(3);
    ft::list<int>   mine1(mine);
    std::list<int>  orig1(orig);

    push_back(1);
    mine.push_back(1);
    orig.push_back(1);
    EXPECT_EQ((mine1 <= mine), (orig1 <= orig));

    mine.push_back(99);
    orig.push_back(99);
    EXPECT_EQ((mine1 <= mine), (orig1 <= orig));

    mine1.push_back(0);
    orig1.push_back(0);
    EXPECT_EQ((mine1 <= mine), (orig1 <= orig));
    EXPECT_EQ((mine <= mine1), (orig <= orig1));
}


TEST_F(ListNonMemberFunctionsTests, greater_than_or_equal_operator) {
    init_fill(3);
    ft::list<int>   mine1(mine);
    std::list<int>  orig1(orig);

    push_back(1);
    mine.push_back(1);
    orig.push_back(1);
    EXPECT_EQ((mine1 >= mine), (orig1 >= orig));

    mine.push_back(99);
    orig.push_back(99);
    EXPECT_EQ((mine1 >= mine), (orig1 >= orig));

    mine1.push_back(0);
    orig1.push_back(0);
    EXPECT_EQ((mine1 >= mine), (orig1 >= orig));
    EXPECT_EQ((mine >= mine1), (orig >= orig1));
}

