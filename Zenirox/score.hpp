#pragma once
#include <SFML/Graphics.hpp>
#include "player.hpp"
#include "gameLevel.hpp"
#include "levelProgress.hpp"
#include "fontManager.hpp"
using namespace sf;
class Score {
public:
	Text scoreText;
	Text totalScoreText;
	void setCurrentScoreText(Player& player);
	void setTotalScoreText(Player& player);
	void updateScoreText(Player& player);
	void openData(Player& player, LevelProgress& levelProgress);
	void saveData(Player& player, GameLevel& currentLevel, LevelProgress& levelProgress);
	void saveCurrentScore(Player& player);
	void removeData(Player& player, LevelProgress& levelProgress, GameLevel& currentLevel);
	void resetQuest(Player& player, LevelProgress& levelProgress);
	Score(FontManager& fontManager);
};