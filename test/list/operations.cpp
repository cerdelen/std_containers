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


// splice

TEST_F(ListOperationsTests, splice) {
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

    ft::list<int>::iterator it = mine.begin();
    it++;
    mine.splice(it, other);
    EXPECT_EQ(mine.size(), 9);
    EXPECT_EQ(other.size(), 0);
    EXPECT_EQ(other.begin(), other.end());
    it = mine.begin();
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 3);
    EXPECT_EQ(*(it++), 6);
    EXPECT_EQ(*(it++), 7);
    EXPECT_EQ(*(it++), 9);
    EXPECT_EQ(*(it++), 4);
    EXPECT_EQ(*(it++), 5);
    EXPECT_EQ(*(it++), 8);
    EXPECT_TRUE(it == mine.end());
}

TEST_F(ListOperationsTests, splice_reverse_iterating_valid) {
    mine.push_back(1);
    mine.push_back(2);

    ft::list<int> other;
    other.push_back(3);
    other.push_back(4);

    ft::list<int>::iterator it = mine.end();
    mine.splice(it, other);
    EXPECT_EQ(mine.size(), 4);
    EXPECT_EQ(other.size(), 0);
    EXPECT_EQ(other.begin(), other.end());
    it = mine.end();
    EXPECT_EQ(*(--it), 4);
    EXPECT_EQ(*(--it), 3);
    EXPECT_EQ(*(--it), 2);
    EXPECT_EQ(*(--it), 1);
    EXPECT_TRUE(it == mine.begin());
    ft::list<int>::iterator other_it = other.end();
    other_it--;
    EXPECT_TRUE(other_it == other.end());
}

TEST_F(ListOperationsTests, splice_iterator_stays_validated) {
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

    ft::list<int>::iterator it = mine.begin();
    it++;
    it++;
    mine.splice(it, other);
    EXPECT_EQ(mine.size(), 9);
    EXPECT_EQ(other.size(), 0);
    EXPECT_EQ(other.begin(), other.end());
    EXPECT_EQ(*(it++), 5);
    EXPECT_EQ(*(it--), 8);
    EXPECT_EQ(*(it--), 5);
    EXPECT_EQ(*(it--), 9);
    EXPECT_EQ(*(it--), 7);
    EXPECT_EQ(*(it--), 6);
    EXPECT_EQ(*(it--), 3);
    EXPECT_EQ(*(it--), 1);
    EXPECT_EQ(*(it--), 4);
    EXPECT_EQ(*(it--), 2);
    it++;
    EXPECT_TRUE(it == mine.begin());
}

TEST_F(ListOperationsTests, splice_at_end) {
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

    ft::list<int>::iterator it = mine.end();
    mine.splice(it, other);
    EXPECT_EQ(mine.size(), 9);
    EXPECT_EQ(other.size(), 0);
    EXPECT_EQ(other.begin(), other.end());
    it = mine.begin();
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

TEST_F(ListOperationsTests, splice_at_begin) {
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
    mine.splice(it, other);
    it = mine.begin();
    EXPECT_EQ(mine.size(), 9);
    EXPECT_EQ(other.size(), 0);
    EXPECT_EQ(other.begin(), other.end());
    EXPECT_EQ(*(it++), 5);
    EXPECT_EQ(*(it++), 6);
    EXPECT_EQ(*(it++), 7);
    EXPECT_EQ(*(it++), 8);
    EXPECT_EQ(*(it++), 9);
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 3);
    EXPECT_EQ(*(it++), 4);
    EXPECT_TRUE(it == mine.end());
}

