#include "Information.h"

void Information::initText()
{
	this->font.loadFromFile("Fonts/font1.ttf");

	this->initText(this->Atext, "A  - turn left", sf::Vector2f(200.f, 300.f));
	this->initText(this->Wtext, "w - turn up",	 sf::Vector2f(200.f, 400.f));
	this->initText(this->Dtext, "D  - turn right", sf::Vector2f(200.f, 500.f));
	this->initText(this->Stext, "S  - turn down", sf::Vector2f(200.f, 600.f));
	this->initText(this->backText, "Back", sf::Vector2f(10.f, 10.f));
}

void Information::initText(sf::Text& text, std::string word, sf::Vector2f pos)
{
	text.setCharacterSize(50.f);
	text.setFillColor(sf::Color::White);
	text.setFont(this->font);
	text.setString(word);
	text.setPosition(pos);
}

Information::Information()
{
	this->textureBackground.loadFromFile("Textures/background.png");
	this->spriteBackground.setTexture(this->textureBackground);
	this->spriteBackground.scale(16 / 12.f, 1.f);

	this->initText();

	this->open = true;

	this->singleClick.openFromFile("Sounds/single_click.wav");
	this->click.openFromFile("Sounds/click.wav");
}

Information::~Information()
{

}

const bool Information::isOpen() const
{
	return this->open;
}

const sf::FloatRect Information::getBackBounds() const
{
	return this->backText.getGlobalBounds();
}

void Information::run(sf::RenderWindow* window)
{
	this->update(window);
	this->render(window);
}

void Information::updateMouse(sf::RenderWindow* window)
{
	this->mousePosWindow = sf::Mouse::getPosition(*window);
	this->mousePosView = window->mapPixelToCoords(this->mousePosWindow);
}

void Information::update(sf::RenderWindow* window)
{
	this->updateMouse(window);

	if (this->backText.getGlobalBounds().contains(this->mousePosView)) 
	{
		if (this->backText.getFillColor() != sf::Color::Red)
		{
			this->backText.setFillColor(sf::Color::Red);
			this->singleClick.setPlayingOffset(sf::seconds(0.11));
			this->singleClick.play();
		}
	}
	else
		this->backText.setFillColor(sf::Color::White);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->backText.getGlobalBounds().contains(this->mousePosView))
	{
		this->open = false;
		this->click.setPlayingOffset(sf::seconds(0.2));
		this->click.play();
	}

}

void Information::render(sf::RenderWindow* window)
{
	window->clear();

	//render background
	window->draw(this->spriteBackground);

	//render text
	window->draw(this->Atext);
	window->draw(this->Wtext);
	window->draw(this->Dtext);
	window->draw(this->Stext);
	window->draw(this->backText);

	window->display();
}
