#include "game.hpp"
#include <stdexcept>
#include "SFML/Graphics.hpp"
Game::Game() : hoveredOption(-1), player(textureManager), score(fontManager), projectileManager(textureManager), obstacleManager(textureManager), utilitaryManager(textureManager), explosionManager(textureManager), star(textureManager, -100, "star"), faststar(textureManager, -200, "star"), background(textureManager, -31.f), hud(textureManager, fontManager) {

	score.setCurrentScoreText(player);
	score.openData(player, levelProgress);

	if (levelProgress.UfinalBoss == true)
		currentLevel = GameLevel::FinalBoss;
	else if (levelProgress.Univeau3C == true)
		currentLevel = GameLevel::Niveau3C;
	else if (levelProgress.Univeau3B == true)
		currentLevel = GameLevel::Niveau3B;
	else if (levelProgress.Univeau3A == true)
		currentLevel = GameLevel::Niveau3A;
	else if (levelProgress.Univeau2C == true)
		currentLevel = GameLevel::Niveau2C;
	else if (levelProgress.Univeau2B == true)
		currentLevel = GameLevel::Niveau2B;
	else if (levelProgress.Univeau2A == true)
		currentLevel = GameLevel::Niveau2A;
	else if (levelProgress.Univeau1C == true)
		currentLevel = GameLevel::Niveau1C;
	else if (levelProgress.Univeau1B == true)
		currentLevel = GameLevel::Niveau1B;
	else
		currentLevel = GameLevel::Niveau1A;
	// font
	if (!font.loadFromFile("UIfont.ttf")) {
		throw std::runtime_error("Failed to load texture");
	}

	
	closeS.setTexture(textureManager.getTexture("close"));
	closeS.setScale(2, 2);

	
	
	confirmS.setTexture(textureManager.getTexture("confirm"));
	confirmS.setScale(2, 2);

	
	editorS.setTexture(textureManager.getTexture("editor"));
	editorS.setScale(2, 2);

	
	cancelS.setTexture(textureManager.getTexture("cancel"));
	cancelS.setScale(2, 2);

	
	dataS.setTexture(textureManager.getTexture("data"));
	dataS.setScale(2, 2);

	
	
	easyS.setTexture(textureManager.getTexture("easy"));
	easyS.setScale(2, 2);

	
	hardcoreS.setTexture(textureManager.getTexture("hardcore"));
	hardcoreS.setScale(2, 2);

	
	menuS.setTexture(textureManager.getTexture("menu"));
	menuS.setScale(2, 2);

	
	normalS.setTexture(textureManager.getTexture("normal"));
	normalS.setScale(2, 2);

	
	questS.setTexture(textureManager.getTexture("quest"));
	questS.setScale(2, 2);

	
	resumeS.setTexture(textureManager.getTexture("resume"));
	resumeS.setScale(2, 2);

	
	settingsS.setTexture(textureManager.getTexture("settings"));
	settingsS.setScale(2, 2);


	
	buyS.setTexture(textureManager.getTexture("buy"));
	buyS.setScale(2, 2);

	
	yesS.setTexture(textureManager.getTexture("yes"));
	yesS.setScale(1.5, 1.5);
	yes2S.setTexture(textureManager.getTexture("yes"));
	yes2S.setScale(1.5, 1.5);

	
	noS.setTexture(textureManager.getTexture("no"));
	noS.setScale(1.5, 1.5);
	no2S.setTexture(textureManager.getTexture("no"));
	no2S.setScale(1.5, 1.5);

	
	backS.setTexture(textureManager.getTexture("back"));
	backS.setScale(2, 2);

	//
	shopS.setTexture(textureManager.getTexture("shop"));
	shopS.setScale(2, 2);

	continueS.setTexture(textureManager.getTexture("continue"));
	continueS.setScale(2, 2);

	resetS.setTexture(textureManager.getTexture("reset"));
	resetS.setScale(2, 2);
	
	pauseS.setTexture(textureManager.getTexture("pause"));
	pauseS.setScale(2, 2);

	//Musique de défaite
	if (!lose.openFromFile("sounds/lose.ogg")) throw runtime_error("Echec lors de l'ouverture de la musique de defaite");

	//Musique finalhours
	if (!finalhours.openFromFile("sounds/finalhours.ogg")) throw runtime_error("Echec lors de l'ouverture de la musique de defaite");
	finalhours.setLoop(true);

	//Musique écran titre
	if (!titleScreenM.openFromFile("sounds/titlescreen.ogg")) throw runtime_error("Echec lors de l'ouverture de l'opening");
	titleScreenM.setLoop(true);
	titleScreenM.setVolume(15);

	//Musique niveau suivant
	if (!nextLevelM.openFromFile("sounds/nextlevel.ogg")) throw runtime_error("Echec lors de l'ouverture de la musique de niveau suivant");

	//Musique éditeur
	if (!editorM.openFromFile("sounds/editor.ogg")) throw runtime_error("Echec lors de l'ouverture de la musique de l'editeur");
	editorM.setLoop(true);

	//Musique victoire
	if (!victoryM.openFromFile("sounds/victory.ogg")) throw runtime_error("Echec lors de l'ouverture de la musique de fin");

	//Musique de combat classique
	if (!playing.openFromFile("sounds/playing.ogg")) throw runtime_error("Musique de combat classique non chargee");
	playing.setLoop(true);

	//Musique de combat de boss
	if (!boss.openFromFile("sounds/boss.ogg")) throw runtime_error("Musique de combat de boss non chargee");
	boss.setLoop(true);

	//Musique de combat final
	if (!finalBossM.openFromFile("sounds/finalboss.ogg")) throw runtime_error("Musique de combat final non chargee");
	finalBossM.setLoop(true);


	//Volume des musiques
	playing.setVolume(50);
	boss.setVolume(50);
	finalBossM.setVolume(50);



	//Son de confirmation
	if (!confirmSoundBuffer.loadFromFile("sounds/confirm.ogg")) throw runtime_error("Echec lors de l'ouverture du son de confirmation");
	confirmSound.setBuffer(confirmSoundBuffer);

	//Son de click sans confirmation
	if (!clickSoundBuffer.loadFromFile("sounds/click.ogg")) throw runtime_error("Echec lors de l'ouverture du son de click");
	clickSound.setBuffer(clickSoundBuffer);
	clickSound.setVolume(50);

	//Son de click impossible
	if (!impossibleActionSoundBuffer.loadFromFile("sounds/impossible.ogg")) throw runtime_error("Echec lors de l'ouverture du son de click impossible");
	impossibleAction.setBuffer(impossibleActionSoundBuffer);

	//Texte du niveau actuel
	currentLevelText.setFont(fontManager.getFont("Engcomica"));
	currentLevelText.setPosition(750, 25);
	currentLevelText.setCharacterSize(40);
	currentLevelText.setOutlineColor(Color::Black);
	currentLevelText.setOutlineThickness(4);

	//Sprites DLC
	
	inventoryShipS.setTexture(textureManager.getTexture("inventoryShip"));
	inventoryShip1S.setTexture(textureManager.getTexture("inventoryShip1"));
	inventoryShip2S.setTexture(textureManager.getTexture("inventoryShip2"));
	inventoryShip3S.setTexture(textureManager.getTexture("inventoryShip3"));
	buyShip1S.setTexture(textureManager.getTexture("buyShip1"));
	buyShip2S.setTexture(textureManager.getTexture("buyShip2"));
	buyShip3S.setTexture(textureManager.getTexture("buyShip3"));
	initLevelDatabase();
}

Game::~Game() {
	score.saveData(player, currentLevel, levelProgress);
}

void Game::setGameDuration(float duration) {
	gameDuration = seconds(duration);
}

