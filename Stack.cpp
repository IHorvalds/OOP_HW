#include "Stack.h"
#include <iostream>

Stack::Stack() {
	this->top = NULL;
}

Stack::Stack(const Stack& st) {
	this->size = st.size;

	if (st.top != NULL) {
		this->top = new Element(st.top->obiect);
		Element* current = st.top;
		Element* current_copy = this->top;
		while (current->next != NULL) {

			current_copy->next = new Element(current->next->obiect);
			
			current_copy = current_copy->next;
			current = current->next;
		}
	}
	else {
		this->top = NULL;
	}
}

Stack::~Stack() {
	while (this->top != NULL) {
		Element* to_be_deleted = this->top; // copy pointer value
		this->top = this->top->next; //move pointer. The copied value doesn't change

		delete to_be_deleted;
		to_be_deleted = NULL;
		this->size--;
	}
}


std::istream& operator >> (std::istream& istream, Stack& st) {
	int size;
	istream >> size;

	for (int i = 0; i < size; i++) {
		Object ob;
		istream >> ob;
		st.Push(new Element(&ob));
	}

	return istream;
}

std::ostream& operator << (std::ostream& ostream, const Stack& st) {
	Element* current = st.top;

	int i = 1;
	while (current != NULL) {
		ostream << i << ". " << *(current->obiect) << '\n';
		i++;
		current = current->next;
	}

	delete current;
	current = NULL;
	return ostream;
}

size_t Stack::GetSize() {
	return this->size;
}


bool Stack::isVoid() {
	return (this->top == NULL);
}

bool Stack::Empty() {
	while (this->top != NULL) {
		this->Pop();
	}
	return this->isVoid();
}

void Stack::Push(Element* e) {
	e->next = this->top;
	this->top = e;
	this->size++;
}

Element Stack::Pop()
{
	Element* ptr_to_return = this->top;
	Element to_return = *(this->top);

	this->top = this->top->next;
	delete ptr_to_return;
	ptr_to_return = NULL;
	this->size--;

	return to_return;
}

Stack& Stack::reverse() {

	Stack* revStack = new Stack(*this); // make a copy so we can return the same object

	while (this->top != NULL) {
		this->Pop();
	}

	do {
		Element* e = new Element((revStack->Pop()));
		e->next = NULL;
		this->Push(e);
	} while (revStack->top != NULL);


	delete revStack;
	revStack = NULL;

	return *(this);
}