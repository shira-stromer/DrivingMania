#include "UnknownCollisionException.h"



UnknownCollisionException::UnknownCollisionException(std::string object1, std::string object2)
{
	m_message = "Unknown Collision Exception: " + object1 + " and " + object2 + " collision is not handled";
}


UnknownCollisionException::~UnknownCollisionException()
{
}

const char * UnknownCollisionException::what() const
{
	return m_message.c_str();
}
