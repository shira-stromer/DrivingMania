#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <typeinfo>
#include <SFML\Graphics.hpp>
#include <vector>
#include "Constants.h"

struct Timer
{
	sf::Clock m_clock;
	bool m_on;
	float m_seconds;
	void setTimerFor(float seconds)
	{
		m_seconds = seconds;
		m_on = true;
		m_clock.restart();
	}
	bool isTimePassed()
	{
		return m_on && m_clock.getElapsedTime().asSeconds() >= m_seconds;
	}
	void onTimePassed()
	{
		setTimerFor(m_seconds);
	}
};

static std::vector<std::string> split(const std::string& s, char delimiter)
{
	std::vector<std::string> tokens;
	std::string token;
	std::istringstream tokenStream(s);
	while (std::getline(tokenStream, token, delimiter))
	{
		tokens.push_back(token);
	}
	return tokens;
}

static int getMax(std::vector<int> vec)
{
	auto b = *std::max_element(vec.begin(), vec.end());
	return b;
}

template<typename T>
static std::string getTypeName()
{
	return std::string(typeid(T).name());
}

static int getRandom(int min, int max)
{
	return rand() % ((max - min) + 1) + min;
}

static std::string getScoresLine(std::string name, std::vector<int>& scores)
{
	std::string line = name;
	
	for (auto i : scores)
	{
		line += ',' + std::to_string(i);
	}

	return line;
}

static void randomizeDirection(Direction& direct)
{
	switch (getRandom(1, 4))
	{
	case 1:
		direct = Top;
		break;
	case 2:
		direct = Buttom;
		break;
	case 3:
		direct = Left;
		break;
	case 4:
		direct = Right;
		break;
	}
}