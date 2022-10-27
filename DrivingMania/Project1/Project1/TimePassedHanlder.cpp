#include "TimePassedHanlder.h"
#include "GameScene.h"
#include "Controller.h"

TimePassedHanlder::TimePassedHanlder() {}
TimePassedHanlder::~TimePassedHanlder() {}

void TimePassedHanlder::onTimePassed()
{
	auto name = getTypeName<TimePassedHanlder>();
	Controller::getInstance().getScene()->onNotify(name);
	
	std::for_each(m_notifiables.begin(), m_notifiables.end(), [name](std::shared_ptr<INotifiable> ptr) 
	{
		ptr->onNotify(name);
	});
}

void TimePassedHanlder::registerForNotification(std::shared_ptr<INotifiable> ptr)
{
	m_notifiables.push_back(ptr);
}
      