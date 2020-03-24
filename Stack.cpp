#include "Stack.h"

Stack::Stack() {
	this->top = NULL;
}

Stack::Stack(const Stack& st) {
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
	while (this->top->next != NULL) {
		Element* to_be_deleted = this->top; // copy pointer value
		this->top = this->top->next; //move pointer. The copied value doesn't change

		delete to_be_deleted;
	}

	delete this->top;
}

bool Stack::isVoid() {
	return (this->top == NULL);
}

void Stack::Push(Element* e) {
	e->next = this->top;
	this->top = e;
}

Element Stack::Pop()
{
	Element* ptr_to_return = this->top;
	this->top = this->top->next;
	Element to_return = *(ptr_to_return);
	delete ptr_to_return;

	return to_return;
}

Stack& Stack::reverse() {

}