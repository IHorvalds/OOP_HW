#pragma once
#include "Object.h"
#include <istream>
#include <ostream>

struct Element {
	Object* obiect;
	Element* next;

	Element(Object* obj_ptr) {
		this->obiect = new Object(*obj_ptr);
		this->next = NULL;
	}
	Element(const Element& e_ref) {
		this->obiect = new Object(*(e_ref.obiect));
		this->next = NULL;
	}
	~Element() {
		delete this->obiect;
		this->obiect = NULL;
	}
};

class Stack
{
private:
	Element* top;
	size_t size = 0;

public:
	Stack();
	Stack(const Stack& st);
	~Stack();

	bool isVoid();
	bool Empty();
	void Push(Element* e);
	size_t GetSize();
	Element Pop();
	Stack& reverse();

	friend std::istream& operator >> (std::istream& istream, Stack& st);
	friend std::ostream& operator << (std::ostream& istream, const Stack& st);
};
