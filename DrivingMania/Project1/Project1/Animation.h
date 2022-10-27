#pragma once
#include <SFML\Graphics.hpp>
#include <memory>
#include <vector>
#include "ResourceManager.h"
#include "NotFoundException.h"

class Animation
{
public:
	Animation(std::string animation, int width, int height, bool repeate = true);
	~Animation();
	void setNextFrame(sf::RectangleShape& ptr);

private:
	std::vector<std::shared_ptr<sf::RectangleShape>> m_frames;
	void loadFrames(std::string animation, int width, int height);
	int m_index = 0;
	bool m_repeate;
};

