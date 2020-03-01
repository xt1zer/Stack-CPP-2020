#include <gtest/gtest.h>
#include "Stack.h"

class StackTest: public testing::Test {
	public:
		Stack<int>* s;
		int size = 0;

		void SetUp() {
		}
		void TearDown() {
		}

};

TEST_F(StackTest, InitStack) {
	s = new Stack<int>;
	ASSERT_TRUE(!s->top());
}

TEST_F(StackTest, FillStack) {
	for (int i = 0; i < 50; ++i) {
		s->push(i);
		++size;
	}
	EXPECT_EQ(s->peek(), 49);
	ASSERT_EQ(size, 50);
}

TEST_F(StackTest, ClearStack) {
	s->clear();
	size = 0;
	ASSERT_EQ(s->isEmpty(), true);
}

TEST_F(StackTest, PushAndPop) {
	s->push(size++);
	int popped = s->pop();
	size = 0;

	ASSERT_EQ(popped, 0);
	ASSERT_EQ(s->pop(), INT32_MIN);
}
