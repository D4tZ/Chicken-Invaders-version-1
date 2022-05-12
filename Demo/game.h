#pragma once
#include "Player.h"
#include "ManyBullets.h"
#include "ManyChickens.h"
#include "Background.h"
#include "ManyEgg.h"
#include "Menu.h"
#include "Information.h"
#include "BulletPower.h"
#include "PointBoard.h"
#include "Boss.h"
#include "ManyEggBoss.h"

class Game
{
private:
	//Windows
	sf::RenderWindow* window;

	//Variables gameplay
	Player* player;
	ManyBullets* bullets;
	ManyChickens* chickens;
	sf::Clock eggClock;
	ManyEgg* eggs;
	BulletPower* bulletPower;
	Boss* boss;
	sf::Clock eggBossClock;
	ManyEggBoss* eggBosses;
	
	//Menu
	Menu* menu;
	Information* info;

	//Board
	PointBoard* board;

	//GUI
	sf::Font font;
	sf::Text pointText;
	sf::Sprite pointBoard;

	//World background game play
	Background* background;

	//Game end
	bool gameWin = false;
	bool gameLose = false;
	bool gameEnd = false;
	sf::Clock gameEndClock;

	//Sound
	sf::Music soundChickenHit1;
	sf::Music soundChickenHit2;
	sf::Music soundChickenHit3;

	//Private functions
	void initWindow();
	void initPlayer();
	void initGUI();
	void initSound();

public:
	//Constructors and Destructors
	Game();
	virtual ~Game();

	//Game run
	void run();
	void runGameplay();


public:
	//Game Play
	void updatePollEvents();
	void updateInputPlayer();

	//Combat
	void updateChickenKilled();
	void updatePlayerDead();
	void updateCombat();
	void updateAddEgg();
	void updatePower();
	void updateBossKilled();
	void checkGameEnd();

	//GUI
	void updateGUI();

	//Update
	void updateGamePlay();

	//Render
	void renderGUI();
	void renderGamePlay();

	//Game restart
	void restartGame();

};

