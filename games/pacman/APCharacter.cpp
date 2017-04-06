/*
** APCharacter.cpp for cpp_arcade in /home/baudet_q/rendu/CPP/cpp_arcade/games/pacman
**
** Made by Quentin Baudet
** Login   <baudet_q@epitech.net>
**
** Started on  Wed Apr 05 18:53:52 2017 Quentin Baudet
** Last update Thu Apr 06 10:56:50 2017 Quentin Baudet
*/

#include "APCharacter.hpp"
#include "MapGame.hpp"
APCharacter::APCharacter () {
	this->_name = "Fossae_t";
	this->_id = 1;
	this->_hp = APCharacter::ALIVE;
	this->_state = Game::VULNERABLE;
	this->_direction = Game::UP;
	this->_X = 0;
	this->_Y = 0;
}

APCharacter::APCharacter (	std::string newName,
							int newId,
							APCharacter::Hp newHp,
							Game::State newState,
							Game::Direction newDirection,
							int newX,
							int newY) {
	this->_name = newName;
	this->_id = newId;
	this->_hp = newHp;
	this->_state = newState;
	this->_direction = newDirection;
	this->_X = newX;
	this->_Y = newY;
}

APCharacter::~APCharacter () {}

/* ACTION */

void 			APCharacter::movePlayerUp(int **map) {
	int oldPosX = this->getX();
	int oldPosY = this->getY();
	if (map[oldPosY + 1][oldPosX]) {
	}
	(void)map;
}
void 			APCharacter::movePlayerRight(int **map) {
	int oldPosX = this->getX();
	int oldPosY = this->getY();

	if (map[oldPosY][oldPosX + 1]) {
	}
	(void)map;
}
void 			APCharacter::movePlayerLeft(int **map) {
	int oldPosX = this->getX();
	int oldPosY = this->getY();

	if (map[oldPosY][oldPosX -1]) {
	}
	(void)map;
}
void 			APCharacter::movePlayerDown(int **map) {
	int oldPosX = this->getX();
	int oldPosY = this->getY();

	if (map[oldPosY - 1][oldPosX]) {
	}
	(void)map;
}

void 		APCharacter::movePlayer(int **map) {
	/* Pointeur sur fonction */
	/* Faire 4 func pour les 4 directions qui check si il peu aller là,
 	si il peut alors il faut changer la position du player */
	(void)map;
}

/* SETTER */

void		APCharacter::setX(int newX) {
	this->_X = newX;
}

void		APCharacter::setY(int newY) {
	this->_Y = newY;
}

void		APCharacter::setState(Game::State newState){
	this->_state = newState;
}


void		APCharacter::setDirection(Game::Direction newDirection) {
	this->_direction = newDirection;
}

/* GETTER */

int			APCharacter::getX(void) const {
	return (this->_X);
}

int			APCharacter::getY(void) const {
	return (this->_Y);
}

Game::State	APCharacter::getState(void) const {
	return (this->_state);
}

Game::Direction	APCharacter::getDirection(void) const{
	return (Game::UP);
}

/* Return l'ID */
int			APCharacter::getType(void) const{
	return (0);
}

bool		APCharacter::isAlive(void) const{
	return (true);
}

void		APCharacter::Dump(void) const{}

void		APCharacter::setScore(int){}
int			APCharacter::getScore(void) const{ return (0); }
size_t		APCharacter::getSpeed(void) const{ return (0); }
void		APCharacter::movePlayer(std::map<int, std::map<int, int>>){}
void		APCharacter::setSpeed(size_t newSpeed){ (void)newSpeed;}
void 	APCharacter::startCore(Arcade::DLLoader<Graph::IGraph> &lib) { (void)lib; }
void		APCharacter::setLive(bool newLive){	(void)newLive; }
