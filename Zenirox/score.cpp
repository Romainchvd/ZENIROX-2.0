#include "score.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <fstream>

using namespace std;
using namespace sf;
//ne pas oublier de dégager les initialisations redondantes
int Score::setCurrentScoreText(Player& player)
{
	scoreText.setString("Score: " + to_string(player.currentScore));
	scoreText.setPosition(0, 50);	
}
int Score::setTotalScoreText(Player& player)
{
	scoreText.setString("       " + to_string(player.totalScore));
	scoreText.setCharacterSize(60);
	scoreText.setPosition(800, 700);
}
void Score::updateScoreText(Player& player)
{
	scoreText.setString("       " + to_string(player.currentScore));
}
void Score::openData(Player &player, LevelProgress& levelProgress) {
	ifstream scoreFile("score.txt");
	int totalScore;
	bool nv1B, nv1C, nv2A, nv2B, nv2C, nv3A, nv3B, nv3C, FB, HW;
	scoreFile >> totalScore >> boolalpha >> nv1B >> nv1C >> nv2A >> nv2B >> nv2C >> nv3A >> nv3B >> nv3C >> FB >> HW;
	player.totalScore = totalScore;
	levelProgress.Univeau1B = nv1B;
	levelProgress.Univeau1C = nv1C;
	levelProgress.Univeau2A = nv2A;
	levelProgress.Univeau2B = nv2B;
	levelProgress.Univeau2C = nv2C;
	levelProgress.Univeau3A = nv3A;
	levelProgress.Univeau3B = nv3B;
	levelProgress.Univeau3C = nv3C;
	levelProgress.UfinalBoss = FB;
	levelProgress.hasWon = HW;
	scoreFile.close();
	ifstream inventoryFile("inventory.txt");
	bool U1, U2, U3;
	inventoryFile >> boolalpha >> U1 >> U2 >> U3;
	player.UShip1 = U1;
	player.UShip2 = U2;
	player.UShip3 = U3;
	inventoryFile.close();
}
void Score::saveData(Player& player, GameLevel& currentLevel)
{
	ofstream scoreFile("score.txt");
	if (currentLevel == GameLevel::Niveau1A)
		scoreFile << player.totalScore << ' ' << boolalpha << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ';
	else if (currentLevel == GameLevel::Niveau1B)
	{
		scoreFile << player.totalScore << ' ' << boolalpha << true << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ';
	}
	else if (currentLevel == GameLevel::Niveau1C)
	{
		scoreFile << player.totalScore << ' ' << boolalpha << true << ' ' << true << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ';
	}
	else if (currentLevel == GameLevel::Niveau2A)
	{
		scoreFile << player.totalScore << ' ' << boolalpha << true << ' ' << true << ' ' << true << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ';
	}
	else if (currentLevel == GameLevel::Niveau2B)
	{
		scoreFile << player.totalScore << ' ' << boolalpha << true << ' ' << true << ' ' << true << ' ' << true << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ';
	}
	else if (currentLevel == GameLevel::Niveau2C)
	{
		scoreFile << player.totalScore << ' ' << boolalpha << true << ' ' << true << ' ' << true << ' ' << true << ' ' << true << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ';
	}
	else if (currentLevel == GameLevel::Niveau3A)
	{
		scoreFile << player.totalScore << ' ' << boolalpha << true << ' ' << true << ' ' << true << ' ' << true << ' ' << true << ' ' << true << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ';
	}
	else if (currentLevel == GameLevel::Niveau3B)
	{
		scoreFile << player.totalScore << ' ' << boolalpha << true << ' ' << true << ' ' << true << ' ' << true << ' ' << true << ' ' << true << ' ' << true << ' ' << false << ' ' << false << ' ' << false << ' ';
	}
	else if (currentLevel == GameLevel::Niveau3C)
	{
		scoreFile << player.totalScore << ' ' << boolalpha << true << ' ' << true << ' ' << true << ' ' << true << ' ' << true << ' ' << true << ' ' << true << ' ' << true << ' ' << false << ' ' << false << ' ';
	}
	else if (currentLevel == GameLevel::FinalBoss)
	{
		scoreFile << player.totalScore << ' ' << boolalpha << true << ' ' << true << ' ' << true << ' ' << true << ' ' << true << ' ' << true << ' ' << true << ' ' << true << ' ' << true << ' ' << game.hasWon << ' ';
	}
	scoreFile.close();
	ofstream inventoryFile("inventory.txt");
	inventoryFile << boolalpha << player.UShip1 << ' ' << player.UShip2 << ' ' << player.UShip3;
	inventoryFile.close();
}
void Score::saveCurrentScore(Player& player)
{
	player.totalScore += player.currentScore;
}
void Score::removeData(Player& player, LevelProgress& levelProgress, GameLevel& currentLevel)
{
	ofstream scoreFile("score.txt");
	scoreFile << 0 << boolalpha << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false;
	player.currentScore = 0;
	player.totalScore = 0;
	levelProgress.Univeau1B = false;
	levelProgress.Univeau1C = false;
	levelProgress.Univeau2A = false;
	levelProgress.Univeau2B = false;
	levelProgress.Univeau2C = false;
	levelProgress.Univeau3A = false;
	levelProgress.Univeau3B = false;
	levelProgress.Univeau3C = false;
	levelProgress.UfinalBoss = false;
	levelProgress.hasWon = false;
	currentLevel = GameLevel::Niveau1A;
	scoreFile.close();
	ofstream inventoryFile("inventory.txt");
	inventoryFile << boolalpha << false << ' ' << false << ' ' << false;
	player.UShip1 = false;
	player.UShip2 = false;
	player.UShip3 = false;
	inventoryFile.close();
}
void Score::resetQuest(Player &player, LevelProgress& levelProgress)
{
	ofstream scoreFile("score.txt");
	scoreFile << player.totalScore << boolalpha << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false << ' ' << false;
	levelProgress.Univeau1B = false;
	levelProgress.Univeau1C = false;
	levelProgress.Univeau2A = false;
	levelProgress.Univeau2B = false;
	levelProgress.Univeau2C = false;
	levelProgress.Univeau3A = false;
	levelProgress.Univeau3B = false;
	levelProgress.Univeau3C = false;
	levelProgress.UfinalBoss = false;
	levelProgress.hasWon = false;
}

Score::Score(FontManager& fontManager)
{
	scoreText.setFillColor(Color::White);
	scoreText.setOutlineColor(Color::Black);
	scoreText.setOutlineThickness(4);
	scoreText.setFont(fontManager.getFont("Engcomica"));
}
