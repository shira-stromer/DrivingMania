#pragma once
#include "IDrawable.h"
#include <memory>
#include "Component.h"
#include "IClickable.h"
#include <vector>
#include "INotifiable.h"

class Scene
	:public IDrawable, public INotifiable
{
public:
	Scene();
	virtual void draw() override;
	std::vector<std::shared_ptr<IClickable>>& getButtons();
	sf::RectangleShape getBackground();
	virtual void onNotify(std::string sender) override;
	~Scene();

protected:
	virtual void initComponents();
	sf::RectangleShape m_background;
	std::vector<std::shared_ptr<Component>> m_components;
	std::vector<std::shared_ptr<IClickable>> m_buttons;
};
