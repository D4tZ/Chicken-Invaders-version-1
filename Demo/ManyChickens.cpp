#include "ManyChickens.h"
//Private functions
void ManyChickens::initTexture()
{
	this->imageChicken.loadFromFile("Textures/chicken_red.png");
	this->imageChicken.createMaskFromColor(sf::Color(170, 170, 170));
	this->texture = new sf::Texture;
	this->texture->loadFromImage(this->imageChicken);
}

void ManyChickens::initChickens()
{
	this->distanceHeight = 40.0f;
	this->distanceWidth = 25.0f;

	for (int i = 0; i < this->CHICKEN_COLS; i++) {
		for (int j = 0; j < this->CHICKEN_ROWS; j++) {
			this->chickenList.push_back(new Chicken(this->texture, i * (75 + distanceWidth), j * (68 + distanceWidth), 1.0f));
		}
	}
}

void ManyChickens::initMovement()
{
	this->speedMovement = 5.0f;
}



//Constructors and Destructors
ManyChickens::ManyChickens()
{
	this->initTexture();
	this->initChickens();
	this->initMovement();
}

ManyChickens::~ManyChickens()
{
	for (auto* chicken : this->chickenList)
	{
		delete chicken;
	}

	delete this->texture;
}

const int ManyChickens::chickenDead() const
{
	return 60 - this->chickenList.size();
}

//Functions
void ManyChickens::updateChicken()
{
	for (auto* chicken : this->chickenList)
	{
		chicken->update();
	}
}

void ManyChickens::updateMovement()
{

}



void ManyChickens::update()
{
	this->updateChicken();
}

void ManyChickens::render(sf::RenderTarget* target)
{
	for (auto* chicken : this->chickenList)
	{
		chicken->render(target);
	}
}
