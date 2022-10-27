#pragma once
#include <exception>
#include <functional>
#include <sstream>
#include <string>

class ObjectNotRegisteredException
	:public std::exception
{
public:
	ObjectNotRegisteredException(std::string obj);
	virtual const char* what() const override;
	~ObjectNotRegisteredException();

private:
	std::string m_message;
};

