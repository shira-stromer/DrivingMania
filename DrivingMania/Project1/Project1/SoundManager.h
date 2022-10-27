#pragma once
#include <SFML\Audio.hpp>
#include "Constants.h"
#include <iostream>
#include <memory>
#include <map>
#include "Constants.h"
#include "NotFoundException.h"
#include <algorithm>

class SoundManager
{
public:
	~SoundManager();
	static SoundManager& getInstance();
	void increaseVolume();
	void decreaseVolume();
	void playBackground();
	int getVolume() const;
	void turnMusicOff();
	void turnMusicOn(int prev);
	void playCollision(std::string name);

private:
	SoundManager();
	SoundManager(const SoundManager&);
	int m_volume;
	void loadMusic(std::string name);
	void onVolumeChanged();
	std::unique_ptr<sf::SoundBuffer>& getMusic(std::string name);
	std::map<std::string, std::unique_ptr<sf::SoundBuffer>> m_musicMap;
	std::unique_ptr<sf::Music> m_background;
	std::unique_ptr<sf::Sound> m_sound;
};

