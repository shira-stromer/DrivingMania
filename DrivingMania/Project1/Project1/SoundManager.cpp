#include "SoundManager.h"



SoundManager::SoundManager()
{
	m_sound = std::make_unique<sf::Sound>();
	m_background = std::make_unique<sf::Music>();
	m_background->openFromFile("Music/Background.ogg");
	m_volume = (int)(MAX_VOLUME * 0.4);
	onVolumeChanged(); 
}

SoundManager::SoundManager(const SoundManager &)
{
}

void SoundManager::loadMusic(std::string name)
{
	std::unique_ptr<sf::SoundBuffer> buffer = std::make_unique<sf::SoundBuffer>();
	if (!buffer->loadFromFile("Music/" + name + ".ogg"))
	{
		throw NotFoundException(name);
	}

	m_musicMap[name] = std::move(buffer);
}

void SoundManager::onVolumeChanged()
{
	m_background->setVolume(m_volume);
}

std::unique_ptr<sf::SoundBuffer>& SoundManager::getMusic(std::string name)
{
	auto value = m_musicMap.find(name);
	if (value == m_musicMap.end())
	{
		loadMusic(name);
	}

	return m_musicMap[name];
}


SoundManager::~SoundManager()
{
}

SoundManager & SoundManager::getInstance()
{
	static SoundManager m_soundManager;
	return m_soundManager;
}

void SoundManager::increaseVolume()
{
	m_volume += VOLUME_CHANGE;
	m_volume = m_volume >= MAX_VOLUME ? MAX_VOLUME : m_volume;
	std::cout << "Volume: " << m_volume << std::endl;
	onVolumeChanged();
}

void SoundManager::decreaseVolume()
{
	m_volume -= VOLUME_CHANGE;
	m_volume = m_volume <= 0 ? 0 : m_volume;
	std::cout << "Volume: " << m_volume << std::endl;
	onVolumeChanged();
}

void SoundManager::playBackground()
{
	auto& b = m_background;
	b->setLoop(true);
	b->play();
}

int SoundManager::getVolume() const
{
	return m_volume;
}


void SoundManager::turnMusicOff()
{
	m_volume = 0;
	onVolumeChanged();
}

void SoundManager::turnMusicOn(int prev)
{
	m_volume = prev;
	onVolumeChanged();
}

void SoundManager::playCollision(std::string name)
{
	auto& b = getMusic(name);
	m_sound->setVolume(m_volume);
	m_sound->setLoop(false);
	m_sound->setBuffer(*b);
	m_sound->play();
}
