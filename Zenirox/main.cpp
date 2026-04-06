#include "game.hpp"
using namespace std;
using namespace sf;





int main() {
	srand(time(NULL));
	

	Game game;

	





	
	


	
	
	

	SoundBuffer shot;
	if (!shot.loadFromFile("sounds/shot.ogg")) throw runtime_error("Son de tir non charge");
	vector<Sound> playerShot{ 10 };
	for (int i = 0; i < playerShot.size(); i++)
	{
		playerShot[i].setBuffer(shot);
	}
	


		//Chargement des niveaux
		game.run(playerShot, shot);







		//if(game.state == niveauEDIT && game.isFightingBoss == false)
		//{
		//	for (int i = 0; i < eManager.getEnemies().size(); i++)
		//	{
		//		if (eManager.getEnemies()[i]->id == BOSS1 || eManager.getEnemies()[i]->id == BOSS2 || eManager.getEnemies()[i]->id == BOSS3 || eManager.getEnemies()[i]->id == BOSS4)
		//			eManager.getEnemies()[i]->sprite.move(-4, 0);
		//	}
		//}
		


		
	

	
	return 0;
}