void Game::initLevelDatabase() {
	levelDatabase[GameLevel::Niveau1A] = {
		"TIER: 1 - LEVEL: 1",
		"palier1",
		240.0f,
		11,
		BOSS1,
		{
			{ENNEMI1, 1000, 600}, {ENNEMI1, 2500, 300}, {ENNEMI1, 4000, 700},
			{ENNEMI1, 5500, 100}, {ENNEMI2, 7000, 800}, {ENNEMI1, 8500, 400},
			{ENNEMI1, 10000, 600}, {ENNEMI1, 11500, 300}, {ENNEMI1, 13000, 500},
			{ENNEMI3, 14500, 800}
		},
		{ {4700, 500} }
	};

	levelDatabase[GameLevel::Niveau1B] = {
		"TIER: 1 - LEVEL: 2", "palier1", 240.0f, 11, BOSS1,
		{
			{ENNEMI1, 1000, 500}, {ENNEMI1, 2500, 300}, {ENNEMI2, 4000, 700},
			{ENNEMI1, 5500, 100}, {ENNEMI1, 7000, 800}, {ENNEMI2, 8500, 400},
			{ENNEMI1, 10000, 600}, {ENNEMI1, 11500, 300}, {ENNEMI1, 13000, 500},
			{ENNEMI3, 14500, 800}
		},
		{ {4700, 500} }
	};

	levelDatabase[GameLevel::Niveau1C] = {
		"TIER: 1 - LEVEL: 3",
		"palier1",
		240.0f,
		11, // 10 ennemis + 1 boss
		BOSS1,
		{
			{ENNEMI1, 1000, 500}, {ENNEMI1, 2500, 300}, {ENNEMI2, 4000, 700},
			{ENNEMI1, 5500, 100}, {ENNEMI1, 7000, 800}, {ENNEMI2, 8500, 400},
			{ENNEMI1, 10000, 600}, {ENNEMI2, 11500, 300}, {ENNEMI1, 13000, 500},
			{ENNEMI3, 14500, 800}
		},
		{ {4700, 500} }
	};
	levelDatabase[GameLevel::Niveau2A] = {
		"TIER: 2 - LEVEL: 1",
		"palier2",           
		240.0f,
		11,                   
		BOSS2,                
		{
			{ENNEMI2, 1000, 500}, {ENNEMI2, 2500, 300}, {ENNEMI2, 4000, 700},
			{ENNEMI2, 5500, 100}, {ENNEMI3, 7000, 800}, {ENNEMI2, 8500, 400},
			{ENNEMI2, 10000, 600}, {ENNEMI2, 11500, 300}, {ENNEMI2, 13000, 500},
			{ENNEMI3, 14500, 800}
		},
		{ {4700, 500} }
	};
	levelDatabase[GameLevel::Niveau2B] = {
	"TIER: 2 - LEVEL: 2",
	"palier2",
	240.0f,
	11,
	BOSS2,
	{
		{ENNEMI2, 1000, 500}, {ENNEMI2, 2500, 300}, {ENNEMI2, 4000, 700},
		{ENNEMI2, 5500, 100}, {ENNEMI3, 7000, 800}, {ENNEMI2, 8500, 400},
		{ENNEMI2, 10000, 600}, {ENNEMI3, 11500, 300}, {ENNEMI2, 13000, 500},
		{ENNEMI3, 14500, 800}
	},
	{ {4700, 500} }
	};

	levelDatabase[GameLevel::Niveau2C] = {
		"TIER: 2 - LEVEL: 3",
		"palier2",
		240.0f,
		11,
		BOSS2,
		{
			{ENNEMI3, 1000, 500}, {ENNEMI2, 2500, 300}, {ENNEMI2, 4000, 700},
			{ENNEMI2, 5500, 100}, {ENNEMI3, 7000, 800}, {ENNEMI2, 8500, 400},
			{ENNEMI2, 10000, 600}, {ENNEMI3, 11500, 300}, {ENNEMI2, 13000, 500},
			{ENNEMI3, 14500, 800}
		},
		{ {4700, 500} }
	};

	levelDatabase[GameLevel::Niveau3A] = {
		"TIER: 3 - LEVEL: 1", "palier3", 240.0f, 11, BOSS3,
		{
			{ENNEMI3, 1000, 500}, {ENNEMI3, 2500, 300}, {ENNEMI3, 4000, 700},
			{ENNEMI3, 5500, 100}, {ENNEMI3, 7000, 800}, {ENNEMI3, 8500, 400},
			{ENNEMI3, 10000, 600}, {ENNEMI3, 11500, 300}, {ENNEMI3, 13000, 500},
			{ENNEMI3, 14500, 800}
		},
		{ {4700, 500}, {6000, 500} }
	};

	levelDatabase[GameLevel::Niveau3B] = {
		"TIER: 3 - LEVEL: 2", "palier3", 300.0f, 16, BOSS3,
		{
			{ENNEMI3, 1000, 500}, {ENNEMI3, 900, 700}, {ENNEMI3, 2500, 300},
			{ENNEMI3, 2400, 500}, {ENNEMI3, 4000, 700}, {ENNEMI3, 5500, 100},
			{ENNEMI3, 7000, 800}, {ENNEMI3, 6900, 500}, {ENNEMI3, 8500, 400},
			{ENNEMI3, 10000, 600}, {ENNEMI3, 11500, 300}, {ENNEMI3, 11400, 700},
			{ENNEMI3, 13000, 500}, {ENNEMI3, 14500, 800}, {ENNEMI3, 14400, 500}
		},
		{ {4700, 500}, {6000, 500} }
	};

	levelDatabase[GameLevel::Niveau3C] = {
		"TIER: 3 - LEVEL: 3", "palier3", 360.0f, 21, BOSS3,
		{
			{ENNEMI3, 1000, 500}, {ENNEMI3, 900, 700}, {ENNEMI3, 800, 300},
			{ENNEMI3, 2500, 300}, {ENNEMI3, 2400, 500}, {ENNEMI3, 2300, 700},
			{ENNEMI3, 4000, 700}, {ENNEMI3, 5500, 100}, {ENNEMI3, 7000, 800},
			{ENNEMI3, 6900, 500}, {ENNEMI3, 6800, 200}, {ENNEMI3, 8500, 400},
			{ENNEMI3, 10000, 600}, {ENNEMI3, 11500, 300}, {ENNEMI3, 11400, 700},
			{ENNEMI3, 11300, 500}, {ENNEMI3, 13000, 500}, {ENNEMI3, 14500, 800},
			{ENNEMI3, 14400, 500}, {ENNEMI3, 14300, 200}
		},
		{ {4700, 500}, {6000, 500} }
	};

	levelDatabase[GameLevel::FinalBoss] = {
	"FINAL BOSS",
	"palier4",
	360.0f,
	0,
	BOSS4,
	{},
	{ {1000, 100}, {1000, 900} }
	};
}

void Game::playLevel(GameLevel levelState, Player& player, EnemyManager& enemyManager, ObstacleManager& obstacleManager, ProjectileManager& projectileManager, UtilitaryManager& utilitaryManager, ExplosionManager& exManager, Music& playing, Music& boss, Music& finalBossM, Background& background)
{
	
	//Does the level exists
	if (levelDatabase.find(levelState) == levelDatabase.end()) return;
	const LevelConfig& config = levelDatabase[levelState];
	// Loading
	if (currentLevel == levelState && loadLevel == true && levelProgress.isFightingBoss == false) {
		currentLevelText.setString(config.title);
		background.setUpTier(textureManager, config.tierName);

		// Reset sounds and clock
		finalhours.stop(); boss.stop(); finalBossM.stop();
		playing.play();
		gameClock.restart();
		setGameDuration(config.duration);

		// Spawning enemies via configuration
		for (const auto& e : config.enemies) {
			enemyManager.creerEnemy(e.id, e.x, e.y, textureManager);
		}
		for (const auto& o : config.obstacles) {
			obstacleManager.creerObstacle(o.x, o.y);
		}

		loadLevel = false;
	}

	// Death
	float elapsed = gameClock.getElapsedTime().asSeconds();
	if (elapsed > gameDuration.asSeconds()) player.HP = 0;

	//Boss
	if (currentLevel == levelState && enemyManager.getEnemies().empty() && !levelProgress.isFightingBoss) {
		playing.stop();
		if (currentLevel == GameLevel::FinalBoss) {
			finalBossM.play();
		}
		else {
			if (finalhours.getStatus() != Sound::Playing) boss.play();
		}
		levelProgress.isFightingBoss = true;
		toKill = 1;
		enemyManager.creerEnemy(config.bossID, 1400, 700, textureManager);

		//Powerups
		spawnPowerups(player, utilitaryManager); 
	}

	//Victory
	if (levelProgress.isFightingBoss && enemyManager.getEnemies().empty() && currentLevel == levelState) {
		exManager.clear();
		previousScreen = currentScreen;
		if (currentLevel == GameLevel::FinalBoss) {
			levelProgress.hasWon = true;
			currentScreen = GameScreen::Win;
		}
		else {
			currentScreen = GameScreen::NextLevel;
		}
	}

}

void Game::spawnPowerups(Player& player, UtilitaryManager& utilitaryManager)
{
	if (player.difficulty != Hardcore)
	{
		utilitaryManager.creerUtilitary(shield, 2000, 700);
		utilitaryManager.creerUtilitary(battery, 6000, 500);
		utilitaryManager.creerUtilitary(heart, 10000, 300);
	}
	if (player.difficulty == Hardcore)
	{
		utilitaryManager.creerUtilitary(evilBattery, 2000, 200);
		utilitaryManager.creerUtilitary(evilShield, 6000, 300);
		utilitaryManager.creerUtilitary(evilHeart, 10000, 700);
	}
}


