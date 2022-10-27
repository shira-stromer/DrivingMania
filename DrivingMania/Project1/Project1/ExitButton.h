#pragma once
#include "IClickable.h"

class ExitButton
	:public IClickable
{
public:
	ExitButton();
	virtual void onClicked() override;
	~ExitButton();
};

