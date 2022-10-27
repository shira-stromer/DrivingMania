#include "Animation.h"

Animation::Animation(std::string animation, int width, int height, bool repeate)
	:m_repeate(repeate)
{
	loadFrames(animation, width, height);
}

Animation::~Animation()
{
}

void Animation::setNextFrame(sf::RectangleShape& ptr)
{
	m_index++;
	if (m_index >= m_frames.size() && !m_repeate)
	{
		ptr.setScale(sf::Vector2f());
		return;
	}

	m_index = m_index >= m_frames.size() ? 0 : m_index;
	
	ptr.setTexture(m_frames[m_index]->getTexture());
}

void Animation::loadFrames(std::string animation, int width, int height)
{
	auto& resource = ResourceManager::getInstance();
	std::string anim;
	int count;
	try
	{
		for (count = 0; count < MAX_FRAME_ANOUNT; count++)
		{
			anim = animation;
			if (count != 0)
			{
				anim += std::to_string(count);
			}
			auto frame = std::make_shared<sf::RectangleShape>(resource.getValue<sf::RectangleShape>(animation + "/" + anim));
			frame->setSize(sf::Vector2f((float)width, (float)height));
			m_frames.emplace_back(frame);
		}
	}
	catch (const NotFoundException& ex)
	{
		return;
	}
}