TEST_F(ListOperationsTests, splice_with_one_empty) {
    ft::list<int> other;
    other.push_back(1);
    other.push_back(4);
    other.push_back(10);
    other.push_back(11);
    other.push_back(15);

    ft::list<int>::iterator it = mine.begin();
    mine.splice(it, other);
    it = mine.begin();
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

TEST_F(ListOperationsTests, splice_with_both_empty) {
    ft::list<int> other;

    ft::list<int>::iterator other_it = other.begin();
    ft::list<int>::iterator it = mine.begin();
    mine.splice(it, other);
    EXPECT_TRUE(other_it == other.end());
    EXPECT_TRUE(it == mine.end());
    EXPECT_EQ(mine.size(), 0);
    EXPECT_EQ(other.size(), 0);
}


TEST_F(ListOperationsTests, splice_with_other_it) {
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

    ft::list<int>::iterator it = mine.begin();
    it++;
    ft::list<int>::iterator other_it = other.begin();
    other_it++;
    mine.splice(it, other, other_it);
    EXPECT_EQ(mine.size(), 8);
    EXPECT_EQ(other.size(), 1);
    it = mine.begin();
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 3);
    EXPECT_EQ(*(it++), 6);
    EXPECT_EQ(*(it++), 7);
    EXPECT_EQ(*(it++), 9);
    EXPECT_EQ(*(it++), 4);
    EXPECT_EQ(*(it++), 5);
    EXPECT_EQ(*(it++), 8);
    EXPECT_TRUE(it == mine.end());
    other_it = other.begin();
    EXPECT_EQ(*(other_it++), 2);
    EXPECT_TRUE(other_it == other.end());
}

TEST_F(ListOperationsTests, splice_with_other_it_reverse_iterating_valid) {
    mine.push_back(1);
    mine.push_back(2);

    ft::list<int> other;
    other.push_back(4);
    other.push_back(3);

    ft::list<int>::iterator it = mine.begin();
    it++;
    ft::list<int>::iterator other_it = other.begin();
    other_it++;
    mine.splice(it, other, other_it);
    EXPECT_EQ(mine.size(), 3);
    EXPECT_EQ(other.size(), 1);
    it = mine.end();
    EXPECT_EQ(*(--it), 2);
    EXPECT_EQ(*(--it), 3);
    EXPECT_EQ(*(--it), 1);
    EXPECT_TRUE(it == mine.begin());
    other_it = other.end();
    EXPECT_EQ(*(--other_it), 4);
    other_it--;
    EXPECT_TRUE(other_it == other.end());
}


TEST_F(ListOperationsTests, splice_with_other_it_iterator_stays_validated) {
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

    ft::list<int>::iterator it = mine.begin();
    it++;
    it++;
    ft::list<int>::iterator other_it = other.begin();
    other_it++;
    mine.splice(it, other, other_it);
    EXPECT_EQ(mine.size(), 8);
    EXPECT_EQ(other.size(), 1);
    EXPECT_EQ(*(it++), 5);
    EXPECT_EQ(*(it--), 8);
    EXPECT_EQ(*(it--), 5);
    EXPECT_EQ(*(it--), 9);
    EXPECT_EQ(*(it--), 7);
    EXPECT_EQ(*(it--), 6);
    EXPECT_EQ(*(it--), 3);
    EXPECT_EQ(*(it--), 4);
    EXPECT_EQ(*(it--), 2);
    it++;
    EXPECT_TRUE(it == mine.begin());
    other_it = other.begin();
    EXPECT_EQ(*(other_it++), 1);
    EXPECT_TRUE(other_it == other.end());
}

TEST_F(ListOperationsTests, splice_with_other_it_at_end) {
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

    ft::list<int>::iterator it = mine.end();
    ft::list<int>::iterator other_it = other.begin();
    other_it++;
    mine.splice(it, other, other_it);
    other_it = other.begin();
    EXPECT_EQ(mine.size(), 8);
    EXPECT_EQ(other.size(), 1);
    it = mine.begin();
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 3);
    EXPECT_EQ(*(it++), 4);
    EXPECT_EQ(*(it++), 6);
    EXPECT_EQ(*(it++), 7);
    EXPECT_EQ(*(it++), 8);
    EXPECT_EQ(*(it++), 9);
    EXPECT_TRUE(it == mine.end());
    EXPECT_EQ(*(other_it++), 5);
    EXPECT_TRUE(other_it == other.end());
}

TEST_F(ListOperationsTests, splice_with_other_it_at_begin) {
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
    ft::list<int>::iterator other_it = other.begin();
    other_it++;
    mine.splice(it, other, other_it);
    it = mine.begin();
    other_it = other.begin();
    EXPECT_EQ(mine.size(), 8);
    EXPECT_EQ(other.size(), 1);
    EXPECT_EQ(*(it++), 6);
    EXPECT_EQ(*(it++), 7);
    EXPECT_EQ(*(it++), 8);
    EXPECT_EQ(*(it++), 9);
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 3);
    EXPECT_EQ(*(it++), 4);
    EXPECT_TRUE(it == mine.end());
    EXPECT_EQ(*(other_it++), 5);
    EXPECT_TRUE(other_it == other.end());
}

