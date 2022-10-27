#include <exception>
#include <string>
#pragma once
class UnknownCollisionException
	:public std::exception
{
public:
	UnknownCollisionException(std::string object1, std::string object2);
	~UnknownCollisionException(); 
	virtual const char* what() const override;
private:
	std::string m_message;
};

