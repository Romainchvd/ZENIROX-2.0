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
#include "score.hpp"
#include "healthbar.hpp"
#include "obstacle.hpp"
#include "powerups.hpp"
#include "enemyManager.hpp"
#include "textureManager.hpp"
#include "fontManager.hpp"
#include "gameScreen.hpp"
#include "gameLevel.hpp"
#include "levelProgress.hpp"
#include "gameHUD.hpp"

using namespace std;
using namespace sf;



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
	~Game();
	Player player;
	Score score;
	TextureManager textureManager;
	FontManager fontManager;
	EnemyManager enemyManager;
	ProjectileManager projectileManager;
	ObstacleManager obstacleManager;
	UtilitaryManager utilitaryManager;
	ExplosionManager explosionManager;
	Sprite backgroundSprite, closeS, confirmS, editorS, cancelS, dataS,
		easyS, hardcoreS, menuS, normalS, questS, resumeS, settingsS, buyS, yesS, yes2S, noS, no2S, backS,
		shopS, continueS, resetS, buyShip1S, buyShip2S, buyShip3S, inventoryShipS, inventoryShip1S, inventoryShip2S, inventoryShip3S, pauseS;
	Starparallaxe star;
	Starparallaxe faststar;
	Font font;
	gameWindow window;
	GameHUD hud;
	Background background;
	Music nextLevelM;
	Music victoryM;
	Music editorM;
	Music titleScreenM;
	Music lose;
	Music finalhours;
	Music playing;
	Music boss;
	Music finalBossM;

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
	Clock deltaTimeClock;
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
	void run(vector<Sound>& playerShot, SoundBuffer& shot);
	std::map<GameLevel, LevelConfig> levelDatabase;
	void initLevelDatabase();
	void playLevel(GameLevel levelState, Player& player, EnemyManager& eManager, ObstacleManager& oManager, ProjectileManager& pManager, UtilitaryManager& uManager, ExplosionManager& exManager, Music& playing, Music& boss, Music& finalBossM, Background& background);
	void spawnPowerups(Player& player, UtilitaryManager& uManager);
};

#endif
