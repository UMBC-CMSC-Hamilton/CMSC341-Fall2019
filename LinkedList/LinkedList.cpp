#include "LinkedList.h"



LinkedList::LinkedList()
	: m_head(nullptr)
{
}


LinkedList::LinkedList(const LinkedList& src)
{
	ListNode * p_node = src.m_head;
	ListNode * p_dest;
	if(p_node)
	{
		m_head = new ListNode(src.m_head->m_data);
		p_dest = m_head;
		p_node = p_node->m_next;
	}
	
	while (p_node)
	{
		p_dest->m_next = new ListNode(p_node->m_data);
		p_dest = p_dest->m_next;
		p_node = p_node->m_next;
	}
}

LinkedList::~LinkedList()
{
	ListNode * p_current = m_head;
	ListNode * p_prev = nullptr;
	while (p_current)
	{
		if (p_prev)
		{
			delete p_prev;
		}
		p_prev = p_current;
		p_current = p_current->m_next;
	}
	if (p_prev)
	{
		delete p_prev;
	}
}

void LinkedList::insert(int pos, int val) 
{
	ListNode * prev = nullptr;
	ListNode * current = m_head;

	ListNode * p_insert = new ListNode(val);

	for (int i = 0; i < pos; i++)
	{
		if (current->m_next)
		{
			prev = current;
			current = current->m_next;
		}
	}
	// insert the node here
	if (pos == 0)
	{
		p_insert->m_next = current;
		m_head = p_insert;
	}
	else
	{
		prev->m_next = p_insert;
		p_insert->m_next = current;

	}
}
void LinkedList::delete_node(int pos)
{
	ListNode * prev = nullptr;
	ListNode * current = m_head;

	for (int i = 0; i < pos; i++)
	{
		if (current->m_next)
		{
			prev = current;
			current = current->m_next;
		}
		else
		{
			return;
		}
	}
	if (prev && current)
	{
		prev->m_next = current->m_next;
		delete current;
	}
	else if (current)
	{
		m_head = current->m_next;
		delete current;
	}
	else
	{
		// empty list
		// you can throw an exception.  
	}

	delete current;

}

bool LinkedList::find(int val)
{
	ListNode * p_current = m_head;
	while (p_current)
	{
		if (p_current->m_data == val)
		{
			return true;
		}
		p_current = p_current->m_next;
	}
	return false;
}

void print_list()
{

}