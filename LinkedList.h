
#ifndef LkList_C3338389
#define LkList_C3338389
#pragma once
#include "Node.h"

class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	void addToTail(Node::value_type data);
	void addToHead(Node::value_type data);
	bool list_is_empty();
	Node search_in_list(Node::value_type data);
	void remove(string data_name);

	Node* get_head() const;
	Node* get_tail() const;
	Node* get_current() const;
	void set_current(Node*);

private:
	Node* Head;
	Node* Tail;
	Node* Current;

};

ostream& operator <<(ostream&, const LinkedList l1);
#endif



