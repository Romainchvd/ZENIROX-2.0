#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <map>

class TextureManager {
public:
	
	bool loadTexture(const std::string& name, const std::string& filename);

	sf::Texture& getTexture(const std::string& name);
	std::map<std::string, std::string> filePaths;
	std::unordered_map<std::string, sf::Texture> textures;
	TextureManager();

private:
	
	void addTexture(const std::string& name, const sf::Texture& texture);
};