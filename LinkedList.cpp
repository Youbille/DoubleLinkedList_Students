//Linked List source file created by Gauthier FALISE C3338389

#include "LinkedList.h"
#include <cstddef>

//Precon : Initiates an empty Linked_List
LinkedList::LinkedList()
{
	Head = NULL;
	Tail = NULL;
	Current = NULL;
}

//Precon:  Linked List is not empty
//Postcon : All nodes of the LinkedList have been destroyed
LinkedList::~LinkedList()
{
	//while (Head != NULL)
	//{
	//	Node* temporary = Head->get_next(); //You create a temporary pointer that points to the next Node after the head
	//	delete Head;//You delete what the head actually point to
	//	Head = temporary;//You set the head to the pointer you created earlier
	//}
	while (Current != NULL)
	{
		delete Current;
		Current = Current->get_next();
	}
}


//Precon : The list exists and can be used
//Postcon : We have a new Node that is now being point at as the tail
void LinkedList::addToTail(Node::value_type data)
{
	Node* node_ptr = new Node();//this is weird
	node_ptr->set_data(data);
	if (list_is_empty())
	{
		Head = node_ptr;
		Tail = node_ptr;
	}
	else
	{
		Tail->set_next(node_ptr);
		node_ptr->set_prev(Tail);
		Tail = node_ptr;
	}
}

//Precon : The list exists and can be used
//Postcon : We have a new Node that is now being point at as the head
void LinkedList::addToHead(Node::value_type data)
{
	Node* node_ptr = new Node();//this is weird
	node_ptr->set_data(data); //this permanently links the data and the reference going with it
	if (list_is_empty())
	{
		Head = node_ptr;
		Tail = node_ptr; //could use a function to avoid repetition here
	}
	else
	{
		Head->set_prev(node_ptr);
		node_ptr->set_next(Head);
		Head = node_ptr;
	}
}

bool LinkedList::list_is_empty()
{
	return Head == NULL && Tail == NULL;
}

//Precon : list is not empty
//returns the first occurence of data researched
Node LinkedList::search_in_list(Node::value_type data)
{
	if (list_is_empty())
	{
		return NULL; //Here we have a problem since it will only work with student
	}
	else
	{
		if (*Head->get_data() == data)return *Head; //We need to check the Tail node because the loop doesn't check it
		Current = Head;
		while (Current != Tail)
		{
			if (*Current->get_data() == data)
			{
				return *Current;
			}
			Current = Current->get_next();
		}
	}
}

//Precon : LinkedList is not empty
//Postcon : all node that contains the wanted data_name have been destroyed
void LinkedList::remove(string data_name)
{
	Student data(data_name, 0); //This is not really what we're looking for, we would prefer to do a general remove function
	Node* node_to_destroy = &search_in_list(data);
	while (node_to_destroy != NULL)
	{
		node_to_destroy->get_data()->get_name() = search_in_list(data).get_data()->get_name();
		delete(node_to_destroy);
	}

}

Node* LinkedList::get_head() const
{
	return Head;
}
Node* LinkedList::get_tail() const
{
	return Tail;
}
Node* LinkedList::get_current() const
{
	return Current;
}

void LinkedList::set_current(Node* ptr)
{
	Current = ptr;
}

ostream& operator <<(ostream& os, LinkedList l1)
{
	os << *l1.get_head()->get_data() << endl; //just to print the head -test purposes
	//l1.set_current(l1.get_head());
	//while(l1.get_current() != NULL)
	//{
	//	os << *l1.get_current()->get_data() << "-";
	//}
	//os << endl;
	return os;
}


