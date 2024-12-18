#include <gtest/gtest.h>
#include <list>
#include <list.hpp>

class ListTestBaseFixture : public ::testing::Test {
    public:
        ft::list<int>   mine;
        std::list<int>  orig;

        void init_fill(std::size_t size) {
            for(std::size_t i = 0; i < size ; i++) {
                mine.push_back(i);
                orig.push_back(i);
            }
            EXPECT_EQ(mine.size(), orig.size());
            EXPECT_EQ(mine.empty(), orig.empty());
        }

        template <typename IteratorType1, typename IteratorType2>
        void increment_iterator(IteratorType1& my_it, IteratorType2& orig_it, size_t count = 1) {
            for (std::size_t i = 0; i < count; i++) {
                my_it++;
                orig_it++;
            }
        }

        template <typename IteratorType1, typename IteratorType2>
        void decrement_iterator(IteratorType1& my_it, IteratorType2& orig_it, size_t count = 1) {
            for (std::size_t i = 0; i < count; i++) {
                my_it--;
                orig_it--;
            }
        }

        void quick_capacity_check() {
            EXPECT_EQ(mine.size(), orig.size());
            EXPECT_EQ(mine.empty(), orig.empty());
        }

        void push_back(const int val) {
            mine.push_back(val);
            orig.push_back(val);
        }

        void push_front(const int val) {
            mine.push_front(val);
            orig.push_front(val);
        }

        void pop_back() {
            mine.pop_back();
            orig.pop_back();
        }

        void pop_front() {
            mine.pop_front();
            orig.pop_front();
        }

        void clear() {
            mine.clear();
            orig.clear();
        }

        void resize(std::size_t count, int val) {
            mine.resize(count, val);
            orig.resize(count, val);
        }

        void front_back_compare() {
            EXPECT_EQ(mine.front(), orig.front());
            EXPECT_EQ(mine.back(), orig.back());
        }
};