TEST_F(ListOperationsTests, splice_with_other_it_with_one_empty) {
    ft::list<int> other;
    other.push_back(1);
    other.push_back(4);
    other.push_back(10);
    other.push_back(11);
    other.push_back(15);

    ft::list<int>::iterator it = mine.begin();
    ft::list<int>::iterator other_it = other.begin();
    other_it++;
    mine.splice(it, other, other_it);
    other_it = other.begin();
    it = mine.begin();
    EXPECT_EQ(*(it++), 4);
    EXPECT_EQ(*(it++), 10);
    EXPECT_EQ(*(it++), 11);
    EXPECT_EQ(*(it++), 15);
    EXPECT_TRUE(it == mine.end());
    EXPECT_EQ(*(other_it++), 1);
    EXPECT_TRUE(other_it == other.end());
    EXPECT_EQ(mine.size(), 4);
    EXPECT_EQ(other.size(), 1);
    // EXPECT_EQ(other.begin(), other.end());
}

TEST_F(ListOperationsTests, splice_with_other_it_with_both_empty) {
    ft::list<int> other;

    ft::list<int>::iterator it = mine.begin();
    ft::list<int>::iterator other_it = other.begin();
    mine.splice(it, other, other_it);
    EXPECT_TRUE(other_it == other.end());
    EXPECT_TRUE(it == mine.end());
    EXPECT_EQ(mine.size(), 0);
    EXPECT_EQ(other.size(), 0);
}

TEST_F(ListOperationsTests, splice_with_other_it_rest_remains) {
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
    ft::list<int>::iterator other_it = other.begin();
    other_it++;
    mine.splice(it, other, other_it);
    it = mine.begin();
    other_it = other.begin();
    EXPECT_EQ(mine.size(), 8);
    EXPECT_EQ(other.size(), 1);
    EXPECT_EQ(*(it++), 6);
    EXPECT_EQ(*(it++), 7);
    EXPECT_EQ(*(it++), 8);
    EXPECT_EQ(*(it++), 9);
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 3);
    EXPECT_EQ(*(it++), 4);
    EXPECT_TRUE(it == mine.end());
    EXPECT_EQ(*(other_it++), 5);
    EXPECT_TRUE(other_it == other.end());
}

TEST_F(ListOperationsTests, splice_with_first_to_last_it) {
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

    ft::list<int>::iterator it = mine.begin();
    it++;
    ft::list<int>::iterator other_it = other.begin();
    other_it++;
    mine.splice(it, other, other_it, --(other.end()));
    EXPECT_EQ(mine.size(), 7);
    EXPECT_EQ(other.size(), 2);
    it = mine.begin();
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 3);
    EXPECT_EQ(*(it++), 6);
    EXPECT_EQ(*(it++), 7);
    EXPECT_EQ(*(it++), 4);
    EXPECT_EQ(*(it++), 5);
    EXPECT_EQ(*(it++), 8);
    EXPECT_TRUE(it == mine.end());
    other_it = other.begin();
    EXPECT_EQ(*(other_it++), 2);
    EXPECT_EQ(*(other_it++), 9);
    EXPECT_TRUE(other_it == other.end());
}

TEST_F(ListOperationsTests, splice_with_first_to_last_it_iterator_stays_validated) {
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

    ft::list<int>::iterator it = mine.begin();
    it++;
    it++;
    ft::list<int>::iterator other_it = other.begin();
    other_it++;
    mine.splice(it, other, other_it, --(other.end()));
    EXPECT_EQ(mine.size(), 7);
    EXPECT_EQ(other.size(), 2);
    EXPECT_EQ(*(it++), 5);
    EXPECT_EQ(*(it--), 8);
    EXPECT_EQ(*(it--), 5);
    EXPECT_EQ(*(it--), 7);
    EXPECT_EQ(*(it--), 6);
    EXPECT_EQ(*(it--), 3);
    EXPECT_EQ(*(it--), 4);
    EXPECT_EQ(*(it--), 2);
    it++;
    EXPECT_TRUE(it == mine.begin());
    other_it = other.begin();
    EXPECT_EQ(*(other_it++), 1);
    EXPECT_EQ(*(other_it++), 9);
    EXPECT_TRUE(other_it == other.end());
}

