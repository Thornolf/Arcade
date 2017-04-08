/*
** APCharacter.cpp for cpp_arcade in /home/baudet_q/rendu/CPP/cpp_arcade/games/pacman
**
** Made by Quentin Baudet
** Login   <baudet_q@epitech.net>
**
** Started on  Wed Apr 05 18:53:52 2017 Quentin Baudet
** Last update Sat Apr 08 17:19:28 2017 Quentin Baudet
*/

#include "APCharacter.hpp"

APCharacter::APCharacter ()
{
  this->_name = "Fossae_t";
  this->_id = 1;
  this->_X = 10;
  this->_Y = 15;
  this->_score = 0;
  this->_pacgum = 0;
}

APCharacter::APCharacter (std::string newName, int newId, APCharacter::Hp newHp,
			  Game::State newState, Game::Direction newDirection, int newX, int newY)
{
  this->_name = newName;
  this->_id = newId;
  this->_hp = newHp;
  this->_state = newState;
  this->_direction = newDirection;
  this->_X = newX;
  this->_Y = newY;
  this->_score = 0;
  this->_pacgum = 0;
}

APCharacter::APCharacter (std::string newName, int newId, int newX, int newY)
{
  this->_name = newName;
  this->_hp = APCharacter::ALIVE;
  this->_state = Game::VULNERABLE;
  this->_direction = Game::UP;
  this->_id = newId;
  this->_X = newX;
  this->_Y = newY;
  this->_score = 0;
  this->_pacgum = 0;
}

APCharacter::~APCharacter () {}

/* ACTION */
BlockType 		APCharacter::getType(int newType) const
{
  if (newType == BlockType::WAY || newType == BlockType::VOID)
    return (BlockType::WAY);
  else
    return (BlockType::BLOCK);
}

bool 			APCharacter::isWalkable(int newBlock) const
{
  if (newBlock == BlockType::WAY || newBlock == BlockType::VOID)
    return (true);
  else
    return (false);
}

void 			APCharacter::movePlayerUp(int **map)
{
  int oldPosX = this->getX();
  int oldPosY = this->getY();
  if (this->isWalkable(map[oldPosY - 1][oldPosX]) == true)
  {
    this->setX(oldPosX);
    this->setY(oldPosY - 1);
  } else {
	  return ;
    // std::cout << "You cannot move to this position Y: " << oldPosY - 1 << " | X : " << oldPosX  << '\n';
  }
	  if (map[this->getY()][this->getX()] == 1) {
		  this->increaseScore(Score::PACGUM);
  		this->_pacgum -= 1;
	  }
}

void 			APCharacter::movePlayerRight(int **map) {
  int oldPosX = this->getX();
  int oldPosY = this->getY();

  if (this->isWalkable(map[oldPosY][oldPosX + 1]) == true)
  {
    this->setX(oldPosX + 1);
    this->setY(oldPosY);
  } else {
	  return ;
    // std::cout << "You cannot move to this position Y: " << oldPosY << " | X : " << oldPosX  + 1<< '\n';
  }
	  if (map[this->getY()][this->getX()] == 1) {
		  this->increaseScore(Score::PACGUM);
  		this->_pacgum -= 1;
	  }
}
void 			APCharacter::movePlayerLeft(int **map)
{
  int oldPosX = this->getX();
  int oldPosY = this->getY();

  if (this->isWalkable(map[oldPosY][oldPosX - 1]) == true)
  {
    this->setX(oldPosX - 1);
    this->setY(oldPosY);
  } else {
	  return ;
    // std::cout << "You cannot move to this position Y: " << oldPosY << " | X : " << oldPosX - 1 << '\n';
  }
	  if (map[this->getY()][this->getX()] == 1) {
		  this->increaseScore(Score::PACGUM);
  		this->_pacgum -= 1;
	  }
}

void 			APCharacter::movePlayerDown(int **map)
{
  int oldPosX = this->getX();
  int oldPosY = this->getY();

  if (this->isWalkable(map[oldPosY + 1][oldPosX]) == true)
  {
    this->setX(oldPosX);
    this->setY(oldPosY + 1);
  } else {
	  return ;
    // std::cout << "You cannot move to this position Y: " << oldPosY + 1 << " | X : " << oldPosX  << '\n';
  }
	  if (map[this->getY()][this->getX()] == 1) {
		  this->increaseScore(Score::PACGUM);
  		this->_pacgum -= 1;
	  }
}

void 		APCharacter::movePlayer(int **map, Game::Direction direction)
{
	std::map<Game::Direction, std::function<void(int **)>>	moveActions;
	moveActions[Game::UP] = std::bind(&APCharacter::movePlayerUp, this, std::placeholders::_1);
	moveActions[Game::DOWN] = std::bind(&APCharacter::movePlayerDown, this, std::placeholders::_1);
	moveActions[Game::LEFT] = std::bind(&APCharacter::movePlayerLeft, this, std::placeholders::_1);
	moveActions[Game::RIGHT] = std::bind(&APCharacter::movePlayerRight, this, std::placeholders::_1);
	if (map[this->getY()][this->getX()] == 1 || this->getId() == 1)
	{
		map[this->getY()][this->getX()] = -1;
	}
	moveActions[direction](map);
	if (this->getId() == 1){
		map[this->getY()][this->getX()] = 7;
	} else {
		map[this->getY()][this->getX()] = 10;
	}
}

/* SETTER */

void		APCharacter::setX(int newX)
{
  this->_X = newX;
}

void		APCharacter::setY(int newY)
{
  this->_Y = newY;
}

void		APCharacter::setState(Game::State newState)
{
  this->_state = newState;
}


void		APCharacter::setDirection(Game::Direction newDirection)
{
  this->_direction = newDirection;
}

/* GETTER */

int			APCharacter::getX(void) const
{
  return (this->_X);
}

int			APCharacter::getY(void) const
{
  return (this->_Y);
}

Game::State	APCharacter::getState(void) const
{
  return (this->_state);
}

Game::Direction	APCharacter::getDirection(void) const
{
  return (Game::UP);
}

/* Return l'ID */
int			APCharacter::getType(void) const
{
  return (0);
}

int 		APCharacter::getId(void) const
{
  return (this->_id);
}

bool		APCharacter::isAlive(void) const
{
  return (true);
}

void 	APCharacter::increaseScore(int newScore)
{
  int tmp = this->getScore() + newScore;
  this->setScore(tmp);
}

int 	APCharacter::getScore(void) const
{
  return (this->_score);
}

void	APCharacter::setScore(int newScore) {
	this->_score = newScore;

}

void 	APCharacter::setPacgum(int newPacgum) {
	this->_pacgum = newPacgum;
}

int 	APCharacter::getPacgum(void) const {
	return (this->_pacgum);
}

void		APCharacter::Dump(void) const {}
void		APCharacter::setLive(bool newLive) { (void)newLive; }
size_t		APCharacter::getSpeed(void) const { return (0); }
void		APCharacter::setSpeed(size_t newSpeed) { (void)newSpeed; }
void		APCharacter::movePlayer(std::map<int, std::map<int, int>>) {}
void 		APCharacter::startCore(Arcade::DLLoader<Graph::IGraph> &lib) { (void)lib; }
