#ifndef GAME_HPP
#define GAME_HPP
#include <SFML/Audio.hpp>
#include <ctime>
#include <stdexcept>
#include <string>
#include <memory>
#include "player.hpp"
#include "gameWindow.hpp"
#include "projectile.hpp"
#include "background.hpp"
#include "parallaxe.hpp"
#include "parallaxe2.hpp"
#include "score.hpp"
#include "healthbar.hpp"
#include "obstacle.hpp"
#include "powerups.hpp"
#include "enemyManager.hpp"
#include "textureManager.hpp"
#include "gameScreen.hpp"
#include "gameLevel.hpp"
#include "levelProgress.hpp"

using namespace std;
using namespace sf;

class Starparallaxe;
class fastStarparallaxe;



struct EnemySpawn {
	ID id;
	float x, y;
};

struct LevelConfig {
	std::string title;
	std::string tierName; // pour le background
	float duration;
	int enemiesToKill;
	ID bossID;
	std::vector<EnemySpawn> enemies;
	std::vector<sf::Vector2f> obstacles;
};

class Game {
private:
	

	std::vector<Text> menuOptions;    // Text objects for menu options
	int hoveredOption;                    // Index of the hovered option
	Text title;                       

public:
	Game();
	Player player;
	TextureManager textureManager;
	EnemyManager eManager;
	Sprite backgroundSprite, closeS, confirmS, editorS, cancelS, dataS,
		easyS, hardcoreS, menuS, normalS, questS, resumeS, settingsS, buyS, yesS, yes2S, noS, no2S, backS,
		shopS, continueS, resetS, buyShip1S, buyShip2S, buyShip3S, inventoryShipS, inventoryShip1S, inventoryShip2S, inventoryShip3S, pauseS;

	Font font;
	gameWindow window;
	Music nextLevelM;
	Music victoryM;
	Music editorM;
	Music titleScreenM;
	Music lose;
	Music finalhours;

	Sound confirmSound;
	Sound clickSound;
	Sound impossibleAction;

	SoundBuffer confirmSoundBuffer;
	SoundBuffer clickSoundBuffer;
	SoundBuffer impossibleActionSoundBuffer;

	GameLevel currentLevel = GameLevel::Niveau1A;
	GameScreen currentScreen = GameScreen::Menu;
	GameScreen previousScreen;
	ID* alias = &nb1;
	Clock gameClock;
	Clock settingsClock;
	Time settingsCooldown = seconds(0.05f);
	Time gameDuration;
	ID  nb1, nb2, nb3, nb4, nb5, nb6, nb7, nb8, nb9, nb10, bossID = ENNEMI1;
	Text currentLevelText;
	Font currentLevelFont;

	bool doLoadBackground = true;
	bool loadLevel = true;
	bool loadCampain, loadEdited = false;
	int toKill = 0;
	int counter = 1;
	int currentID = 0;
	bool EloadObstacle, EloadPowerups = false;
	LevelProgress levelProgress;

	void setGameDuration(float duration);
	void levelP(Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager, ExplosionManager& exManager, Music& playing, Music& boss, Music& finalBossM, Background& background);
	void run(RenderWindow& window, Player& player, Sprite& coin, Background& background, Starparallaxe& star, Starparallaxe& faststar, Healthbar& healthbar, EnemyManager& eManager, ProjectileManager& pManager, ObstacleManager& oManager, UtilitaryManager& uManager, ExplosionManager& exManager, Clock& clock, Text& scoreText, Font& scoreFont, RectangleShape& interface, Music& playing, Music& boss, Music& finalBossM, vector<Sound>& playerShot, SoundBuffer& shot, Text& totalScoreText);
	std::map<GameLevel, LevelConfig> levelDatabase;
	void initLevelDatabase();
	void playLevel(GameLevel levelState, Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager, ExplosionManager& exManager, Music& playing, Music& boss, Music& finalBossM, Background& background);
	void spawnPowerups(Player& player, UtilitaryManager& uManager);
};

#endif
