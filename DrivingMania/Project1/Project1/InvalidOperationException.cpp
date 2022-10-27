#include "InvalidOperationException.h"

InvalidOperationException::InvalidOperationException(std::string sender)
{
	m_message = "Invalid operation occured at: " + sender;
}

const char * InvalidOperationException::what() const
{
	return m_message.c_str();
}

InvalidOperationException::~InvalidOperationException()
{
}
