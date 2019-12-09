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

TEST(TQueue, throws_when_push_into_full_queue)
{
	TQueue<int> q(3);
	q.Push(1);
	q.Push(2);
	q.Push(3);
	ASSERT_ANY_THROW(q.Push(4));
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
