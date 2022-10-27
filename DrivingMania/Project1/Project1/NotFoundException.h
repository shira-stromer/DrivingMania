#pragma once
#include <exception>
#include <string>
class NotFoundException
	:public std::exception
{
public:
	NotFoundException(std::string objectName);
	virtual const char* what() const override;
	~NotFoundException();

private:
	std::string m_message;
};

