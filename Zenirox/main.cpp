#include "game.hpp"
using namespace std;
using namespace sf;





int main() {
	srand(time(NULL));
	

	Game game;

	
	Background background(game.textureManager, -31);

	Starparallaxe star(game.textureManager, -100.f, "star");
	Starparallaxe faststar(game.textureManager, -200.f, "star");

	Healthbar healthbar;
	healthbar.setTextureList();

	sf::Clock clock;

	ProjectileManager pManager(game.textureManager);
	
	


	Music playing;
	Music boss;
	Music finalBossM;
	
	if (!playing.openFromFile("sounds/playing.ogg")) throw runtime_error("Musique de combat classique non chargee");
	playing.setLoop(true);

	if(!boss.openFromFile("sounds/boss.ogg")) throw runtime_error("Musique de combat de boss non chargee");
	boss.setLoop(true);
	if(!finalBossM.openFromFile("sounds/finalboss.ogg")) throw runtime_error("Musique de combat final non chargee");
	finalBossM.setLoop(true);

	playing.setVolume(50);
	boss.setVolume(50);
	finalBossM.setVolume(50);

	SoundBuffer shot;
	if (!shot.loadFromFile("sounds/shot.ogg")) throw runtime_error("Son de tir non charge");
	vector<Sound> playerShot{ 10 };
	for (int i = 0; i < playerShot.size(); i++)
	{
		playerShot[i].setBuffer(shot);
	}


	
	Sprite skull;
	Texture skullT;
	if (!skullT.loadFromFile("skull.png")) throw runtime_error("Erreur chargement crane");
	skull.setTexture(skullT);
	skull.setColor(Color::Red);
	skull.setScale(0.1, 0.1);
	skull.setPosition(350, 0);
	

	while (window.isOpen()){
		//Chargement des niveaux
		game.run(window, player, coin, background, star, faststar, healthbar, eManager, pManager, oManager, uManager, exManager, clock, scoreText, scoreFont, cockpit, playing, boss, finalBossM, playerShot, shot, totalScoreText);







		if(game.state == niveauEDIT && game.isFightingBoss == false)
		{
			for (int i = 0; i < eManager.getEnemies().size(); i++)
			{
				if (eManager.getEnemies()[i]->id == BOSS1 || eManager.getEnemies()[i]->id == BOSS2 || eManager.getEnemies()[i]->id == BOSS3 || eManager.getEnemies()[i]->id == BOSS4)
					eManager.getEnemies()[i]->sprite.move(-4, 0);
			}
		}
		


		if(game.finalhours.getStatus() == Sound::Playing)
		{
			if(warningClock.getElapsedTime().asSeconds() > warningCooldown.asSeconds())
			{
				window.draw(skull);
				window.draw(warningText);
			}
			if (warningClock.getElapsedTime().asSeconds() > warningCooldown.asSeconds() + 1)
				warningClock.restart();
		}
		window.display();

	}
	return 0;
}