#pragma once
#include "Student.h"
class Node : public Student {
private:
	Node* link;

public:
	Node(int id = 0, string name = "", string dept = "") :Student(id, name, dept) {
		link = NULL;
	}
	~Node(void){}

	Node* getLink() { return link; }

	void setLink(Node* p) { link = p; }

};