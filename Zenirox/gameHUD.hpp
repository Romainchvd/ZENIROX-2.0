#pragma once
#include <SFML/Graphics.hpp>
#include "textureManager.hpp"
#include "fontManager.hpp"
#include "healthbar.hpp"

class GameHUD {
public:
	sf::Sprite cockpit;
	sf::Sprite skull;
	sf::Sprite coin;
	sf::Clock warningClock;
	sf::Time warningDuration;
	sf::Text warningText;
	Healthbar healthbar;
	TextureManager& textureManager;
	FontManager& fontManager;
	GameHUD(TextureManager& textureManager, FontManager& fontManager);
	void initCockpit();
	void initCoin();
	void initWarningText();
	void initSkull();
	void handleWarning(sf::RenderWindow& window);
};