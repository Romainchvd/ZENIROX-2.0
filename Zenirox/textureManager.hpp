#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <vector>

class TextureManager {
public:
	
	bool loadTexture(const std::string& name, const std::string& filename);

	sf::Texture& getTexture(const std::string& name);

	std::unordered_map<std::string, sf::Texture> textures;
	TextureManager();

private:
	
	void addTexture(const std::string name, const sf::Texture texture);
};