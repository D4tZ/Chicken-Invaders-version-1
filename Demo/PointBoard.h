#pragma once

#include<SFML/Graphics.hpp>

class PointBoard
{
private:
	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;

	sf::Font font;
	sf::Text pointsText;
	sf::Text levelBulletText;
	sf::Text livesText;

	void initSprite();
	void initFont();
	void initText();
	void initText(sf::Text& text, float pos_x, float pos_y);
public:
	PointBoard();
	virtual ~PointBoard();

	
	void updateText(int points, int levelBullet, int lives);
	void update(int points, int levelBullet, int lives);
	void render(sf::RenderTarget* target);

};

