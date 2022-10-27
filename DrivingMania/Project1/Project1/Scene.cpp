#include "Scene.h"



Scene::Scene()
{
	initComponents();
}

void Scene::draw()
{
	std::for_each(m_components.begin(), m_components.end(), [](std::shared_ptr<Component> comp)
	{
		comp->draw();
	});
}

std::vector<std::shared_ptr<IClickable>>& Scene::getButtons()
{
	return m_buttons;
}

sf::RectangleShape Scene::getBackground()
{
	return m_background;
}

void Scene::onNotify(std::string sender)
{
}

Scene::~Scene()
{
}

void Scene::initComponents()
{	
}