void Game::levelP(Player& player, EnemyManager& enemyManager, ObstacleManager& obstacleManager, ProjectileManager& projectileManager, UtilitaryManager& utilitaryManager, ExplosionManager& exManager, Music& playing, Music& boss, Music& finalBossM, Background& background)
{
	if (currentLevel == GameLevel::NiveauEDIT && loadLevel == true && levelProgress.isFightingBoss == false)
	{
		currentLevelText.setString("EDITED LEVEL");
		background.setUpTier(textureManager, "palier1");
		boss.stop();
		finalBossM.stop();
		playing.play();
		gameClock.restart();
		setGameDuration(240);
		toKill = 10;

		if(EloadObstacle == true)
			obstacleManager.creerObstacle(4700, 500);
		enemyManager.creerEnemy(nb1, 1000, 600, textureManager);
		enemyManager.creerEnemy(nb2, 2500, 300, textureManager);
		enemyManager.creerEnemy(nb3, 4000, 700, textureManager);
		enemyManager.creerEnemy(nb4, 5500, 100, textureManager);
		enemyManager.creerEnemy(nb5, 7000, 800, textureManager);
		enemyManager.creerEnemy(nb6, 8500, 400, textureManager);
		enemyManager.creerEnemy(nb7, 10000, 600, textureManager);
		enemyManager.creerEnemy(nb8, 11500, 300, textureManager);
		enemyManager.creerEnemy(nb9, 13000, 500, textureManager);
		enemyManager.creerEnemy(nb10, 14500, 800, textureManager);

		loadLevel = false;
	}
	if (gameClock.getElapsedTime().asSeconds() > gameDuration.asSeconds())
	{
		player.HP = 0;
	}
	if (gameClock.getElapsedTime().asSeconds() > gameDuration.asSeconds() - gameDuration.asSeconds() / 4 && finalhours.getStatus() != Sound::Playing && player.HP >= 0 && lose.getStatus() != Sound::Playing)
	{
		playing.stop();
		finalBossM.stop();
		boss.stop();
		finalhours.play();
	}
	else if (currentLevel == GameLevel::NiveauEDIT && toKill == 0 && levelProgress.isFightingBoss == false)
	{
		playing.stop();
		finalBossM.stop();
		if (finalhours.getStatus() != Sound::Playing)
			boss.play();
		levelProgress.isFightingBoss = true;
		toKill = 1;
		enemyManager.creerEnemy(bossID, 1400, 700, textureManager);
		if (EloadPowerups == true)
		{
			if (player.difficulty == Easy)
			{
				utilitaryManager.creerUtilitary(shield, 2000, 700);
				utilitaryManager.creerUtilitary(battery, 6000, 500);
				utilitaryManager.creerUtilitary(heart, 10000, 300);
			}
			else if (player.difficulty == Hardcore)
			{
				utilitaryManager.creerUtilitary(evilBattery, 2000, 200);
				utilitaryManager.creerUtilitary(evilShield, 6000, 300);
				utilitaryManager.creerUtilitary(evilHeart, 10000, 700);
			}
			else if (player.difficulty == Normal)
			{
				utilitaryManager.creerUtilitary(shield, 2000, 700);
				utilitaryManager.creerUtilitary(battery, 6000, 500);
				utilitaryManager.creerUtilitary(heart, 10000, 300);
				utilitaryManager.creerUtilitary(evilBattery, 2000, 200);
				utilitaryManager.creerUtilitary(evilShield, 6000, 300);
				utilitaryManager.creerUtilitary(evilHeart, 10000, 700);
			}
		}
	}
	if (levelProgress.isFightingBoss == true && toKill == 0 && currentLevel == GameLevel::NiveauEDIT)
	{
		levelProgress.isFightingBoss = false;
		doLoadBackground = true;
		loadLevel = true;
		boss.stop();
		previousScreen = currentScreen;
		currentScreen = GameScreen::Editor;
		counter = 1;
		currentID = 0;
		previousScreen = GameScreen::SetDifficulty;


	}

}

