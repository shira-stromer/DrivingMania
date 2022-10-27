#include "ObjectNotRegisteredException.h"



ObjectNotRegisteredException::ObjectNotRegisteredException(std::string obj)
{
	m_message = " Object: " + obj + " is not registered in ComponenentFactory";
}

const char * ObjectNotRegisteredException::what() const
{
	return m_message.c_str();
}


ObjectNotRegisteredException::~ObjectNotRegisteredException()
{
}
