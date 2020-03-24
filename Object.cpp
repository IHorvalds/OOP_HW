#include "Object.h"
#include <string>
#include <iomanip>
#include <algorithm>

Object::Object() {
	this->size = 0;
	this->content = NULL;
}

Object::Object(size_t size) {
	this->size = size;
	this->content = (void*) new char[size] { 0 };
}

Object::Object(const Object& ob_ref) {
	this->size = ob_ref.size;
	this->content = (void*) new char[size] { 0 };
	if (ob_ref.content != NULL) {
		memcpy(this->content, ob_ref.content, ob_ref.size);
	}
}

Object::~Object() {
	delete this->content;
	this->content = NULL;
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
	if (value.size() != (2 * size)) {
		throw std::range_error("Please pad the input to the correct size");
	}

	for (int i = 0; i < size; i++) {
		memset((char*)ob.content + i, std::stoi(value.substr(i*2, 2), nullptr, 16), 1);
	}
	return istream;
}

std::ostream& operator << (std::ostream& ostream, const Object& ob) {
	ostream << (int)ob.size << " 0x" << std::hex;

	for (size_t iter = 0; iter < ob.size; iter++) {
		ostream << std::setw(2) << (unsigned int)(*((unsigned char*)ob.content + iter));
	}

	return ostream << std::dec;
}

bool operator == (Object& lhs, Object& rhs) {

	if (lhs.size == rhs.size) {
		return memcmp(lhs.content, rhs.content, lhs.size) == 0;
	}
	else {
		return false;
	}
}

bool operator != (Object& lhs, Object& rhs) {

	if (lhs.size != rhs.size) {
		return true;
	}
	else {
		return memcmp(lhs.content, rhs.content, lhs.size) != 0;
	}
}

bool operator >= (Object& lhs, Object& rhs) {

	if (lhs.size < rhs.size) {
		return false;
	}
	else {
		return memcmp(lhs.content, rhs.content, rhs.size) >= 0;
	}

}

bool operator >  (Object& lhs, Object& rhs) {

	if (lhs.size < rhs.size) {
		return false;
	}
	else {
		return memcmp(lhs.content, rhs.content, lhs.size) > 0;
	}

}
bool operator <= (Object& lhs, Object& rhs) {

	if (lhs.size > rhs.size) {
		return false;
	}
	else {
		return memcmp(lhs.content, rhs.content, lhs.size) <= 0;
	}

}
bool operator <  (Object& lhs, Object& rhs) {

	if (lhs.size > rhs.size) {
		return false;
	}
	else {
		return memcmp(lhs.content, rhs.content, lhs.size) < 0;
	}
	
}