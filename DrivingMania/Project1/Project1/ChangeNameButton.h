#pragma once
#include "IClickable.h"

class Controller;
class ChangeNameButton :
	public IClickable
{
public:
	ChangeNameButton();
	virtual void onClicked() override;
	~ChangeNameButton();
};

