#include <iostream>
#include "CreateAndDestroy.h"

CreateAndDestroy::CreateAndDestroy(int ID, std::string message)
	: m_objectID(ID), m_message(message)
{
	std::cout << "Object " << m_objectID << "    constructor runs   "
		<< m_message << std::endl;
}

CreateAndDestroy::~CreateAndDestroy()
{
	// output newline for certain objects
	std::cout << (m_objectID == 1 || m_objectID == 6 ? "\n": "");

	std::cout << "Object " << m_objectID << "    destructor runs   "
		<< m_message << std::endl;
}
