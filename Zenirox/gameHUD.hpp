#pragma once
#include <SFML/Graphics.hpp>
#include "textureManager.hpp"
#include "fontManager.hpp"

class gameHUD {
public:
	sf::Sprite cockpit;
	sf::Sprite coin;
	sf::Clock warningClock;
	sf::Time warningDuration;
	sf::Text warningText;
	TextureManager& textureManager;
	FontManager& fontManager;
	gameHUD(TextureManager& textureManager, FontManager& fontManager);
	void initCockpit();
	void initCoin();
	void initWarningText();
	void updateScoreText(int currentScore);
	void updateTotalScoreText(int totalScore);
};