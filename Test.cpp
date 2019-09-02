#include "LinkedList.h"

int main()
{
	Node* test = new Node;
	cout << test->get_data() << endl;
	cout << test->get_next() << endl;
	Student student_ex = Student("Jean", 15);
	test->set_data(student_ex);
	cout << *test->get_data();
	LinkedList l1;
	
	//l1.addToHead(x);
	//x.set_name("Georgette");
	//x.set_score(94);
	//l1.addToHead(x);
	//x.set_name("Alfred");
	//x.set_score(12);
	//l1.addToHead(x);

	return 0;
}
