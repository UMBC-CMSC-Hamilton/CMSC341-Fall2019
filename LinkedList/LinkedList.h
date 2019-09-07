#pragma once

#include "ListNode.h"

class LinkedList
{
	public:
		LinkedList();
		~LinkedList();
		void insert(int pos, int val);
		void delete_node(int pos);
		bool find(int val);
		void print_list();

	private:
		ListNode * m_head;
};

