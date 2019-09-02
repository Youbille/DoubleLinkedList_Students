#include "Node.h"
#include <cstddef>

//Precon:
//Postcon : Creates a Node object with 3 pointers to the date, next node and previous node
Node::Node(value_type* i, Node* p, Node* n)
{
	data = i;
	previous = p;
	next = n;
}

//precon : 
//Postcon : pointers and what the point to have been deleted
Node::~Node()
{
	if (data != NULL) { delete (data); }
	if (next != NULL) { delete (next); }
	if (previous != NULL) { delete (previous); }
	//You can't call delete on a NULL pointer	
}

//Precon of all setters : the pointer exists
//postcon : We've set the pointer to what we wanted
void Node::set_next(Node* next_ptr)
{
	next = next_ptr;
}

void Node::set_prev(Node* previous_ptr)
{
	previous = previous_ptr;
}

void Node::set_data(value_type value)
{
	value_type* value_ptr = &value;
	data = value_ptr;
}

//Precon of all getters : The value exists
//Postcon: return the value
Node* Node::get_next() const
{
	return next;
}

Node* Node::get_prev() const
{
	return previous;
}

Node::value_type* Node::get_data() const
{
	return data;
}


