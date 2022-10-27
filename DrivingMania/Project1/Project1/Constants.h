#pragma once
#include <string>
#include "SFML\Graphics.hpp"

const int SCREEN_HEIGHT = 900;
const int SCREEN_WIDTH = 900;
const std::string LEVELS_FILE_NAME = "Files/LevelsFile.txt";
const int MAX_VOLUME = 100;
const std::string SCORES_FILE_NAME = "Files/Names.txt";
const std::string GAME_FONT = "Fonts/gameFont.TTF"; 
const int TRAFFIC_LIGHT_GREEN_WAIT_SECONDS = 4; //Must be different from the others;
const int TRAFFIC_LIGHT_RED_WAIT_SECONDS = 7;
const int TRAFFIC_LIGHT_YELLOW_WAIT_SECONDS = 2;
const int LIVES_AMOUNT = 10;
const int MAX_NAME_SIZE = 19;
const int RECOVERY_SECONDS = 1;
const int MAX_FRAME_ANOUNT = 35;
const int FRAME_SECONDS = 1;
const int VOLUME_CHANGE = 5;
const int COIN_LIVES_INCREASE = 1;
const std::string PLAYER = "Player";

const sf::Color UNCOMPLETE_ARROW_COLOR = sf::Color(sf::Uint8(206),sf::Uint8(79),sf::Uint8(44));
const sf::Color COMPLETE_ARROW_COLOR = sf::Color::Green;

enum TrafficLightColor
{
	Red = TRAFFIC_LIGHT_RED_WAIT_SECONDS,
	Yellow = TRAFFIC_LIGHT_YELLOW_WAIT_SECONDS,
	Green = TRAFFIC_LIGHT_GREEN_WAIT_SECONDS
};

enum Direction
{
	Top =0 ,
	Left = 270,
	Right = 90,
	Buttom = 180
};