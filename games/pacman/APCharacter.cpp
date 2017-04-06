/*
** APCharacter.cpp for cpp_arcade in /home/baudet_q/rendu/CPP/cpp_arcade/games/pacman
**
** Made by Quentin Baudet
** Login   <baudet_q@epitech.net>
**
** Started on  Wed Apr 05 18:53:52 2017 Quentin Baudet
** Last update Thu Apr 06 11:40:41 2017 Quentin Baudet
*/

#include "APCharacter.hpp"

APCharacter::APCharacter () {
	this->_name = "Fossae_t";
	this->_id = 1;
	this->_hp = APCharacter::ALIVE;
	this->_state = Game::VULNERABLE;
	this->_direction = Game::UP;
	this->_X = 1;
	this->_Y = 1;
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

BlockType 		APCharacter::getType(int newType) const {
	if (newType == BlockType::WAY) {
		return (BlockType::WAY);
	} else {
		return (BlockType::BLOCK);
	}
}

bool 			APCharacter::isWalkable(int newBlock) const {
	if (newBlock == BlockType::WAY) {
		return (true);
	} else {
		return (false);
	}
}
void 			APCharacter::movePlayerUp(int **map) {
	int oldPosX = this->getX();
	int oldPosY = this->getY();
	if (this->isWalkable(map[oldPosY + 1][oldPosX]) == true) {
		this->setX(oldPosX);
		this->setY(oldPosY + 1);
	} else {
		std::cout << "You cannot move to this position Y: " << oldPosY + 1 << " | X : " << oldPosX  << '\n';
	}
	(void)map;
}
void 			APCharacter::movePlayerRight(int **map) {
	int oldPosX = this->getX();
	int oldPosY = this->getY();

	if (this->isWalkable(map[oldPosY][oldPosX + 1]) == true) {
		this->setX(oldPosX + 1);
		this->setY(oldPosY);
	} else {
		std::cout << "You cannot move to this position Y: " << oldPosY << " | X : " << oldPosX  + 1<< '\n';
	}
	(void)map;
}
void 			APCharacter::movePlayerLeft(int **map) {
	int oldPosX = this->getX();
	int oldPosY = this->getY();

	if (this->isWalkable(map[oldPosY][oldPosX - 1]) == true) {
		this->setX(oldPosX - 1);
		this->setY(oldPosY);
	} else {
		std::cout << "You cannot move to this position Y: " << oldPosY << " | X : " << oldPosX - 1 << '\n';
	}
	(void)map;
}
void 			APCharacter::movePlayerDown(int **map) {
	int oldPosX = this->getX();
	int oldPosY = this->getY();

	if (this->isWalkable(map[oldPosY - 1][oldPosX]) == true) {
		this->setX(oldPosX);
		this->setY(oldPosY - 1);
	} else {
		std::cout << "You cannot move to this position Y: " << oldPosY - 1 << " | X : " << oldPosX  << '\n';
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
