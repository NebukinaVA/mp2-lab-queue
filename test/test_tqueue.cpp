#include "tqueue.h"

#include <gtest.h>

TEST(TQueue, can_create_queue)
{
	ASSERT_NO_THROW(TQueue<int> s);
}

TEST(TQueue, can_push)
{
	TQueue<int> q;
	ASSERT_NO_THROW(q.Push(1));
}

TEST(TQueue, can_pop)
{
	TQueue<int> q(5);
	q.Push(1);
	ASSERT_NO_THROW(q.Pop());
}

TEST(TQueue, throws_when_pop_from_empty_queue)
{
	TQueue<int> q;
	ASSERT_ANY_THROW(q.Pop());
}
/*
TEST(TQueue, no_throw_when_push_into_full_queue)
{
	TQueue<int> q(5);
	q.Push(1);
	q.Push(2);
	q.Push(3);
	q.Push(4);
	q.Push(5);
	ASSERT_NO_THROW(q.Push(0));
}
*/
TEST(TQueue, can_check_if_empty)
{
	TQueue<int> q;
	EXPECT_TRUE(q.IsEmpty());
}

TEST(TQueue, can_check_if_not_full)
{
	TQueue<int> q;
	q.Push(1);
	EXPECT_FALSE(q.IsFull());
}

TEST(TQueue, can_check_if_full)
{
	TQueue<int> q(5);
	q.Push(1);
	q.Push(2);
	q.Push(3);
	q.Push(4);
	q.Push(5);
	EXPECT_TRUE(q.IsFull());
}