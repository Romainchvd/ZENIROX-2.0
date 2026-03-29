#include "textureManager.hpp"

bool TextureManager::loadTexture(const std::string& name, const std::string& filename)
{
		sf::Texture texture;
		if (!texture.loadFromFile(filename)) {
			return false;
		}
		textures[name] = texture;
		return true;
}

sf::Texture& TextureManager::getTexture(const std::string& name)
{
	return textures.at(name);
}

TextureManager::TextureManager()
{

	sf::Texture texture;
	std::vector<std::pair<std::string, std::string>> textureFiles = {
		{"palier1", "palier1.jpg"},
		{"palier2", "palier2.jpg"},
		{"palier3", "palier3.jpg"},
		{"palier4", "palier4.jpg"},
		{"star", "star.png"},
		{"enemy1", "enemy1.png"},
		{"enemy2", "enemy2.png"},
		{"enemy3", "enemy3.png"},
		{"Boss1", "Boss1.png"},
		{"Boss2", "Boss2.png"},
		{"Boss3", "Boss3.png"},
		{"Boss4", "Boss4.png"},
		{"mainmenu", "mainmenu.png", },
		{"close", "button/close.png"},
		{"confirm", "button/confirm.png"},
		{"editor", "button/editor.png"},
		{"cancel", "button/cancel.png"},
		{"data", "button/data.png"},
		{"easy", "button/easy.png"},
		{"hardcore", "button/hardcore.png"},
		{"normal", "button/normal.png"},
		{"quest", "button/quest.png"},
		{"resume", "button/resume.png"},
		{"settings", "button/settings.png"},
		{"buy", "button/buy.png"},
		{"yes", "button/yes.png"},
		{"no", "button/no.png"},
		{"back", "button/back.png"},
		{"shop", "button/shop.png"},
		{"continue", "button/continue.png"},
		{"reset", "button/reset.png"},
		{ "inventoryShip", "inventory/ship.png"},
		{"inventoryShip1", "inventory/ship1.png"},
		{"inventoryShip2", "inventory/ship2.png"},
		{"inventoryShip3", "inventory/ship3.png"},
		{"buyShip1", "shop/ship1.png"},
		{"buyShip2", "shop/ship2.png"},
		{"buyShip3", "shop/ship3.png" },
		{"menu", "button/menu.png"},
		{ "pause", "button/pause.png" },
		{"meteor", "meteor.png" },
		{  "heart", "heartboost.png" },
		{ "evilHeart", "heartnerf.png" },
		{ "battery", "cooldownboost.png" },
		{ "evilBattery", "cooldownnerf.png" },
		{ "shield", "shield.png" },
		{ "evilShield", "evilshield.png" },
		{"projectilePlayer", "projectiles/11.png" },
		{"projectileEnemy", "projectiles/14.png" },
		{"ship", "ship.png" },
		{"ship1", "ship1.png" },
		{"ship2", "ship2.png" },
		{"ship3", "ship3.png" },
	};
	for (const auto& pair : textureFiles) {
		if (!texture.loadFromFile(pair.second)) {
			throw std::runtime_error("Failed to load texture: " + pair.second);
		}
		addTexture(pair.first, texture);
	}


}

void TextureManager::addTexture(const std::string name, const sf::Texture texture)
{
	textures[name] = texture;
}