void Game::run(vector<Sound>& playerShot, SoundBuffer& shot)
{
	while (window.isOpen())
	{
		window.clear();
		if (currentScreen == GameScreen::Paused)
		{
		resumeS.setPosition(780, 485);
		Sprite pauseBackgroundS;
		Texture pauseBackgroundT;
		if (!pauseBackgroundT.loadFromFile("pause.png")) throw runtime_error("Erreur lors du chargement de l'ecran de pause");
		pauseBackgroundS.setTexture(pauseBackgroundT);

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Escape)
					currentScreen = previousScreen;
			}
			if (event.type == Event::MouseButtonPressed)
			{
				Vector2i mousePos = Mouse::getPosition(window.window);
				if (event.mouseButton.button == Mouse::Left && resumeS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
					currentScreen = previousScreen;
			}

		}
		window.draw(pauseBackgroundS);
		window.draw(resumeS);
		}
		if (currentScreen == GameScreen::Shop)
	{
			Sprite shopBackgroundS;
			Texture shopBackgroundT;
			if (!shopBackgroundT.loadFromFile("shop.png")) throw runtime_error("Erreur chargement fond shop");
			buyShip1S.setPosition(112.f, 351.f);
			buyShip2S.setPosition(810.f, 351.f);
			buyShip3S.setPosition(1508.f, 351.f);
			backS.setScale(2.f, 2.f);
			backS.setPosition(360.f, 860.f);
			settingsS.setPosition(1163.f, 860.f);
			settingsS.setScale(2.f, 2.f);
			hud.coin.setScale(0.26f, 0.26f);
			hud.coin.setPosition(880.f, 5.f);
			score.totalScoreText.setScale(1.f, 1.f);
			score.setTotalScoreText(player);
			score.totalScoreText.setPosition(880.f, 0.f);
			


			shopBackgroundS.setTexture(shopBackgroundT);

			Event event;

			while (window.pollEvent(event))
				if (event.type == Event::Closed)
					window.close();
			if (event.type == Event::MouseButtonPressed)
			{
				Vector2i mousePos = Mouse::getPosition(window.window);

				if (player.UShip1 == false && event.mouseButton.button == Mouse::Left && buyShip1S.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					if (player.totalScore >= 2500)
					{
						player.buy.play();
						player.totalScore -= 2500;
						player.UShip1 = true;
						score.saveData(player, currentLevel, levelProgress);
					}
					else
						impossibleAction.play();
				}
				if (player.UShip2 == false && event.mouseButton.button == Mouse::Left && buyShip2S.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					if (player.totalScore >= 4000)
					{
						player.buy.play();
						player.totalScore -= 4000;
						player.UShip2 = true;
						score.saveData(player, currentLevel, levelProgress);
					}
					else
						impossibleAction.play();
				}
				if (player.UShip3 == false && event.mouseButton.button == Mouse::Left && buyShip3S.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					if (player.totalScore >= 7500)
					{
						player.buy.play();
						player.totalScore -= 7500;
						player.UShip3 = true;
						score.saveData(player, currentLevel, levelProgress);
					}
					else
						impossibleAction.play();
				}
				if (event.mouseButton.button == Mouse::Left && backS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					confirmSound.play();
					currentScreen = previousScreen;
				}
				if (event.mouseButton.button == Mouse::Left && settingsS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)) && settingsClock.getElapsedTime().asSeconds() > settingsCooldown.asSeconds())
				{
					confirmSound.play();
					settingsClock.restart();
					currentScreen = GameScreen::Settings;
				}
			}

			
			window.draw(shopBackgroundS);
			if (player.UShip1 == false)
				window.draw(buyShip1S);
			if (player.UShip2 == false)
				window.draw(buyShip2S);
			if (player.UShip3 == false)
				window.draw(buyShip3S);
			window.draw(backS);
			window.draw(settingsS);
			window.draw(hud.coin);
			window.draw(score.totalScoreText);
	}
		if (currentScreen == GameScreen::Settings)
	{
		Sprite settingsBackgroundS;
		Texture settingsBackgroundT;
		if (!settingsBackgroundT.loadFromFile("inventory.png")) throw runtime_error("Erreur chargement fond inventaire");
		inventoryShipS.setPosition(49, 471);
		inventoryShip1S.setPosition(561, 471);
		inventoryShip2S.setPosition(1059, 471);
		inventoryShip3S.setPosition(1571, 471);
		backS.setScale(2, 2);
		backS.setPosition(360, 860);
		shopS.setPosition(1163, 860);
		shopS.setScale(2, 2);
		settingsBackgroundS.setTexture(settingsBackgroundT);

		Event event;

		while(window.pollEvent(event))
			if(event.type == Event::Closed)
				window.close();
		if (event.type == Event::MouseButtonPressed)
		{
			Vector2i mousePos = Mouse::getPosition(window.window);

			if (event.mouseButton.button == Mouse::Left && backS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
			{
				confirmSound.play();
				currentScreen = previousScreen;
			}
			if (event.mouseButton.button == Mouse::Left && shopS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)) && settingsClock.getElapsedTime().asSeconds() > settingsCooldown.asSeconds())
			{
				confirmSound.play();
				settingsClock.restart();
				currentScreen = GameScreen::Shop;
			}
			if (event.mouseButton.button == Mouse::Left && inventoryShipS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
			{
				confirmSound.play();
				player.ship = Default;
				player.handleShipTexture();
				currentScreen = previousScreen;
			}
			if (player.UShip1 == true && event.mouseButton.button == Mouse::Left && inventoryShip1S.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
			{
				confirmSound.play();
				player.ship = Ship1;
				player.handleShipTexture();
				currentScreen = previousScreen;
			}
			if (player.UShip2 == true && event.mouseButton.button == Mouse::Left && inventoryShip2S.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
			{
				confirmSound.play();
				player.ship = Ship2;
				player.handleShipTexture();
				currentScreen = previousScreen;
			}
			if (player.UShip3 == true && event.mouseButton.button == Mouse::Left && inventoryShip3S.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
			{
				confirmSound.play();
				player.ship = Ship3;
				player.handleShipTexture();
				currentScreen = previousScreen;
			}
		}

		window.draw(settingsBackgroundS);
		window.draw(inventoryShipS);
		if(player.UShip1 == true)
			window.draw(inventoryShip1S);
		if(player.UShip2 == true)
			window.draw(inventoryShip2S);
		if(player.UShip3 == true)
			window.draw(inventoryShip3S);
		window.draw(backS);
		window.draw(shopS);
	}

		if (currentScreen == GameScreen::SetDifficulty)
	{
		score.openData(player, levelProgress);
		if (previousScreen == GameScreen::Editor)
			loadEdited = true;
		backS.setScale(2, 2);
		Sprite SetDifficultyS;
		Texture SetDifficultyT;
		if (!SetDifficultyT.loadFromFile("difficulty.png")) throw runtime_error("Erreur : texture fond difficulté non trouvé");
		SetDifficultyS.setTexture(SetDifficultyT);
		easyS.setPosition(276, 496);
		normalS.setPosition(760, 496);
		hardcoreS.setPosition(1240, 496);
		backS.setPosition(760, 777);
		if (previousScreen == GameScreen::Editor)
			if (editorM.getStatus() != Sound::Playing)
				editorM.play();
		if (previousScreen == GameScreen::Menu)
			if (titleScreenM.getStatus() != Sound::Playing)
				titleScreenM.play();

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::MouseButtonPressed)
			{
				Vector2i mousePos = Mouse::getPosition(window.window);

				if (event.mouseButton.button == Mouse::Left && easyS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					player.setDifficulty(Easy);
					confirmSound.play();
					titleScreenM.stop();
					previousScreen = currentScreen;
					if (loadCampain == true)
					{
						currentScreen = GameScreen::Playing;
						loadCampain = false;
						if (levelProgress.UfinalBoss == true)
							currentLevel = GameLevel::FinalBoss;
						else if (levelProgress.Univeau3C == true)
							currentLevel = GameLevel::Niveau3C;
						else if (levelProgress.Univeau3B == true)
							currentLevel = GameLevel::Niveau3B;
						else if (levelProgress.Univeau3A == true)
							currentLevel = GameLevel::Niveau3A;
						else if (levelProgress.Univeau2C == true)
							currentLevel = GameLevel::Niveau2C;
						else if (levelProgress.Univeau2B == true)
							currentLevel = GameLevel::Niveau2B;
						else if (levelProgress.Univeau2A == true)
							currentLevel = GameLevel::Niveau2A;
						else if (levelProgress.Univeau1C == true)
							currentLevel = GameLevel::Niveau1C;
						else if (levelProgress.Univeau1B == true)
							currentLevel = GameLevel::Niveau1B;
						else
							currentLevel = GameLevel::Niveau1A;
					}
					else if (loadEdited == true)
					{
						currentScreen = previousScreen;
						currentScreen = GameScreen::Editor;
						loadEdited = false;
					}
					
				}
				if (event.mouseButton.button == Mouse::Left && normalS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					player.setDifficulty(Normal);
					confirmSound.play();
					titleScreenM.stop();
					previousScreen = currentScreen;
					if (loadCampain == true)
					{
						currentScreen = GameScreen::Playing;
						loadCampain = false;
						if (levelProgress.UfinalBoss == true)
							currentLevel = GameLevel::FinalBoss;
						else if (levelProgress.Univeau3C == true)
							currentLevel = GameLevel::Niveau3C;
						else if (levelProgress.Univeau3B == true)
							currentLevel = GameLevel::Niveau3B;
						else if (levelProgress.Univeau3A == true)
							currentLevel = GameLevel::Niveau3A;
						else if (levelProgress.Univeau2C == true)
							currentLevel = GameLevel::Niveau2C;
						else if (levelProgress.Univeau2B == true)
							currentLevel = GameLevel::Niveau2B;
						else if (levelProgress.Univeau2A == true)
							currentLevel = GameLevel::Niveau2A;
						else if (levelProgress.Univeau1C == true)
							currentLevel = GameLevel::Niveau1C;
						else if (levelProgress.Univeau1B == true)
							currentLevel = GameLevel::Niveau1B;
						else
							currentLevel = GameLevel::Niveau1A;
					}
					else if (loadEdited == true)
					{
						currentScreen = GameScreen::Editor;
						loadEdited = false;
					}
					
				}
				if (event.mouseButton.button == Mouse::Left && hardcoreS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					player.setDifficulty(Hardcore);
					confirmSound.play();
					titleScreenM.stop();
					previousScreen = currentScreen;
					if (loadCampain == true)
					{
						currentScreen = GameScreen::Playing;
						loadCampain = false;
						if (levelProgress.UfinalBoss == true)
							currentLevel = GameLevel::FinalBoss;
						else if (levelProgress.Univeau3C == true)
							currentLevel = GameLevel::Niveau3C;
						else if (levelProgress.Univeau3B == true)
							currentLevel = GameLevel::Niveau3B;
						else if (levelProgress.Univeau3A == true)
							currentLevel = GameLevel::Niveau3A;
						else if (levelProgress.Univeau2C == true)
							currentLevel = GameLevel::Niveau2C;
						else if (levelProgress.Univeau2B == true)
							currentLevel = GameLevel::Niveau2B;
						else if (levelProgress.Univeau2A == true)
							currentLevel = GameLevel::Niveau2A;
						else if (levelProgress.Univeau1C == true)
							currentLevel = GameLevel::Niveau1C;
						else if (levelProgress.Univeau1B == true)
							currentLevel = GameLevel::Niveau1B;
						else
							currentLevel = GameLevel::Niveau1A;
					}
					else if (loadEdited == true)
					{
						currentScreen = GameScreen::Editor;
						loadEdited = false;
					}
				}
				if (event.mouseButton.button == Mouse::Left && backS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					confirmSound.play();
					currentScreen = GameScreen::Menu;
					loadCampain = false;
					loadEdited = false;
				}
			}
		}
		window.draw(SetDifficultyS);
		window.draw(hardcoreS);
		window.draw(easyS);
		window.draw(normalS);
		window.draw(backS);
	}

		if (currentScreen == GameScreen::EreaseData)
	{
		Sprite EreaseDataS;
		Texture EreaseDataT;
		if (!EreaseDataT.loadFromFile("erease-Red.png")) throw runtime_error("Erreur: texture du fond non chargée");
		EreaseDataS.setTexture(EreaseDataT);
		confirmS.setPosition(1160, 519);
		cancelS.setPosition(360, 519);
		resetS.setPosition(760, 778);

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::MouseButtonPressed)
			{
				Vector2i mousePos = Mouse::getPosition(window.window);

				if (event.mouseButton.button == Mouse::Left && cancelS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					confirmSound.play();
					currentScreen = previousScreen;
				}
				if (event.mouseButton.button == Mouse::Left && confirmS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					confirmSound.play();
					currentScreen = previousScreen;
					score.removeData(player, levelProgress, currentLevel);
					currentLevel = GameLevel::Niveau1A;
					score.saveData(player, currentLevel, levelProgress);
					score.openData(player, levelProgress);
				}
				if (event.mouseButton.button == Mouse::Left && resetS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)) && levelProgress.hasWon == true)
				{
					confirmSound.play();
					currentScreen = previousScreen;
					score.resetQuest(player, levelProgress);
					currentLevel = GameLevel::Niveau1A;
					score.saveData(player, currentLevel, levelProgress);
					score.openData(player, levelProgress);
				}
			}
		}
		window.draw(EreaseDataS);
		window.draw(confirmS);
		window.draw(cancelS);
		if(levelProgress.hasWon == true)
		window.draw(resetS);
	}

		if (currentScreen == GameScreen::Menu) {
		score.setTotalScoreText(player);
		editorM.stop();
		if (titleScreenM.getStatus() != Sound::Playing)
			titleScreenM.play();
		backgroundSprite.setTexture(textureManager.getTexture("mainmenu"));
		backgroundSprite.setPosition(0, 0);

		// title
		title.setFont(font);
		title.setString("ZENIROX");
		title.setCharacterSize(150);
		title.setFillColor(sf::Color::White);
		title.setOutlineColor(sf::Color::Black);
		title.setOutlineThickness(6);
		title.setPosition(665, 100);
		closeS.setPosition(510, 733); closeS.setScale(1.5, 1.5);
		editorS.setPosition(1110, 321); editorS.setScale(1.5, 1.5);
		dataS.setPosition(1110, 733); dataS.setScale(1.5, 1.5);
		questS.setPosition(510, 321); questS.setScale(1.5, 1.5);
		settingsS.setPosition(510, 527); settingsS.setScale(1.5, 1.5);
		shopS.setPosition(1110, 527); shopS.setScale(1.5, 1.5);
		


		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::MouseButtonPressed)
			{
				Vector2i mousePos = Mouse::getPosition(window.window);

				if (event.mouseButton.button == Mouse::Left && editorS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					confirmSound.play();
					currentLevel = GameLevel::NiveauEDIT;
					previousScreen = currentScreen;
					currentScreen = GameScreen::SetDifficulty;
					loadEdited = true;
					score.openData(player, levelProgress);
				}
				if (event.mouseButton.button == Mouse::Left && dataS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					confirmSound.play();
					previousScreen = currentScreen;
					currentScreen = GameScreen::EreaseData;
					score.openData(player, levelProgress);
				}
				if (event.mouseButton.button == Mouse::Left && questS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					confirmSound.play();
					previousScreen = currentScreen;
					currentScreen = GameScreen::SetDifficulty;
					loadCampain = true; //Load campain veut dire charger Quest (Playing)
					score.openData(player, levelProgress);
				}
				if (event.mouseButton.button == Mouse::Left && settingsS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					confirmSound.play();
					previousScreen = currentScreen;
					currentScreen = GameScreen::Settings;
					score.openData(player, levelProgress);
				}
				if (event.mouseButton.button == Mouse::Left && shopS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					confirmSound.play();
					previousScreen = currentScreen;
					currentScreen = GameScreen::Shop;
					score.openData(player, levelProgress);
				}
				if (event.mouseButton.button == Mouse::Left && closeS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					confirmSound.play();
					window.close();
				}
			}
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Enter || event.key.code == Keyboard::Escape)
					window.close();
			}
		}
		window.draw(backgroundSprite);
		window.draw(title);
		window.draw(closeS);
		//window.draw(confirmS);
		window.draw(editorS);
		//window.draw(cancelS);
		window.draw(dataS);
		//window.draw(easyS);
		//window.draw(hardcoreS);
		//window.draw(menuS);
		//window.draw(normalS);
		window.draw(questS);
		//window.draw(resumeS);
		window.draw(settingsS);
		//window.draw(buyS);
		//window.draw(yesS);
		//window.draw(noS);
		window.draw(shopS);
	}

		if (currentScreen == GameScreen::Win)
		{
		projectileManager.clear();
		obstacleManager.clear();
		utilitaryManager.clear();
		explosionManager.clear();
		enemyManager.clear();
		resetS.setPosition(764, 872);
		settingsS.setScale(2, 2);
		settingsS.setPosition(192, 872);
		closeS.setScale(2, 2);
		closeS.setPosition(1328, 872);
		menuS.setScale(2, 2);
		menuS.setPosition(1329, 642);
		finalBossM.stop();
		boss.stop();
		playing.stop();
		nextLevelM.stop();
		editorM.stop();
		editorM.stop();
		if(victoryM.getStatus() != Sound::Playing)
			victoryM.play();
		Sprite winBackground;
		Texture winBackgroundT;
		if (!winBackgroundT.loadFromFile("winscreen.png")) throw runtime_error("Erreur lors du chargement de l'ecran de victoire");
		winBackground.setTexture(winBackgroundT);

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				score.saveCurrentScore(player);
				score.saveData(player, currentLevel, levelProgress);
				score.openData(player, levelProgress);
				window.close();
			}
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Enter)
				{
					score.saveCurrentScore(player);
					score.saveData(player, currentLevel, levelProgress);
					score.openData(player, levelProgress);
					window.close();
				}
			}
			if (event.type == Event::MouseButtonPressed)
			{
				Vector2i mousePos = Mouse::getPosition(window.window);

				if (event.mouseButton.button == Mouse::Left && resetS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					confirmSound.play();
					currentScreen = previousScreen;
					score.resetQuest(player, levelProgress);
					currentLevel = GameLevel::Niveau1A;
					score.saveData(player, currentLevel, levelProgress);
					score.openData(player, levelProgress);
				}

				if (event.mouseButton.button == Mouse::Left && settingsS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					confirmSound.play();
					previousScreen = currentScreen;
					currentScreen = GameScreen::Settings;
				}
				if (event.mouseButton.button == Mouse::Left && closeS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					score.saveCurrentScore(player);
					score.saveData(player, currentLevel, levelProgress);
					score.openData(player, levelProgress);
					window.close();
				}
				if (event.mouseButton.button == Mouse::Left && menuS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					score.saveCurrentScore(player);
					score.saveData(player, currentLevel, levelProgress);
					previousScreen = currentScreen;
					victoryM.stop();
					currentScreen = GameScreen::Menu;
				}
			}
		}
		window.draw(winBackground);
		window.draw(settingsS);
		window.draw(closeS);
		window.draw(resetS);
		window.draw(menuS);
		}

		if (currentScreen == GameScreen::Lost)
		{
		menuS.setPosition(192 , 714);
		closeS.setPosition(760 , 714);
		closeS.setScale(2, 2);
		continueS.setPosition(1328, 714);
		Sprite lostScreen;
		Texture lostScreenT;
		if (!lostScreenT.loadFromFile("lostscreen.png")) throw runtime_error("Erreur lors du chargement de l'ecran de defaite");
		lostScreen.setTexture(lostScreenT);
		Event event;
		projectileManager.clear();
		obstacleManager.clear();
		utilitaryManager.clear();
		explosionManager.clear();
		enemyManager.clear();
		player.currentScore = 0;
		player.isAlive = true;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Enter)
				{
				confirmSound.play();
					switch (currentLevel)
					{
					case GameLevel::NiveauEDIT:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						previousScreen = currentScreen;
						currentScreen = GameScreen::Editor;
						counter = 1;
						break;
					case GameLevel::Niveau1A:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						break;
					case GameLevel::Niveau1B:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						break;
					case GameLevel::Niveau1C:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						break;
					case GameLevel::Niveau2A:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						break;
					case GameLevel::Niveau2B:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						break;
					case GameLevel::Niveau2C:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						break;
					case GameLevel::Niveau3A:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						break;
					case GameLevel::Niveau3B:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						break;
					case GameLevel::Niveau3C:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						break;
					case GameLevel::FinalBoss:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						break;
					default:
						break;
					}
					lose.stop();
					player.HP = player.maxHP;
					if(currentLevel != GameLevel::NiveauEDIT)
					{
						previousScreen = currentScreen;
						currentScreen = GameScreen::Playing;
					}
				}
			}
			if (event.type == Event::MouseButtonPressed)
			{
				Vector2i mousePos = Mouse::getPosition(window.window);

				if (event.mouseButton.button == Mouse::Left && continueS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					confirmSound.play();
					switch (currentLevel)
					{
					case GameLevel::NiveauEDIT:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						previousScreen = currentScreen;
						currentScreen = GameScreen::Editor;
						counter = 1;
						break;
					case GameLevel::Niveau1A:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						break;
					case GameLevel::Niveau1B:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						break;
					case GameLevel::Niveau1C:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						break;
					case GameLevel::Niveau2A:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						break;
					case GameLevel::Niveau2B:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						break;
					case GameLevel::Niveau2C:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						break;
					case GameLevel::Niveau3A:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						break;
					case GameLevel::Niveau3B:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						break;
					case GameLevel::Niveau3C:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						break;
					case GameLevel::FinalBoss:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						break;
					default:
						break;
					}
					lose.stop();
					player.HP = player.maxHP;
					if (currentLevel != GameLevel::NiveauEDIT)
					{
						previousScreen = currentScreen;
						currentScreen = GameScreen::Playing;
					}
				}

				if (event.mouseButton.button == Mouse::Left && menuS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					confirmSound.play();
					switch (currentLevel)
					{
					case GameLevel::NiveauEDIT:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						previousScreen = currentScreen;
						currentScreen = GameScreen::Editor;
						counter = 1;
						break;
					case GameLevel::Niveau1A:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						break;
					case GameLevel::Niveau1B:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						break;
					case GameLevel::Niveau1C:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						break;
					case GameLevel::Niveau2A:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						break;
					case GameLevel::Niveau2B:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						break;
					case GameLevel::Niveau2C:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						break;
					case GameLevel::Niveau3A:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						break;
					case GameLevel::Niveau3B:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						break;
					case GameLevel::Niveau3C:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						break;
					case GameLevel::FinalBoss:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						break;
					default:
						break;
					}
					player.HP = player.maxHP;
					lose.stop();
					confirmSound.play();
					previousScreen = currentScreen;
					currentScreen = GameScreen::Menu;
					counter = 1;
					currentID = 0;
				}
				if (event.mouseButton.button == Mouse::Left && closeS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					window.close();
				}
			}
		}
		window.draw(lostScreen);
		window.draw(continueS);
		window.draw(closeS);
		window.draw(menuS);
		}

		if (currentScreen == GameScreen::NextLevel)
		{
		editorM.stop();
		if (player.difficulty != Hardcore)
			player.HP = player.maxHP;
		else
			player.shield = 0;
		continueS.setPosition(764, 872);
		settingsS.setScale(2, 2);
		settingsS.setPosition(192, 872);
		closeS.setScale(2, 2);
		closeS.setPosition(1328 , 872);
		menuS.setScale(2, 2);
		menuS.setPosition(1329, 642);
		
		boss.stop();
		if (nextLevelM.getStatus() != Sound::Playing)
			nextLevelM.play();
		finalBossM.stop();
		finalhours.stop();
		obstacleManager.clear();
		utilitaryManager.clear();
		explosionManager.clear();
		projectileManager.clear();
		hud.coin.setScale(0.5, 0.5);
		hud.coin.setPosition(750, 670);
		score.saveCurrentScore(player);
		score.setTotalScoreText(player);
		player.currentScore = 0;
		Sprite nextLevelBackground;
		Texture nextLevelBackgroundT;
		if (!nextLevelBackgroundT.loadFromFile("levelwin.png")) throw runtime_error("Erreur de chargement du fond de niveau suivant");
		nextLevelBackground.setTexture(nextLevelBackgroundT);
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				score.saveCurrentScore(player);
				score.saveData(player, currentLevel, levelProgress);
				switch (currentLevel)
				{
				case GameLevel::NiveauEDIT:
					loadLevel = true;
					doLoadBackground = true;
					levelProgress.isFightingBoss = false;
					counter = 1;
					currentLevel = GameLevel::NiveauEDIT;
					currentScreen = GameScreen::Editor;
					nextLevelM.stop();
					break;
				case GameLevel::Niveau1A:
					levelProgress.isFightingBoss = false;
					loadLevel = true;
					doLoadBackground = true;
					levelProgress.Univeau1B = true;
					currentLevel = GameLevel::Niveau1B;
					break;
				case GameLevel::Niveau1B:
					levelProgress.isFightingBoss = false;
					loadLevel = true;
					doLoadBackground = true;
					levelProgress.Univeau1C = true;
					currentLevel = GameLevel::Niveau1C;
					break;
				case GameLevel::Niveau1C:
					levelProgress.isFightingBoss = false;
					loadLevel = true;
					levelProgress.Univeau2A = true;
					currentLevel = GameLevel::Niveau2A;
					break;
				case GameLevel::Niveau2A:
					levelProgress.isFightingBoss = false;
					loadLevel = true;
					levelProgress.Univeau2B = true;
					currentLevel = GameLevel::Niveau2B;
					break;
				case GameLevel::Niveau2B:
					levelProgress.isFightingBoss = false;
					loadLevel = true;
					levelProgress.Univeau2C = true;
					currentLevel = GameLevel::Niveau2C;
					break;
				case GameLevel::Niveau2C:
					levelProgress.isFightingBoss = false;
					loadLevel = true;
					levelProgress.Univeau3A = true;
					currentLevel = GameLevel::Niveau3A;
					break;
				case GameLevel::Niveau3A:
					levelProgress.isFightingBoss = false;
					loadLevel = true;
					levelProgress.Univeau3B = true;
					currentLevel = GameLevel::Niveau3B;
					break;
				case GameLevel::Niveau3B:
					levelProgress.isFightingBoss = false;
					loadLevel = true;
					levelProgress.Univeau3C = true;
					currentLevel = GameLevel::Niveau3C;
					break;
				case GameLevel::Niveau3C:
					levelProgress.isFightingBoss = false;
					loadLevel = true;
					levelProgress.UfinalBoss = true;
					currentLevel = GameLevel::FinalBoss;
					break;
				case GameLevel::FinalBoss:
					break;
				default:
					break;
				}
				window.close();
			}
			if (event.type == Event::KeyPressed)
			{
				
				if (event.key.code == Keyboard::Enter)
				{
				confirmSound.play();
					switch (currentLevel)
					{
					case GameLevel::NiveauEDIT:
						score.saveCurrentScore(player);
						score.saveData(player, currentLevel, levelProgress);
						score.openData(player, levelProgress);
						loadLevel = true;
						doLoadBackground = true;
						levelProgress.isFightingBoss = false;
						counter = 1;
						currentLevel = GameLevel::NiveauEDIT;
						previousScreen = currentScreen;
						currentScreen = GameScreen::Editor;
						nextLevelM.stop();
						break;
					case GameLevel::Niveau1A:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						levelProgress.Univeau1B = true;
						currentLevel = GameLevel::Niveau1B;
						break;
					case GameLevel::Niveau1B:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						levelProgress.Univeau1C = true;
						currentLevel = GameLevel::Niveau1C;
						break;
					case GameLevel::Niveau1C:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						levelProgress.Univeau2A = true;
						currentLevel = GameLevel::Niveau2A;
						break;
					case GameLevel::Niveau2A:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						levelProgress.Univeau2B = true;
						currentLevel = GameLevel::Niveau2B;
						break;
					case GameLevel::Niveau2B:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						levelProgress.Univeau2C = true;
						currentLevel = GameLevel::Niveau2C;
						break;
					case GameLevel::Niveau2C:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						levelProgress.Univeau3A = true;
						currentLevel = GameLevel::Niveau3A;
						break;
					case GameLevel::Niveau3A:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						levelProgress.Univeau3B = true;
						currentLevel = GameLevel::Niveau3B;
						break;
					case GameLevel::Niveau3B:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						levelProgress.Univeau3C = true;
						currentLevel = GameLevel::Niveau3C;
						break;
					case GameLevel::Niveau3C:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						levelProgress.UfinalBoss = true;
						currentLevel = GameLevel::FinalBoss;
						break;
					case GameLevel::FinalBoss:
						break;
					default:
						break;
					}
					player.currentScore = 0;
					hud.coin.setPosition(0.f, 50.f);
					hud.coin.setScale(0.2f, 0.2f);
					if(currentLevel != GameLevel::NiveauEDIT)
					{
						previousScreen = currentScreen;
						currentScreen = GameScreen::Playing;
						nextLevelM.stop();
					}

				}
			}
			if (event.type == Event::MouseButtonPressed)
			{
				Vector2i mousePos = Mouse::getPosition(window.window);

				if (event.mouseButton.button == Mouse::Left && continueS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					confirmSound.play();
					switch (currentLevel)
					{
					case GameLevel::NiveauEDIT:
						loadLevel = true;
						doLoadBackground = true;
						levelProgress.isFightingBoss = false;
						counter = 1;
						currentLevel = GameLevel::NiveauEDIT;
						previousScreen = currentScreen;
						currentScreen = GameScreen::Editor;
						nextLevelM.stop();
						break;
					case GameLevel::Niveau1A:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						levelProgress.Univeau1B = true;
						currentLevel = GameLevel::Niveau1B;
						break;
					case GameLevel::Niveau1B:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						levelProgress.Univeau1C = true;
						currentLevel = GameLevel::Niveau1C;
						break;
					case GameLevel::Niveau1C:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						levelProgress.Univeau2A = true;
						currentLevel = GameLevel::Niveau2A;
						break;
					case GameLevel::Niveau2A:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						levelProgress.Univeau2B = true;
						currentLevel = GameLevel::Niveau2B;
						break;
					case GameLevel::Niveau2B:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						levelProgress.Univeau2C = true;
						currentLevel = GameLevel::Niveau2C;
						break;
					case GameLevel::Niveau2C:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						levelProgress.Univeau3A = true;
						currentLevel = GameLevel::Niveau3A;
						break;
					case GameLevel::Niveau3A:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						levelProgress.Univeau3B = true;
						currentLevel = GameLevel::Niveau3B;
						break;
					case GameLevel::Niveau3B:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						levelProgress.Univeau3C = true;
						currentLevel = GameLevel::Niveau3C;
						break;
					case GameLevel::Niveau3C:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						levelProgress.UfinalBoss = true;
						currentLevel = GameLevel::FinalBoss;
						break;
					case GameLevel::FinalBoss:
						break;
					default:
						break;
					}
					score.saveCurrentScore(player);
					score.saveData(player, currentLevel, levelProgress);
					player.currentScore = 0;
					hud.coin.setPosition(0.f, 50.f);
					hud.coin.setScale(0.2f, 0.2f);
					if (currentLevel != GameLevel::NiveauEDIT)
					{
						previousScreen = currentScreen;
						currentScreen = GameScreen::Playing;
						nextLevelM.stop();
					}

				}

				if (event.mouseButton.button == Mouse::Left && settingsS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					confirmSound.play();
					previousScreen = currentScreen;
					currentScreen = GameScreen::Settings;
				}
				if (event.mouseButton.button == Mouse::Left && closeS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					confirmSound.play();
					switch (currentLevel)
					{
					case GameLevel::NiveauEDIT:
						loadLevel = true;
						doLoadBackground = true;
						levelProgress.isFightingBoss = false;
						counter = 1;
						currentLevel = GameLevel::NiveauEDIT;
						previousScreen = currentScreen;
						currentScreen = GameScreen::Editor;
						nextLevelM.stop();
						break;
					case GameLevel::Niveau1A:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						levelProgress.Univeau1B = true;
						currentLevel = GameLevel::Niveau1B;
						break;
					case GameLevel::Niveau1B:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						levelProgress.Univeau1C = true;
						currentLevel = GameLevel::Niveau1C;
						break;
					case GameLevel::Niveau1C:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						levelProgress.Univeau2A = true;
						currentLevel = GameLevel::Niveau2A;
						break;
					case GameLevel::Niveau2A:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						levelProgress.Univeau2B = true;
						currentLevel = GameLevel::Niveau2B;
						break;
					case GameLevel::Niveau2B:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						levelProgress.Univeau2C = true;
						currentLevel = GameLevel::Niveau2C;
						break;
					case GameLevel::Niveau2C:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						levelProgress.Univeau3A = true;
						currentLevel = GameLevel::Niveau3A;
						break;
					case GameLevel::Niveau3A:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						levelProgress.Univeau3B = true;
						currentLevel = GameLevel::Niveau3B;
						break;
					case GameLevel::Niveau3B:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						levelProgress.Univeau3C = true;
						currentLevel = GameLevel::Niveau3C;
						break;
					case GameLevel::Niveau3C:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						levelProgress.UfinalBoss = true;
						currentLevel = GameLevel::FinalBoss;
						break;
					case GameLevel::FinalBoss:
						break;
					default:
						break;
					}
					score.saveCurrentScore(player);
					score.saveData(player, currentLevel, levelProgress);
					window.close();
				}
				if (event.mouseButton.button == Mouse::Left && menuS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					confirmSound.play();
					switch (currentLevel)
					{
					case GameLevel::NiveauEDIT:
						loadLevel = true;
						doLoadBackground = true;
						levelProgress.isFightingBoss = false;
						counter = 1;
						currentLevel = GameLevel::NiveauEDIT;
						previousScreen = currentScreen;
						currentScreen = GameScreen::Editor;
						nextLevelM.stop();
						break;
					case GameLevel::Niveau1A:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						levelProgress.Univeau1B = true;
						currentLevel = GameLevel::Niveau1B;
						break;
					case GameLevel::Niveau1B:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						doLoadBackground = true;
						levelProgress.Univeau1C = true;
						currentLevel = GameLevel::Niveau1C;
						break;
					case GameLevel::Niveau1C:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						levelProgress.Univeau2A = true;
						currentLevel = GameLevel::Niveau2A;
						break;
					case GameLevel::Niveau2A:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						levelProgress.Univeau2B = true;
						currentLevel = GameLevel::Niveau2B;
						break;
					case GameLevel::Niveau2B:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						levelProgress.Univeau2C = true;
						currentLevel = GameLevel::Niveau2C;
						break;
					case GameLevel::Niveau2C:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						levelProgress.Univeau3A = true;
						currentLevel = GameLevel::Niveau3A;
						break;
					case GameLevel::Niveau3A:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						levelProgress.Univeau3B = true;
						currentLevel = GameLevel::Niveau3B;
						break;
					case GameLevel::Niveau3B:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						levelProgress.Univeau3C = true;
						currentLevel = GameLevel::Niveau3C;
						break;
					case GameLevel::Niveau3C:
						levelProgress.isFightingBoss = false;
						loadLevel = true;
						levelProgress.UfinalBoss = true;
						currentLevel = GameLevel::FinalBoss;
						break;
					case GameLevel::FinalBoss:
						break;
					default:
						break;
					}
					score.saveCurrentScore(player);
					score.saveData(player, currentLevel, levelProgress);
					hud.coin.setPosition(0.f, 50.f);
					hud.coin.setScale(0.2f, 0.2f);
					previousScreen = currentScreen;
					nextLevelM.stop();
					currentScreen = GameScreen::Menu;
				}
			}
		}
		window.draw(nextLevelBackground);
		window.draw(score.totalScoreText);
		window.draw(hud.coin);
		window.draw(settingsS);
		window.draw(closeS);
		window.draw(continueS);
		window.draw(menuS);
		}

		if (currentScreen == GameScreen::Editor)
	{
		player.shield = 0;
		if(editorM.getStatus() != Sound::Playing)
			editorM.play();
		vector <ID> IDlist{ ENNEMI1, ENNEMI2, ENNEMI3, BOSS1, BOSS2, BOSS3, BOSS4 };
		Text numerotation;
		numerotation.setString(to_string(counter));
		if (counter > 10)
			numerotation.setString("Boss");
		numerotation.setFont(fontManager.getFont("Engcomica"));
		numerotation.setOutlineThickness(6);
		numerotation.setOutlineColor(Color::Black);
		numerotation.setPosition(1220, 35);
		numerotation.setCharacterSize(200);
		RectangleShape editorBackground(Vector2f(1920, 1080));
		Texture editorBackgroundE;
		if (!editorBackgroundE.loadFromFile("level-editor.png")) throw runtime_error("Erreur de chargement fond editeur");
		editorBackground.setTexture(&editorBackgroundE);
		Sprite up;
		Sprite down;
		Texture upT;
		Texture downT;
		if (!upT.loadFromFile("button/up.png")) throw runtime_error("Impossible de charger le bouton haut");
		if (!downT.loadFromFile("button/down.png")) throw runtime_error("Impossible de charger le bouton bas");
		up.setTexture(upT);
		down.setTexture(downT);
		up.setPosition(500.f, 400.f);
		down.setPosition(500.f, 600.f);
		Sprite enemySprite;
		Texture enemyTexture;
		enemySprite.setPosition(900.f, 500.f);
		settingsS.setScale(1.5f, 1.5f);
		settingsS.setPosition(1480.f, 835.f);
		confirmS.setScale(1.5f, 1.5f);
		confirmS.setPosition(140.f, 290.f);
		backS.setScale(1.5f, 1.5f);
		backS.setPosition(140.f, 835.f);
		cancelS.setScale(1.5f, 1.5f);
		cancelS.setPosition(140.f, 480.f);
		yesS.setPosition(1480.f, 359.f);
		yes2S.setPosition(1480.f, 655.f);
		if (EloadObstacle == true)
			yesS.setTexture(textureManager.getTexture("yes"));
		else
			yesS.setTexture(textureManager.getTexture("no"));
		if (EloadPowerups == true)
			yes2S.setTexture(textureManager.getTexture("yes"));
		else
			yes2S.setTexture(textureManager.getTexture("no"));
		alias = &IDlist[currentID];
		switch (*alias)
		{
		case ENNEMI1:
			if (!enemyTexture.loadFromFile("enemy1.png")) throw runtime_error("Erreur chargement ennemi1");
			break;
		case ENNEMI2:
			if (!enemyTexture.loadFromFile("enemy2.png")) throw runtime_error("Erreur chargement ennemi1");
			break;
		case ENNEMI3:
			if (!enemyTexture.loadFromFile("enemy3.png")) throw runtime_error("Erreur chargement ennemi1");
			break;
		case BOSS1:
			if (!enemyTexture.loadFromFile("boss1.png")) throw runtime_error("Erreur chargement ennemi1");
			break;
		case BOSS2:
			if (!enemyTexture.loadFromFile("boss2.png")) throw runtime_error("Erreur chargement ennemi1");
			break;
		case BOSS3:
			if (!enemyTexture.loadFromFile("boss3.png")) throw runtime_error("Erreur chargement ennemi1");
			break;
		case BOSS4:
			if (!enemyTexture.loadFromFile("boss4.png")) throw runtime_error("Erreur chargement ennemi1");
			break;
		default:
			break;
		}
		enemySprite.setTexture(enemyTexture);

		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::MouseButtonPressed || event.type == Event::KeyPressed)
			{
				Vector2i mousePos = Mouse::getPosition(window.window);
				if (event.mouseButton.button == Mouse::Left && up.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)) || event.key.code == Keyboard::Up)
				{
					
					if (currentID != IDlist.size() - 1)
					{
						currentID++;
						clickSound.play();
					}
					else
						impossibleAction.play();
				}
				if (event.mouseButton.button == Mouse::Left && yesS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)) || event.key.code == Keyboard::Down)
				{
					confirmSound.play();
					if (EloadObstacle == false)
						EloadObstacle = true;
					else
						EloadObstacle = false;
				}
				if (event.mouseButton.button == Mouse::Left && yes2S.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)) || event.key.code == Keyboard::Down)
				{
					confirmSound.play();
					if (EloadPowerups == false)
						EloadPowerups = true;
					else
						EloadPowerups = false;
				}
				if (event.mouseButton.button == Mouse::Left && down.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)) || event.key.code == Keyboard::Down)
				{
					
					if (currentID != 0)
					{
						currentID--;
						clickSound.play();
					}
					else
						impossibleAction.play();
				}
				if (event.mouseButton.button == Mouse::Left && backS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)) || event.key.code == Keyboard::Down)
				{
					confirmSound.play();
					currentScreen = previousScreen;
					previousScreen = GameScreen::Editor;
					counter = 1;
					currentID = 0;
					
				}
				if (event.mouseButton.button == Mouse::Left && cancelS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)) || event.key.code == Keyboard::Down)
				{
					confirmSound.play();
					counter--;
					if (counter < 1)
						counter = 1;
					

				}
				if (event.mouseButton.button == Mouse::Left && settingsS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)) || event.key.code == Keyboard::Down)
				{
					confirmSound.play();
					counter--;
					currentScreen = previousScreen;
					currentScreen = GameScreen::Settings;


				}
				if (event.mouseButton.button == Mouse::Left && confirmS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)) || event.key.code == Keyboard::Down)
				{

					confirmSound.play();
					switch (counter)
					{
					case 1:
						nb1 = *alias;
						alias = &nb2;
						break;
					case 2:
						nb2 = *alias;
						alias = &nb3;
						break;
					case 3:
						nb3 = *alias;
						alias = &nb4;
						break;
					case 4:

						nb4 = *alias;
						alias = &nb5;
						break;
					case 5:
						nb5 = *alias;
						alias = &nb6;
						break;
					case 6:
						nb6 = *alias;
						alias = &nb7;
						break;
					case 7:
						nb7 = *alias;
						alias = &nb8;
						break;
					case 8:
						nb8 = *alias;
						alias = &nb9;
						break;
					case 9:
						nb9 = *alias;
						alias = &nb10;
						break;
					case 10:
						nb10 = *alias;
						alias = &bossID;
						break;
					default:
						bossID = *alias;
						player.HP = player.maxHP;
						previousScreen = currentScreen;
						currentScreen = GameScreen::Playing;
						editorM.stop();
						break;
					}
					counter++;
				}
			}
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Space)
				{
				confirmSound.play();
					switch (counter)
					{
					case 1:
						nb1 = *alias;
						alias = &nb2;
						break;
					case 2:
						nb2 = *alias;
						alias = &nb3;
						break;
					case 3:
						nb3 = *alias;
						alias = &nb4;
						break;
					case 4:

						nb4 = *alias;
						alias = &nb5;
						break;
					case 5:
						nb5 = *alias;
						alias = &nb6;
						break;
					case 6:
						nb6 = *alias;
						alias = &nb7;
						break;
					case 7:
						nb7 = *alias;
						alias = &nb8;
						break;
					case 8:
						nb8 = *alias;
						alias = &nb9;
						break;
					case 9:
						nb9 = *alias;
						alias = &nb10;
						break;
					case 10:
						nb10 = *alias;
						alias = &bossID;
						break;
					default:
						bossID = *alias;
						player.HP = player.maxHP;
						previousScreen = currentScreen;
						currentScreen = GameScreen::Playing;
						editorM.stop();
						break;
					}
					counter++;
				}
			}
		}
		window.draw(editorBackground);
		window.draw(confirmS);
		window.draw(settingsS);
		window.draw(backS);
		window.draw(cancelS);
		window.draw(numerotation);
		window.draw(enemySprite);
		window.draw(up);
		window.draw(down);
		window.draw(yesS);
		window.draw(yes2S);
	}

	/////////////////////////////////////////////////////////////////////

		if (currentScreen == GameScreen::Playing)
	{
		hud.coin.setScale(0.2f, 0.2f);
		hud.coin.setPosition(0, 45);
		pauseS.setScale(1, 1);
		pauseS.setPosition(1100, 0);
		if (gameClock.getElapsedTime().asSeconds() > gameDuration.asSeconds() - gameDuration.asSeconds() / 4 && finalhours.getStatus() != Sound::Playing && player.HP >= 0 && lose.getStatus() != Sound::Playing)
		{
			playing.stop();
			finalBossM.stop();
			boss.stop();
			finalhours.play();
		}
		if (currentLevel != GameLevel::NiveauEDIT && levelDatabase.count(currentLevel))
		{
			if (currentLevel == GameLevel::FinalBoss && loadLevel)
			{
				sf::Color bossPurple(245, 194, 254);
				star.sprite.setColor(bossPurple);
				star.sprite2.setColor(bossPurple);
				faststar.sprite.setColor(bossPurple);
				faststar.sprite2.setColor(bossPurple);
			}
			playLevel(currentLevel, player, enemyManager, obstacleManager, projectileManager, utilitaryManager, explosionManager, playing, boss, finalBossM, background);

			if (currentLevel == GameLevel::FinalBoss && currentScreen == GameScreen::Win)
			{
				score.saveData(player, currentLevel, levelProgress);
				score.openData(player, levelProgress);
			}
		}
		else if (currentLevel == GameLevel::NiveauEDIT)
			levelP(player, enemyManager, obstacleManager, projectileManager, utilitaryManager, explosionManager, playing, boss, finalBossM, background);

		if (player.boostClock.getElapsedTime().asSeconds() < player.boostDuration.asSeconds() && player.canBeBoosted == true)
		{
			player.attackCooldown = seconds(0.1f);
		}
		else
			player.attackCooldown = seconds(0.2f);

		player.checkOutOfScreen(); //Empêche de sortir de l'écran
		Event event;
		if (Keyboard::isKeyPressed(Keyboard::Up))
			player.sprite.move(0.f, -10.f);
		if (Keyboard::isKeyPressed(Keyboard::Down))
			player.sprite.move(0.f, 10.f);

		//Créé un projectile lorsqu'il y a un click gauche avec un cooldown

		if (Mouse::isButtonPressed(Mouse::Left) && player.attackClock.getElapsedTime().asSeconds() > player.attackCooldown.asSeconds()) {
			player.attackClock.restart();
			projectileManager.creerProjectile(player);
			bool soundPlayed = false;
			for (auto& shot : playerShot)
			{
				if (shot.getStatus() != Sound::Playing)
				{
					shot.play();
					cout << "Son joue" << endl;
					soundPlayed = true;
					break;
				}
			}
			if (!soundPlayed)
				playerShot[0].play();
			projectileManager.getProjectiles()[projectileManager.getProjectiles().size() - 1]->sprite.setPosition(player.sprite.getPosition().x, player.sprite.getGlobalBounds().top + 50);
		}



		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed)
			{
				if (event.key.code == Keyboard::Enter)
					window.close();
				if (event.key.code == Keyboard::Escape)
				{
					previousScreen = currentScreen;
					currentScreen = GameScreen::Paused;
				}
			}
			if (event.type == Event::MouseButtonPressed)
			{
				Vector2i mousePos = Mouse::getPosition(window.window);

				if (event.mouseButton.button == Mouse::Left && pauseS.getGlobalBounds().contains(static_cast<Vector2f>(mousePos)))
				{
					previousScreen = currentScreen;
					currentScreen = GameScreen::Paused;
				}
			}

		}

		// Calcul du deltaTime
		float deltaTime = deltaTimeClock.restart().asSeconds();
		// Mettre à jour l'arrière-plan
		background.update(deltaTime);
		star.update(deltaTime);
		faststar.update(deltaTime);


		background.draw(window);
		star.draw(window);
		faststar.draw(window);

		//Gestion de l'affichage, de la durée de vie des projectiles et des dégâts infligés
		for (unsigned int i = 0; i < projectileManager.getProjectiles().size(); i++)
		{
			window.draw(projectileManager.getProjectiles()[i]->sprite);
			if (projectileManager.getProjectiles()[i]->id == PLAYER)
				projectileManager.getProjectiles()[i]->sprite.move(14, 0);
			if (projectileManager.getProjectiles()[i]->id != PLAYER)
				projectileManager.getProjectiles()[i]->sprite.move(projectileManager.getProjectiles()[i]->velocity, 0);
			projectileManager.checkProjectileOutOfScreen(projectileManager.getProjectiles()[i], enemyManager, player, score.scoreText);
		}
		projectileManager.detruireProjectile();
		for (auto i = 0; i < utilitaryManager.getUtilitaryList().size(); i++)
		{
			window.draw(utilitaryManager.getUtilitaryList()[i]->sprite);
			utilitaryManager.getUtilitaryList()[i]->moveUtilitary();
			utilitaryManager.checkUtilitary(utilitaryManager.getUtilitaryList()[i], player, enemyManager);
		}
		//Regarde si un ennemi sort de l'écran ou si il est mort
		for (auto i = 0; i < enemyManager.getEnemies().size(); i++)
		{
			window.draw(enemyManager.getEnemies()[i]->sprite);
			cout << enemyManager.getEnemies()[i]->HP << endl;
			enemyManager.checkEnemy(enemyManager.getEnemies()[i], toKill, explosionManager);
		}
		enemyManager.detruireEnemy();
		for (auto i = 0; i < enemyManager.getEnemies().size(); i++)
		{
			if (enemyManager.getEnemies()[i]->boostClock.getElapsedTime().asSeconds() < enemyManager.getEnemies()[i]->boostDuration.asSeconds() && enemyManager.getEnemies()[i]->canBeBoosted == true)
			{
				enemyManager.getEnemies()[i]->attackCooldown = seconds(0.05f);
			}
			else
			{
				switch (enemyManager.getEnemies()[i]->id)
				{
				case ENNEMI1:
					enemyManager.getEnemies()[i]->attackCooldown = seconds(3.f);
					break;
				case ENNEMI2:
					enemyManager.getEnemies()[i]->attackCooldown = seconds(1.5f);
					break;
				case ENNEMI3:
					enemyManager.getEnemies()[i]->attackCooldown = seconds(1.f);
					break;
				case BOSS1:
					enemyManager.getEnemies()[i]->attackCooldown = seconds(0.08f);
					break;
				case BOSS2:
					enemyManager.getEnemies()[i]->attackCooldown = seconds(0.2f);
					break;
				case BOSS3:
					enemyManager.getEnemies()[i]->attackCooldown = seconds(0.2f);
					break;
				case BOSS4:
					enemyManager.getEnemies()[i]->attackCooldown = seconds(0.06f);
					break;
				}
			}
		}
		//Gestion des obstacles
		for (int i = 0; i < obstacleManager.getObstacles().size(); i++) {
			window.draw(obstacleManager.getObstacles()[i]->sprite);
			int randValue = rand() % 3;
			if (currentLevel != GameLevel::FinalBoss)
				obstacleManager.getObstacles()[i]->moveObstacle(randValue);
			else if (currentLevel == GameLevel::FinalBoss)
				obstacleManager.getObstacles()[i]->moveObstacleF();
			obstacleManager.getObstacles()[i]->checkObstacle(player);
		}
		//Gestion de l'attaque des ennemis
		for (auto i = 0; i < enemyManager.getEnemies().size(); i++)
		{
			enemyManager.getEnemies()[i]->enemyMove();
			if (enemyManager.getEnemies()[i]->rechargeClock.getElapsedTime().asSeconds() > enemyManager.getEnemies()[i]->rechargeCooldown.asSeconds())
			{

				if (enemyManager.getEnemies()[i]->attackClock.getElapsedTime().asSeconds() > enemyManager.getEnemies()[i]->attackCooldown.asSeconds())
				{
					int projVelocityChance = rand() % 3;
					int projVelocity;
					switch (projVelocityChance) {
					case 1:
						projVelocity = -6;
						break;
					case 2:
						projVelocity = -7;
						break;
					case 3:
						projVelocity = -8;
						break;
					default:
						projVelocity = -9;
						break;
					}
					enemyManager.getEnemies()[i]->attackClock.restart();
					projectileManager.creerProjectile(enemyManager.getEnemies()[i], projVelocity);
					if (enemyManager.getEnemies()[i]->sprite.getPosition().x > 0 && enemyManager.getEnemies()[i]->sprite.getPosition().x < WIDTH)
						enemyManager.getEnemies()[i]->lasershot.play();

				}


				if (enemyManager.getEnemies()[i]->rechargeClock.getElapsedTime().asSeconds() > enemyManager.getEnemies()[i]->rechargeCooldown.asSeconds() * 2)
					enemyManager.getEnemies()[i]->rechargeClock.restart();
			}

		}

		for (int i = 0; i < explosionManager.getExplosions().size(); i++)
		{
			explosionManager.getExplosions()[i]->animate();
			window.draw(explosionManager.getExplosions()[i]->sprite);
			explosionManager.getExplosions()[i]->sprite.move(-4, 0);
			if (explosionManager.getExplosions()[i]->frame == 8)
			{
				explosionManager.getExplosions()[i]->isDead = true;
			}
		}
		
		score.updateScoreText(player);
		hud.healthbar.setHealthbar(player);
		player.checkOutOfScreen();

		window.draw(hud.cockpit);

		if (player.HP > 0)
			window.draw(player.sprite);
		else
		{
			if (player.isAlive == true)
			{
				explosionManager.creerExplosion(player);
				player.isAlive = false;
				boss.stop();
				finalBossM.stop();
				playing.stop();
				finalhours.stop();
				lose.play();
				previousScreen = currentScreen;
				currentScreen = GameScreen::Lost;
				player.shield = 0;
			}
		}

		window.draw(score.scoreText);
		window.draw(hud.coin);
		window.draw(currentLevelText);
		window.draw(pauseS);
		window.draw(hud.healthbar.psprite);
		if (player.shield > 0)
			window.draw(hud.healthbar.pShield);

		if(levelProgress.isFightingBoss == true)
		{
			for (int i = 0; i < enemyManager.getEnemies().size(); i++)
			{
				if (enemyManager.getEnemies()[i]->id == ENNEMI1 || enemyManager.getEnemies()[i]->id == ENNEMI2 || enemyManager.getEnemies()[i]->id == ENNEMI3 || enemyManager.getEnemies()[i]->id == BOSS1 || enemyManager.getEnemies()[i]->id == BOSS2 || enemyManager.getEnemies()[i]->id == BOSS3 || enemyManager.getEnemies()[i]->id == BOSS4)
				{
					hud.healthbar.setHealthbar(enemyManager.getEnemies()[i]);
					window.draw(hud.healthbar.esprite);
					if (enemyManager.getEnemies()[i]->shield > 0)
						window.draw(hud.healthbar.eShield);
				}
			}
		}
		explosionManager.detruireExplosion();
	}

	if (finalhours.getStatus() == Sound::Playing)
	{
		hud.handleWarning(window.window);
	}
	window.display();
	}
}