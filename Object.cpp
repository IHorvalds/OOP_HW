#include "Object.h"
#include <string>

Object::Object(size_t size) {
	this->size = size;
	this->content = (void*) new char[size] { 0 };
}

Object::Object(const Object& ob_ref) {
	this->size = ob_ref.size;
	this->content = (void*) new char[size] { 0 };
	memcpy(this->content, ob_ref.content, ob_ref.size);
}

Object::~Object() {
	memset(this->content, 0, this->size); // nu lasam valori in urma
	delete this->content;
}

size_t Object::GetSize() {
	return this->size;
}

size_t Object::SetContent(void* newContent, size_t size_of_content) {
	if (size_of_content > this->size) {
		throw std::invalid_argument("New size of content too big for object at " + std::to_string((long long)this));
	}
	else {
		memcpy(this->content, newContent, size_of_content);
	}
}

// the format for the object is 
// %d 0x[0-A]
std::istream& operator >> (std::istream& istream, Object& ob) {
	std::string value;
	int size;

	istream >> size;
	ob.size = (size_t)size;

	ob.content = (void*) new char[size] { 0 };

	istream >> value;
	unsigned long long v = stoull(value, nullptr, 16);
	memcpy(ob.content, &v, ob.size);
	return istream;
}

std::ostream& operator << (std::ostream& ostream, const Object& ob) {
	ostream << (int)ob.size << ' ';
	ostream << std::hex << *((unsigned long long*)ob.content);

	return ostream;
}

bool operator == (Object& lhs, Object& rhs) {
	return *((unsigned long long*)lhs.content) == *((unsigned long long*)rhs.content);
}

bool operator != (Object& lhs, Object& rhs) {
	return *((unsigned long long*)lhs.content) != *((unsigned long long*)rhs.content);
}

bool operator >= (Object& lhs, Object& rhs) {
	return *((unsigned long long*)lhs.content) >= *((unsigned long long*)rhs.content);
}

bool operator >  (Object& lhs, Object& rhs) {
	return *((unsigned long long*)lhs.content) > *((unsigned long long*)rhs.content);
}
bool operator <= (Object& lhs, Object& rhs) {
	return *((unsigned long long*)lhs.content) <= *((unsigned long long*)rhs.content);
}
bool operator <  (Object& lhs, Object& rhs) {
	return *((unsigned long long*)lhs.content) < *((unsigned long long*)rhs.content);
}