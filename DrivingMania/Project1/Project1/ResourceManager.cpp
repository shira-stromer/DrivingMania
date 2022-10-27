#include "ResourceManager.h"
#include "Player.h"

ResourceManager::ResourceManager()
{
	loadLevels();
	loadScores();
}

void ResourceManager::loadImage(std::string name)
{
	sf::Image image;
	if (!image.loadFromFile("Images/" + name + ".png"))
	{
		throw NotFoundException(name);
	}
	
	m_imageMap[name] = image;
}

ResourceManager & ResourceManager::getInstance()
{
	static ResourceManager m_instance;
	return m_instance;
}

ResourceManager::~ResourceManager()
{
}

void ResourceManager::exportScores()
{
	auto& player = Player::getInstance();
	auto score = player.getScore();
	auto name = player.getName();
	m_scores[name].push_back(score);

	std::ofstream file;
	file.open(SCORES_FILE_NAME);
	if(!file.is_open())
	{
		throw NotFoundException(SCORES_FILE_NAME);
	}
	
	std::string line;
	line = getScoresLine(name, m_scores[name]) + '\n';
	
	file << line;

	for (auto& item : m_scores)
	{
		if (item.first == name)
			continue;

		line = getScoresLine(item.first, item.second) + '\n';
	}

	file.close();
}

std::map<std::string, std::vector<int>>& ResourceManager::getScores()
{
	return m_scores;
}

sf::Image ResourceManager::getImage(std::string name)
{
	auto value = m_imageMap.find(name);
	if (value == m_imageMap.end())
	{
		loadImage(name);
	}

	return m_imageMap[name];
}

void ResourceManager::loadLevels()
{
	std::ifstream file;
	std::string s;
	int counter = 1;
	file.open(LEVELS_FILE_NAME);
	
	if (!file.is_open())
	{
		throw NotFoundException(LEVELS_FILE_NAME);
	}

	while (std::getline(file, s))
	{
		auto b = "Level" + std::to_string(counter);
		m_levelMap[b] = s;
		counter++;
	}
	m_levelAmount = counter - 1;
	file.close();
}

void ResourceManager::loadScores()
{
	std::ifstream file;
	file.open(SCORES_FILE_NAME);
	std::string s;

	if (!file.is_open())
	{
		throw NotFoundException(SCORES_FILE_NAME);
	}

	while (std::getline(file, s))
	{
		std::vector<int> scores;
		int score;
		auto words = split(s, ',');
		std::string playerName = "";

		for (auto& str : words)
		{
			if (playerName == "")
			{
				playerName = str;
			}
			else
			{
				std::stringstream ss(str);
				ss >> score;
				scores.emplace_back(score);
			}
			
		}
		if (m_scores.size() == 0)
		{
			m_playerName = playerName;
		}
		
		m_scores[playerName] = scores;
	}
}
