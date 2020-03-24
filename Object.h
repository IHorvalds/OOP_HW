#pragma once
#include <ostream>
#include <istream>

class Object
{
private:
	void* content;
	size_t size;
public:
	Object(size_t size);
	Object(const Object& ob_ref);
	~Object();

	size_t GetSize();
	size_t SetContent(void* content, size_t size_of_content);

	friend std::ostream& operator <<(std::ostream& ostream, const Object& ob);
	friend std::istream& operator >>(std::istream& istream, Object& ob);
	friend bool operator == (Object& lhs, Object& rhs);
	friend bool operator != (Object& lhs, Object& rhs);
	friend bool operator >= (Object& lhs, Object& rhs);
	friend bool operator >  (Object& lhs, Object& rhs);
	friend bool operator <= (Object& lhs, Object& rhs);
	friend bool operator <  (Object& lhs, Object& rhs);

};

