#include "Textable.h"



Textable::Textable(sf::Vector2f pos, int size,sf::Color color)
{
	m_font = std::make_unique<sf::Font>();
	if (!m_font->loadFromFile(GAME_FONT))
	{
		throw NotFoundException(GAME_FONT);
	}

	m_text.setPosition(pos);
	m_text.setCharacterSize(size);
	m_text.setFillColor(color);

}

void Textable::draw()
{
	m_text.setFont(*m_font);
	Screen::getInstance().getWindow().draw(m_text);
}

void Textable::setString(std::string str)
{
	m_text.setString(str);
}

std::string Textable::getString()
{
	return m_text.getString();
}


Textable::~Textable()
{
}
