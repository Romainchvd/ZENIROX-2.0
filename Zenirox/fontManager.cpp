#include "fontManager.hpp"

bool FontManager::loadFont(const std::string& name, const std::string& filename)
{
	sf::Font font;
	if (!font.loadFromFile(filename)) {
		return false;
	}
	fonts[name] = font;
	return true;
}

sf::Font& FontManager::getFont(const std::string& name)
{
	auto it = fonts.find(name);
	if (it != fonts.end()) {
		return it->second;
	}

	auto pathIt = filePaths.find(name);
	if (pathIt == filePaths.end()) {
		throw std::runtime_error("Font name not found in paths: " + name);
	}

	sf::Font font;
	if (!font.loadFromFile(pathIt->second)) {
		throw std::runtime_error("Failed to load font file: " + pathIt->second);
	}

	fonts[name] = std::move(font);
	return fonts[name];
}

FontManager::FontManager()
{
	filePaths = {
		{"Engcomica", "engcomica.otf"}
	};
}

void FontManager::addFont(const std::string& name, const sf::Font& font)
{
	fonts[name] = font;
}
