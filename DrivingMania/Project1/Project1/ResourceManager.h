#pragma once
#include <SFML\Graphics.hpp>
#include <map>
#include <string>
#include "NotFoundException.h"
#include <memory>
#include <iostream>
#include <fstream>
#include "Constants.h"
#include <SFML\Audio.hpp>
#include <vector>
#include "Utilities.h"

class Player;
class ResourceManager
{
public:
	static ResourceManager& getInstance();
	~ResourceManager();

	template<typename T>
	T getValue(std::string) { return NULL; }
	void exportScores();
	std::map<std::string, std::vector<int>>& getScores();

private:
	ResourceManager();
	ResourceManager(const ResourceManager&);
	void loadImage(std::string name);
	sf::Image getImage(std::string);
	std::map<std::string, std::string> m_levelMap;
	std::map<std::string, sf::Image> m_imageMap;
	std::map < std::string, std::vector<int>> m_scores;
	void loadLevels();
	void loadScores();
	std::string m_playerName;
	int m_levelAmount;

    #pragma region getValueSpecialization
public:
	template <>
	sf::Image getValue(std::string valueName)
	{
		return getImage(valueName);
	}
	template <>
	std::string getValue(std::string str)
	{
		if (str == "PlayerName")
			return m_playerName;

		return m_levelMap[str];
	}
	template <>
	sf::RectangleShape getValue(std::string valueName)
	{
		sf::RectangleShape sprite;
		sf::Texture* texture = new sf::Texture;
		texture->loadFromImage(getValue<sf::Image>(valueName));
		sprite.setTexture(texture);
		return sprite;
	}
	template<>
	int getValue(std::string valueName)
	{
		if (valueName == "LevelAmount")
		{
			return m_levelAmount;
		}
		return 0;
	}

#pragma endregion

};

