#pragma once
#include "SFML\Graphics.hpp"
#include "IDrawable.h"
#include "Screen.h"
#include <string>
#include "NotFoundException.h"
#include <memory>
#include "Constants.h"

class Textable
	:public IDrawable
{
public:
	Textable(sf::Vector2f pos, int size, sf::Color color);
	virtual void draw() override;
	void setString(std::string);
	std::string getString();
	~Textable();

private:
	sf::Text m_text;
	std::unique_ptr<sf::Font> m_font;
};

