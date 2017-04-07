/*
** IGameInterface.hpp for cpp_arcade
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Mon Mar 13 16:42:14 2017 Thomas Fossaert
** Last update Fri Apr 07 11:49:06 2017 Quentin Baudet
*/

#ifndef		__IGRAPH_HPP__
# define	__IGRAPH_HPP__

# include <iostream>
# include <vector>
# include <ncurses.h>
# include <utility>

namespace Game
{
  class IGame;
}

namespace Graph
{
  class IGraph
  {
    public:
      virtual ~IGraph(void) {}
      virtual std::pair<std::string, std::string>	startMenu(const std::vector<std::string> &, const std::vector<std::string> &) = 0;
      virtual void					createMap(void) = 0;
      virtual void					Game(void) = 0;
      virtual void					SetSprite(int, int, Game::IGame *) = 0;
      virtual void					UnsetSprite(int, int, Game::IGame *) = 0;
      virtual void					Animation(void) = 0;
      virtual void					displayMap(int **) = 0;
      virtual void					displayMap(int **, int, int) = 0;
      virtual void					drawMap(int, int, char) = 0;
      virtual void					drawPlayer(std::vector<Game::IGame*>, char) = 0;
      virtual void					drawScore(int, int) = 0;
      virtual void					drawFood(int, int, char) = 0;
      virtual void					drawLoose(void) = 0;
      virtual int					recoverKey(void) = 0;
      virtual bool					checkSizeWindow(int x, int y) = 0;
  };
}

#endif		/*__IGRAPH_HPP__ */
