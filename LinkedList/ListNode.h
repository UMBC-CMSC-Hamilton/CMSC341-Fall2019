#pragma once
class ListNode
{
	public:
	ListNode(int data = 0)
		: m_next(nullptr), m_data(data)
	{

	}
	~ListNode();
	ListNode * m_next;
	int m_data;
};