TEST_F(ListOperationsTests, splice_with_first_to_last_it_at_end) {
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

    ft::list<int>::iterator it = mine.end();
    ft::list<int>::iterator other_it = other.begin();
    other_it++;
    mine.splice(it, other, other_it, --(other.end()));
    EXPECT_EQ(mine.size(), 7);
    EXPECT_EQ(other.size(), 2);
    it = mine.begin();
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 3);
    EXPECT_EQ(*(it++), 4);
    EXPECT_EQ(*(it++), 6);
    EXPECT_EQ(*(it++), 7);
    EXPECT_EQ(*(it++), 8);
    EXPECT_TRUE(it == mine.end());
    other_it = other.begin();
    EXPECT_EQ(*(other_it++), 5);
    EXPECT_EQ(*(other_it++), 9);
    EXPECT_TRUE(other_it == other.end());
}

TEST_F(ListOperationsTests, splice_with_first_to_last_it_at_begin) {
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
    ft::list<int>::iterator other_it = other.begin();
    other_it++;
    mine.splice(it, other, other_it, --(other.end()));
    it = mine.begin();
    EXPECT_EQ(mine.size(), 7);
    EXPECT_EQ(other.size(), 2);
    EXPECT_EQ(*(it++), 6);
    EXPECT_EQ(*(it++), 7);
    EXPECT_EQ(*(it++), 8);
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 3);
    EXPECT_EQ(*(it++), 4);
    EXPECT_TRUE(it == mine.end());
    other_it = other.begin();
    EXPECT_EQ(*(other_it++), 5);
    EXPECT_EQ(*(other_it++), 9);
    EXPECT_TRUE(other_it == other.end());
}

TEST_F(ListOperationsTests, splice_with_first_to_last_it_with_one_empty) {
    ft::list<int> other;
    other.push_back(1);
    other.push_back(4);
    other.push_back(10);
    other.push_back(11);
    other.push_back(15);

    ft::list<int>::iterator it = mine.begin();
    ft::list<int>::iterator other_it = other.begin();
    other_it++;
    mine.splice(it, other, other_it, --(other.end()));
    it = mine.begin();
    EXPECT_EQ(*(it++), 4);
    EXPECT_EQ(*(it++), 10);
    EXPECT_EQ(*(it++), 11);
    EXPECT_TRUE(it == mine.end());
    EXPECT_EQ(mine.size(), 3);
    EXPECT_EQ(other.size(), 2);
    other_it = other.begin();
    EXPECT_EQ(*(other_it++), 1);
    EXPECT_EQ(*(other_it++), 15);
    EXPECT_TRUE(other_it == other.end());
}

TEST_F(ListOperationsTests, splice_with_first_to_last_it_with_both_empty) {
    ft::list<int> other;

    ft::list<int>::iterator it = mine.begin();
    ft::list<int>::iterator other_it = other.begin();
    mine.splice(it, other, other_it, --(other.end()));
    EXPECT_TRUE(other_it == other.end());
    EXPECT_TRUE(it == mine.end());
    EXPECT_EQ(mine.size(), 0);
    EXPECT_EQ(other.size(), 0);
}

TEST_F(ListOperationsTests, splice_with_first_to_last_it_at_begin_rest_remains) {
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
    ft::list<int>::iterator other_it = other.begin();
    other_it++;
    mine.splice(it, other, other_it, --(other.end()));
    it = mine.begin();
    other_it = other.begin();
    EXPECT_EQ(mine.size(), 7);
    EXPECT_EQ(other.size(), 2);
    EXPECT_EQ(*(it++), 6);
    EXPECT_EQ(*(it++), 7);
    EXPECT_EQ(*(it++), 8);
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 3);
    EXPECT_EQ(*(it++), 4);
    EXPECT_TRUE(it == mine.end());
    EXPECT_EQ(*(other_it++), 5);
    EXPECT_EQ(*(other_it++), 9);
    EXPECT_TRUE(other_it == other.end());
}

