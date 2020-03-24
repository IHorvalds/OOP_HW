#pragma once
#include "Object.h"

struct Element {
	Object* obiect;
	Element* next;

	Element(Object* obj_ptr) {
		this->obiect = new Object(*obj_ptr);
		this->next = NULL;
	}
	~Element() {
		delete this->obiect;
		delete this->next;
	}
};

class Stack
{
private:
	Element* top;

public:
	Stack();
	Stack(const Stack& st);
	~Stack();

	bool isVoid();
	void Push(Element* e);
	Element Pop();
	Stack& reverse();
};
