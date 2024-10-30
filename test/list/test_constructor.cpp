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

    mine.push_front(2);
    orig.push_front(2);

    mine.push_front(3);
    orig.push_front(3);

    mine.push_front(4);
    orig.push_front(4);
    EXPECT_EQ(orig.size(), mine.size());
}

TEST(TestingList, Multiple_push_front_size) {
    ft::list<int> mine;
    std::list<int> orig;

    mine.push_front(1);
    orig.push_front(1);

    EXPECT_EQ(orig.front(), mine.front());
    EXPECT_EQ(orig.back(), mine.back());
    mine.push_front(2);
    orig.push_front(2);

    EXPECT_EQ(orig.front(), mine.front());
    EXPECT_EQ(orig.back(), mine.back());
    mine.push_front(3);
    orig.push_front(3);

    EXPECT_EQ(orig.front(), mine.front());
    EXPECT_EQ(orig.back(), mine.back());
    mine.push_front(4);
    orig.push_front(4);

    EXPECT_EQ(orig.front(), mine.front());
    EXPECT_EQ(orig.back(), mine.back());
}

