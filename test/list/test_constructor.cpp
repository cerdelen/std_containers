#include <gtest/gtest.h>
#include <list>
#include <list.hpp>

TEST(TestingList, Constructing) {
    ft::list<int> mine;
}

TEST(TestingList, Constructing_0_size) {
    ft::list<int> mine;
    std::list<int> orig;
    EXPECT_EQ(orig.size(), mine.size());
}

TEST(TestingList, Simple_push_front) {
    ft::list<int> mine;
    std::list<int> orig;

    mine.push_front(1);
    orig.push_front(1);
    EXPECT_EQ(orig.size(), mine.size());
}

TEST(TestingList, Multiple_push_front_size) {
    ft::list<int> mine;
    std::list<int> orig;

    mine.push_front(1);
    orig.push_front(1);
    EXPECT_EQ(orig.size(), mine.size());

    mine.push_front(2);
    orig.push_front(2);
    EXPECT_EQ(orig.size(), mine.size());

    mine.push_front(3);
    orig.push_front(3);
    EXPECT_EQ(orig.size(), mine.size());

    mine.push_front(4);
    orig.push_front(4);
    EXPECT_EQ(orig.size(), mine.size());
}

TEST(TestingList, MultipleFrontCalls) {
    ft::list<int> mine;
    std::list<int> orig;

    mine.push_front(1);
    orig.push_front(1);

    EXPECT_EQ(orig.front(), mine.front());
    mine.push_front(2);
    orig.push_front(2);

    EXPECT_EQ(orig.front(), mine.front());
    mine.push_front(3);
    orig.push_front(3);

    EXPECT_EQ(orig.front(), mine.front());
    mine.push_front(4);
    orig.push_front(4);

    EXPECT_EQ(orig.front(), mine.front());
}

TEST(TestingList, Multiple_push_back_size) {
    ft::list<int> mine;
    std::list<int> orig;

    mine.push_back(1);
    orig.push_back(1);
    EXPECT_EQ(orig.size(), mine.size());

    mine.push_back(2);
    orig.push_back(2);
    EXPECT_EQ(orig.size(), mine.size());

    mine.push_back(3);
    orig.push_back(3);
    EXPECT_EQ(orig.size(), mine.size());

    mine.push_back(4);
    orig.push_back(4);
    EXPECT_EQ(orig.size(), mine.size());
}

TEST(TestingList, MultipleBackCalls) {
    ft::list<int> mine;
    std::list<int> orig;

    mine.push_back(1);
    orig.push_back(1);

    EXPECT_EQ(orig.back(), mine.back());
    mine.push_back(2);
    orig.push_back(2);

    EXPECT_EQ(orig.back(), mine.back());
    mine.push_back(3);
    orig.push_back(3);

    EXPECT_EQ(orig.back(), mine.back());
    mine.push_back(4);
    orig.push_back(4);

    EXPECT_EQ(orig.back(), mine.back());
}

TEST(TestingList, MixedPushes) {
    ft::list<int> mine;
    std::list<int> orig;

    mine.push_front(4);
    orig.push_front(4);

    EXPECT_EQ(orig.back(), mine.back());
    EXPECT_EQ(orig.size(), mine.size());
    EXPECT_EQ(orig.front(), mine.front());
    mine.push_front(3);
    orig.push_front(3);

    EXPECT_EQ(orig.back(), mine.back());
    EXPECT_EQ(orig.front(), mine.front());
    EXPECT_EQ(orig.size(), mine.size());
    mine.push_front(2);
    orig.push_front(2);

    EXPECT_EQ(orig.back(), mine.back());
    EXPECT_EQ(orig.front(), mine.front());
    EXPECT_EQ(orig.size(), mine.size());
    mine.push_front(1);
    orig.push_front(1);

    EXPECT_EQ(orig.back(), mine.back());
    EXPECT_EQ(orig.front(), mine.front());
    EXPECT_EQ(orig.size(), mine.size());
    mine.push_back(5);
    orig.push_back(5);

    EXPECT_EQ(orig.back(), mine.back());
    EXPECT_EQ(orig.size(), mine.size());
    EXPECT_EQ(orig.front(), mine.front());
    mine.push_back(6);
    orig.push_back(6);

    EXPECT_EQ(orig.back(), mine.back());
    EXPECT_EQ(orig.front(), mine.front());
    EXPECT_EQ(orig.size(), mine.size());
    mine.push_back(7);
    orig.push_back(7);

    EXPECT_EQ(orig.back(), mine.back());
    EXPECT_EQ(orig.front(), mine.front());
    EXPECT_EQ(orig.size(), mine.size());
    mine.push_back(8);
    orig.push_back(8);

    EXPECT_EQ(orig.back(), mine.back());
    EXPECT_EQ(orig.front(), mine.front());
    EXPECT_EQ(orig.size(), mine.size());
}

