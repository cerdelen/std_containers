#include "ListTestBaseFixture.hpp"
#include <functional>

class ListOperationsTests : public ListTestBaseFixture { };

TEST_F(ListOperationsTests, merge) {
    mine.push_back(1);
    mine.push_back(4);
    mine.push_back(5);
    mine.push_back(8);

    ft::list<int> other;
    other.push_back(2);
    other.push_back(3);
    other.push_back(6);
    other.push_back(7);
    other.push_back(9);

    mine.merge(other);
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(mine.size(), 9);
    EXPECT_EQ(other.size(), 0);
    EXPECT_EQ(other.begin(), other.end());
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 3);
    EXPECT_EQ(*(it++), 4);
    EXPECT_EQ(*(it++), 5);
    EXPECT_EQ(*(it++), 6);
    EXPECT_EQ(*(it++), 7);
    EXPECT_EQ(*(it++), 8);
    EXPECT_EQ(*(it++), 9);
    EXPECT_TRUE(it == mine.end());
}

TEST_F(ListOperationsTests, merge_iterator_stays_validated) {
    mine.push_back(2);
    mine.push_back(4);
    mine.push_back(5);
    mine.push_back(8);

    ft::list<int> other;
    other.push_back(1);
    other.push_back(3);
    other.push_back(6);
    other.push_back(7);
    other.push_back(9);

    ft::list<int>::iterator it = other.begin();
    mine.merge(other);
    EXPECT_EQ(mine.size(), 9);
    EXPECT_EQ(other.size(), 0);
    EXPECT_EQ(other.begin(), other.end());
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 3);
    EXPECT_EQ(*(it++), 4);
    EXPECT_EQ(*(it++), 5);
    EXPECT_EQ(*(it++), 6);
    EXPECT_EQ(*(it++), 7);
    EXPECT_EQ(*(it++), 8);
    EXPECT_EQ(*(it++), 9);
    EXPECT_TRUE(it == mine.end());
}

TEST_F(ListOperationsTests, merge_at_end) {
    mine.push_back(1);
    mine.push_back(2);
    mine.push_back(3);
    mine.push_back(4);

    ft::list<int> other;
    other.push_back(5);
    other.push_back(6);
    other.push_back(7);
    other.push_back(8);
    other.push_back(9);

    ft::list<int>::iterator it = mine.begin();
    mine.merge(other);
    EXPECT_EQ(mine.size(), 9);
    EXPECT_EQ(other.size(), 0);
    EXPECT_EQ(other.begin(), other.end());
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 3);
    EXPECT_EQ(*(it++), 4);
    EXPECT_EQ(*(it++), 5);
    EXPECT_EQ(*(it++), 6);
    EXPECT_EQ(*(it++), 7);
    EXPECT_EQ(*(it++), 8);
    EXPECT_EQ(*(it++), 9);
    EXPECT_TRUE(it == mine.end());
}

TEST_F(ListOperationsTests, merge_with_one_empty) {
    ft::list<int> other;
    other.push_back(1);
    other.push_back(4);
    other.push_back(10);
    other.push_back(11);
    other.push_back(15);

    ft::list<int>::iterator it = other.begin();
    mine.merge(other);
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 4);
    EXPECT_EQ(*(it++), 10);
    EXPECT_EQ(*(it++), 11);
    EXPECT_EQ(*(it++), 15);
    EXPECT_TRUE(it == mine.end());
    EXPECT_EQ(mine.size(), 5);
    EXPECT_EQ(other.size(), 0);
    EXPECT_EQ(other.begin(), other.end());
}

TEST_F(ListOperationsTests, merge_with_both_empty) {
    ft::list<int> other;

    ft::list<int>::iterator other_it = other.begin();
    ft::list<int>::iterator it = mine.begin();
    mine.merge(other);
    EXPECT_TRUE(other_it == other.end());
    EXPECT_TRUE(it == mine.end());
    EXPECT_EQ(mine.size(), 0);
    EXPECT_EQ(other.size(), 0);
}

struct OperationsCounter {
    static int constructions;
    static int destructions;
    OperationsCounter() {
        constructions++;
    }
    ~OperationsCounter() {
        destructions++;
    }
    bool operator<(OperationsCounter &other){
        return true;
    }
};
int OperationsCounter::constructions = 0;
int OperationsCounter::destructions = 0;

TEST_F(ListOperationsTests, merge_check_for_constructions_destructions) {
    ft::list<OperationsCounter> other;
    ft::list<OperationsCounter> other2;
    other.push_back(OperationsCounter());
    other.push_back(OperationsCounter());
    other.push_back(OperationsCounter());
    other.push_back(OperationsCounter());

    other2.push_back(OperationsCounter());
    other2.push_back(OperationsCounter());
    other2.push_back(OperationsCounter());
    other2.push_back(OperationsCounter());
    other2.push_back(OperationsCounter());

    int constructed = OperationsCounter::constructions;
    int destructed = OperationsCounter::destructions;
    other.merge(other2);
    EXPECT_EQ(other.size(), 9);
    EXPECT_EQ(other2.size(), 0);

    EXPECT_EQ(constructed, OperationsCounter::constructions);
    EXPECT_EQ(destructed, OperationsCounter::destructions);
}

