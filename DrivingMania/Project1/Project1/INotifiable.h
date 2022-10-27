#pragma once
#include <string>

class INotifiable
{
public:
	INotifiable();
	virtual void onNotify(std::string Sender) = 0;
	virtual ~INotifiable();
};

