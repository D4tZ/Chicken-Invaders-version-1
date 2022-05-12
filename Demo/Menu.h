#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>

class Menu
{
private:
	sf::Texture textureBackground;
	sf::Sprite spriteBackground;

	sf::Texture textureLogo;
	sf::Sprite spriteLogo;

	sf::Music backgroundMusic;
	sf::Music singleClick;
	sf::Music click;

public:
	bool menuClose;
	bool gameStart;
	bool showInformation;

private:
	//Text and font
	float sizeText;
	sf::Text startText;
	sf::Text informationText;
	sf::Text quitText;
	sf::Font font;

	//Mouse
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	void initText();
public:
	Menu();
	virtual ~Menu();
	
	void run(sf::RenderWindow* window);

	const bool isMenuClose() const;
	const bool isGameStart() const;
	const bool isShowInfo() const;

	const sf::FloatRect getStartBounds() const;
	const sf::FloatRect getInformationBounds() const;
	const sf::FloatRect getQuitBounds() const;


	void updateMouse(sf::RenderWindow* window);
	void updateGUI(sf::RenderWindow* window);
	void update(sf::RenderWindow* window);
	void renderGUI(sf::RenderWindow* window);
	void render(sf::RenderWindow* window);

	void restartGame();
};

