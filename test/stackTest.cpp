#include <gtest/gtest.h>
#include "Stack.h"

class StackTest: public testing::Test {
	public:
		Stack<int>* s;

		void SetUp() {
		}
		void TearDown() {
		}

};

TEST_F(StackTest, InitStack) {
	s = new Stack<int>;
	ASSERT_TRUE(s->top() == nullptr);
}
