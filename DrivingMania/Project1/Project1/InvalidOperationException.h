#pragma once
#include <string>
#include <exception>
class InvalidOperationException
	:public std::exception
{
public:
	InvalidOperationException(std::string sender);
	virtual const char* what() const override;
	~InvalidOperationException();

private:
	std::string m_message;
};

