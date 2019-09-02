#pragma once
//Header for the Node class by Gauthier FALISE C3338389


#ifndef GF_Node
#define GF_Node
#include "Student.h";
#include <cstddef>

class Node
{
public:
	typedef Student value_type;
	Node(value_type* initial_value = NULL, Node* p = NULL, Node* n = NULL);
	~Node();

	//Getters and setters that all look the same way in the header
	void set_next(Node* next_ptr);
	void set_prev(Node* previous_ptr);
	void set_data(value_type value);
	Node* get_next() const;
	Node* get_prev() const;
	value_type* get_data() const;
private:
	value_type* data;
	Node* previous;
	Node* next;
};
#endif


