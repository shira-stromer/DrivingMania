#pragma once
#include <SFML\Graphics.hpp>
#include <vector>
#include "Player.h"
#include <memory>
#include <functional>
#include "INotifiable.h"

class Controller;
class TimePassedHanlder
{
public:
	TimePassedHanlder();
	~TimePassedHanlder();
	void onTimePassed();
	void registerForNotification(std::shared_ptr<INotifiable>);

private:
	std::vector<std::shared_ptr<INotifiable>> m_notifiables;
};