TEST_F(ListOperationsTests, splice_with_first_to_last_it_reverse_iterating_valid) {
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
    ft::list<int>::iterator other_it = other.begin();
    other_it++;
    mine.splice(it, other, other_it, --(other.end()));
    it = mine.end();
    other_it = other.end();
    EXPECT_EQ(mine.size(), 7);
    EXPECT_EQ(other.size(), 2);
    EXPECT_EQ(*(--it), 4);
    EXPECT_EQ(*(--it), 3);
    EXPECT_EQ(*(--it), 2);
    EXPECT_EQ(*(--it), 1);
    EXPECT_EQ(*(--it), 8);
    EXPECT_EQ(*(--it), 7);
    EXPECT_EQ(*(--it), 6);
    it--;
    EXPECT_TRUE(it == mine.end());
    EXPECT_EQ(*(--other_it), 9);
    EXPECT_EQ(*(--other_it), 5);
    EXPECT_TRUE(other_it == other.begin());
}

//
//
// remove
// remove_if
//
//
// reverse

TEST_F(ListOperationsTests, reverse) {
    mine.push_back(1);
    mine.push_back(2);
    mine.push_back(3);
    mine.push_back(4);
    mine.push_back(5);

    mine.reverse();
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 5);
    EXPECT_EQ(*(it++), 4);
    EXPECT_EQ(*(it++), 3);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 1);
    EXPECT_TRUE(it == mine.end());
}

TEST_F(ListOperationsTests, reverse_iterator_stay_valid) {
    mine.push_back(1);
    mine.push_back(2);
    mine.push_back(3);
    mine.push_back(4);
    mine.push_back(5);

    ft::list<int>::iterator it = mine.begin();
    it++;
    it++;
    mine.reverse();
    ft::list<int>::iterator it2 = it;
    EXPECT_EQ(*(it2--), 3);
    EXPECT_EQ(*(it2--), 4);
    EXPECT_EQ(*(it2--), 5);

    EXPECT_EQ(*(it++), 3);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 1);
    EXPECT_TRUE(it == mine.end());
}

TEST_F(ListOperationsTests, reverse_on_empty) {
    mine.reverse();
    ft::list<int>::iterator it = mine.begin();
    EXPECT_TRUE(it == mine.end());
}


//
//
// unique
TEST_F(ListOperationsTests, unique) {
    mine.push_back(1);
    mine.push_back(1);
    mine.push_back(2);
    mine.push_back(2);
    mine.push_back(2);
    mine.push_back(3);
    mine.push_back(4);
    mine.push_back(4);
    mine.push_back(4);
    mine.push_back(2);
    mine.push_back(5);
    mine.push_back(4);

    mine.unique();
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 3);
    EXPECT_EQ(*(it++), 4);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 5);
    EXPECT_EQ(*(it++), 4);
    EXPECT_TRUE(it == mine.end());
}

TEST_F(ListOperationsTests, unique_iterator_stays_valid) {
    mine.push_back(1);
    mine.push_back(1);
    mine.push_back(2);
    mine.push_back(2);
    mine.push_back(2);
    mine.push_back(3);
    mine.push_back(4);
    mine.push_back(4);
    mine.push_back(4);
    mine.push_back(2);
    mine.push_back(5);
    mine.push_back(4);

    ft::list<int>::iterator it = mine.begin();
    mine.unique();
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 3);
    EXPECT_EQ(*(it++), 4);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 5);
    EXPECT_EQ(*(it++), 4);
    EXPECT_TRUE(it == mine.end());
}

bool comp(int first, int second) {return first == second;}
TEST_F(ListOperationsTests, unique_with_compare_function) {
    mine.push_back(1);
    mine.push_back(1);
    mine.push_back(2);
    mine.push_back(2);
    mine.push_back(2);
    mine.push_back(3);
    mine.push_back(4);
    mine.push_back(4);
    mine.push_back(4);
    mine.push_back(2);
    mine.push_back(5);
    mine.push_back(4);

    mine.unique(comp);
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 3);
    EXPECT_EQ(*(it++), 4);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 5);
    EXPECT_EQ(*(it++), 4);
    EXPECT_TRUE(it == mine.end());
}

