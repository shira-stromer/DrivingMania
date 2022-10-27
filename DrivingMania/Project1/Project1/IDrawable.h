#pragma once
class IDrawable
{
public:
	IDrawable();
	virtual void draw() = 0;
	virtual ~IDrawable();
};

