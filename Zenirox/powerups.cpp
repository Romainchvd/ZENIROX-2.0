#include "powerups.hpp"

Utilitary::Utilitary() {}
Utilitary::~Utilitary() { cout << "Un powerup de heal a ete detruit" << endl; }
void Utilitary::setUtilitary(TextureManager& textureManager) {
	switch (type)
	{
		case heart:
		sprite.setTexture(textureManager.getTexture("heart"));
		break;
		case evilHeart:
			sprite.setTexture(textureManager.getTexture("evilHeart"));
			break;
		case battery:
			sprite.setTexture(textureManager.getTexture("battery"));
			break;
		case evilBattery:
			sprite.setTexture(textureManager.getTexture("evilBattery"));
			break;
		case shield:
			sprite.setTexture(textureManager.getTexture("shield"));
			break;
		case evilShield:
			sprite.setTexture(textureManager.getTexture("evilShield"));
			break;
		default:
			break;
	}
}
void Utilitary::moveUtilitary()
{
	sprite.move(-velocity, 0);
}


UtilitaryManager::UtilitaryManager(TextureManager& manager) : textureManager(manager) {}


void UtilitaryManager::creerUtilitary(Powerup defType, float width, float height) {
	auto h = make_unique<Utilitary>();
	h->type = defType;
	h->setUtilitary(textureManager);
	h->sprite.setPosition(width, height);
	h->sprite.setScale(0.5,0.5);
	if (defType == shield || defType == evilShield)
		h->sprite.setScale(1, 1);
	utilitaryList.push_back(move(h));

}

vector<unique_ptr<Utilitary>>& UtilitaryManager::getUtilitaryList()
{
	return utilitaryList;
}
void UtilitaryManager::detruireUtilitary(unique_ptr<Utilitary>& h)
{
	auto it = find_if(utilitaryList.begin(), utilitaryList.end(), h.get());
	if (it != utilitaryList.end()) {
		utilitaryList.erase(it);
	}
}
void UtilitaryManager::checkUtilitary(unique_ptr<Utilitary>& h, Player& player, EnemyManager& eManager)
{
	cout << h->sprite.getPosition().x << endl;
	if (h->sprite.getGlobalBounds().intersects(player.sprite.getGlobalBounds()))
	{
		if(h->type == heart)
		{
			player.HP += (player.maxHP*0.5);
			if (player.HP >= player.maxHP)
				player.HP = player.maxHP;
			player.bonus.play();
		}
		if (h->type == evilHeart)
		{
			for (int i = 0; i < eManager.getEnemies().size(); i++)
			{
				eManager.getEnemies()[i]->HP += eManager.getEnemies()[i]->maxHP * 0.5;
				if (eManager.getEnemies()[i]->HP > eManager.getEnemies()[i]->maxHP)
					eManager.getEnemies()[i]->HP = eManager.getEnemies()[i]->maxHP;
			}
			player.malus.play();
		}
		if (h->type == battery)
		{
			player.canBeBoosted = true;
			player.boostClock.restart();
			player.bonus.play();
		}
		if (h->type == evilBattery)
		{
			for (int i = 0; i < eManager.getEnemies().size(); i++)
			{
				eManager.getEnemies()[i]->canBeBoosted = true;
				eManager.getEnemies()[i]->boostClock.restart();
			}
			player.malus.play();
		}
		if (h->type == shield)
		{
			player.shield = player.maxShield;
			player.bonus.play();
		}
		if (h->type == evilShield)
		{
			for (int i = 0; i < eManager.getEnemies().size(); i++)
			{
				if (eManager.getEnemies()[i]->id == ENNEMI1 || eManager.getEnemies()[i]->id == ENNEMI2 || eManager.getEnemies()[i]->id == ENNEMI3 || eManager.getEnemies()[i]->id == BOSS1 || eManager.getEnemies()[i]->id == BOSS2)
				{
					eManager.getEnemies()[i]->maxShield = eManager.getEnemies()[i]->maxHP * 0.5;
				}
				eManager.getEnemies()[i]->shield = eManager.getEnemies()[i]->maxShield;
			}
			player.malus.play();
		}
		detruireUtilitary(h);
	}
	if (h->sprite.getPosition().x < -500)
	{
		detruireUtilitary(h);
	}

}
