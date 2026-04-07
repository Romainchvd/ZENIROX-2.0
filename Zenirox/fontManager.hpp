#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <map>
#include <memory>

class FontManager {
public:

	bool loadFont(const std::string& name, const std::string& filename);

	sf::Font& getFont(const std::string& name);
	std::map<std::string, std::string> filePaths;
	std::unordered_map<std::string, std::unique_ptr<sf::Font>> fonts;
	FontManager();

private:

	void addFont(const std::string& name, const sf::Font& font);
};