#pragma once
#include "IClickable.h"
#include "SoundManager.h"
#include "Animation.h"

class SoundButton :
	public IClickable
{
public:
	SoundButton();
	virtual void onClicked() override;
	~SoundButton();

private:
	bool m_isOff = false;
	int m_prevVolume = 0;
	Animation m_animation;
};

