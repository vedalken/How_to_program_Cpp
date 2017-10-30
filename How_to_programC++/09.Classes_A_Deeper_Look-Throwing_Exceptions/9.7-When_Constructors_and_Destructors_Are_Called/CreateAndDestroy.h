#ifndef CREATE_AND_DESTROY_H
#define CREATE_AND_DESTROY_H
#include <string>

class CreateAndDestroy
{
public:
	CreateAndDestroy(int, std::string);
	~CreateAndDestroy();
private:
	int m_objectID;
	std::string m_message;
};

#endif

