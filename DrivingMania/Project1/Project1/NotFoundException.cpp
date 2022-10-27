#include "NotFoundException.h"



NotFoundException::NotFoundException(std::string objectName)
{
	m_message = "Not found Exception: " +objectName + " could not be found";
}

const char * NotFoundException::what() const
{
	return m_message.c_str();
}


NotFoundException::~NotFoundException()
{
}