TEST_F(ListOperationsTests, unique_with_compare_funciton_iterator_stays_valid) {
    mine.push_back(1);
    mine.push_back(1);
    mine.push_back(2);
    mine.push_back(2);
    mine.push_back(2);
    mine.push_back(3);
    mine.push_back(4);
    mine.push_back(4);
    mine.push_back(4);
    mine.push_back(2);
    mine.push_back(5);
    mine.push_back(4);

    ft::list<int>::iterator it = mine.begin();
    mine.unique(comp);
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 3);
    EXPECT_EQ(*(it++), 4);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 5);
    EXPECT_EQ(*(it++), 4);
    EXPECT_TRUE(it == mine.end());
}

//
//
// sort
TEST_F(ListOperationsTests, sort) {
    mine.push_back(4);
    mine.push_back(4);
    mine.push_back(4);
    mine.push_back(1);
    mine.push_back(3);
    mine.push_back(3);
    mine.push_back(2);
    mine.push_back(5);

    mine.sort();
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 3);
    EXPECT_EQ(*(it++), 3);
    EXPECT_EQ(*(it++), 4);
    EXPECT_EQ(*(it++), 4);
    EXPECT_EQ(*(it++), 4);
    EXPECT_EQ(*(it++), 5);
    EXPECT_TRUE(it == mine.end());
}

TEST_F(ListOperationsTests, sort_iterator_stays_valid) {
    mine.push_back(4);
    mine.push_back(1);
    mine.push_back(3);
    mine.push_back(2);
    mine.push_back(5);

    ft::list<int>::iterator it = mine.begin();
    mine.sort();
    EXPECT_EQ(*(it++), 4);
    EXPECT_EQ(*(it++), 5);
    EXPECT_EQ(*(--it), 5);
    EXPECT_EQ(*(--it), 4);
    EXPECT_EQ(*(--it), 3);
    EXPECT_EQ(*(--it), 2);
    EXPECT_EQ(*(--it), 1);
    EXPECT_TRUE(it == mine.begin());
}

TEST_F(ListOperationsTests, sort_on_empty_list) {
    ft::list<int>::iterator it = mine.begin();
    mine.sort();
    EXPECT_TRUE(it == mine.begin());
    EXPECT_EQ(mine.size(), 0);
}

TEST_F(ListOperationsTests, sort_with_compare_func) {
    mine.push_back(4);
    mine.push_back(4);
    mine.push_back(4);
    mine.push_back(1);
    mine.push_back(3);
    mine.push_back(3);
    mine.push_back(2);
    mine.push_back(5);

    mine.sort(std::greater<>());
    ft::list<int>::iterator it = mine.begin();
    EXPECT_EQ(*(it++), 5);
    EXPECT_EQ(*(it++), 4);
    EXPECT_EQ(*(it++), 4);
    EXPECT_EQ(*(it++), 4);
    EXPECT_EQ(*(it++), 3);
    EXPECT_EQ(*(it++), 3);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 1);
    EXPECT_TRUE(it == mine.end());
}

TEST_F(ListOperationsTests, sort_with_compare_func_iterator_stays_valid) {
    mine.push_back(4);
    mine.push_back(1);
    mine.push_back(3);
    mine.push_back(2);
    mine.push_back(5);

    ft::list<int>::iterator it = mine.begin();
    mine.sort(std::greater<>());
    EXPECT_EQ(*(it--), 4);
    EXPECT_EQ(*(it--), 5);
    EXPECT_EQ(*(++it), 5);
    EXPECT_EQ(*(++it), 4);
    EXPECT_EQ(*(++it), 3);
    EXPECT_EQ(*(++it), 2);
    EXPECT_EQ(*(++it), 1);
    it++;
    EXPECT_TRUE(it == mine.end());
}

TEST_F(ListOperationsTests, sort_with_compare_func_on_empty_list) {
    ft::list<int>::iterator it = mine.begin();
    mine.sort(std::greater<>());
    EXPECT_TRUE(it == mine.begin());
    EXPECT_EQ(mine.size(), 0);
}










