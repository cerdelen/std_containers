#include <gtest/gtest.h>
#include <list>
#include <list.hpp>
#include <memory>
#include <utility>

typedef typename std::pair<std::list<int>, ft::list<int> > testing_pair;

void push_back(std::unique_ptr<testing_pair>& pair_ptr, int val) {
    pair_ptr->first.push_back(val);
    pair_ptr->second.push_back(val);
}

void resize(std::unique_ptr<testing_pair>& pair_ptr, size_t size) {
    pair_ptr->first.resize(size);
    pair_ptr->second.resize(size);
}

void push_front(std::unique_ptr<testing_pair>& pair_ptr, int val) {
    pair_ptr->first.push_front(val);
    pair_ptr->second.push_front(val);
}

void pop_back(std::unique_ptr<testing_pair>& pair_ptr) {
    pair_ptr->first.pop_back();
    pair_ptr->second.pop_back();
}

std::unique_ptr<testing_pair> init_test_pair(size_t size) {
    ft::list<int> mine;
    std::list<int> orig;
    auto out = std::make_unique<testing_pair>(orig, mine);
    EXPECT_EQ(out->first.size(), out->second.size());
    for (int i = size; i > size / 2; i--) {
        push_front(out, i);
    }
    for (int i = size / 2; i > 0; i--) {
        push_back(out, i);
    }

    EXPECT_EQ(out->first.size(), out->second.size());

    return out;
}

void quick_equal_check(const std::unique_ptr<testing_pair>& pair_ptr) {
    EXPECT_EQ(pair_ptr->first.back(), pair_ptr->second.back());
    EXPECT_EQ(pair_ptr->first.front(), pair_ptr->second.front());
    EXPECT_EQ(pair_ptr->first.size(), pair_ptr->second.size());
}

// class ListTests : public ::testing::Test {
//     protected:
//         std::unique_ptr<testing_pair> test_pair;
//         void SetUp() override {
//             ft::list<int> mine;
//             std::list<int> orig;
//             test_pair = std::make_unique<testing_pair>(orig, mine);
//         }
// };



TEST(ListTests, Testing_test_functions) {
    auto pair = init_test_pair(10);
    quick_equal_check(pair);
}


TEST(ListTests, Constructing) {
    ft::list<int> mine;
}

TEST(ListTests, Constructing_0_size) {
    ft::list<int> mine;
    std::list<int> orig;
    EXPECT_EQ(orig.size(), mine.size());
}

TEST(ListTests, Simple_push_front) {
    ft::list<int> mine;
    std::list<int> orig;
    // EXPECT_EQ(orig.back(), mine.back());
    // EXPECT_EQ(orig.front(), mine.front());
    // EXPECT_EQ(orig.size(), mine.size());
    // size_front_back<int>(mine, orig);

    mine.push_front(1);
    orig.push_front(1);
    EXPECT_EQ(orig.back(), mine.back());
    EXPECT_EQ(orig.front(), mine.front());
    EXPECT_EQ(orig.size(), mine.size());
}

TEST(ListTests, Multiple_push_front_size) {
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

TEST(ListTests, MultipleFrontCalls) {
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

TEST(ListTests, Multiple_push_back_size) {
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

TEST(ListTests, MultipleBackCalls) {
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

TEST(ListTests, MixedPushes) {
    auto pair = init_test_pair(10);
    quick_equal_check(pair);
}

TEST(ListTests, PopBack) {
    auto pair = init_test_pair(10);
    quick_equal_check(pair);

    pop_back(pair);
    quick_equal_check(pair);

    pop_back(pair);
    quick_equal_check(pair);

    push_back(pair,7);
    quick_equal_check(pair);
}

TEST(ListTests, resize) {
    auto pair = init_test_pair(10);
    quick_equal_check(pair);

    resize(pair, 5);
    quick_equal_check(pair);

    pop_back(pair);
    quick_equal_check(pair);

    push_back(pair, 7);
    quick_equal_check(pair);

    push_back(pair, 8);
    quick_equal_check(pair);

    pop_back(pair);
    quick_equal_check(pair);

    resize(pair, 2);
    quick_equal_check(pair);

    resize(pair, 15);
    quick_equal_check(pair);

    resize(pair, 0);
    quick_equal_check(pair);
}
