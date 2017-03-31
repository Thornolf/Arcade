/*
** IGameInterface.hpp for cpp_arcade
**
** Made by Thomas Fossaert
** Login   <fossae_t@epitech.net>
**
** Started on  Mon Mar 13 16:42:14 2017 Thomas Fossaert
** Last update Thu Mar 23 16:44:05 2017 Thomas Fossaert
*/

#ifndef		__IGRAPH_HPP__
# define	__IGRAPH_HPP__

# include	<iostream>
# include	<map>
# include	<ncurses.h>

namespace Graph
{
  class IGraph
  {
    protected:
      std::map<int, std::map<int, int>> _gamemap;
    public:
      virtual ~IGraph(void) {}
      virtual void createMap() = 0;
      virtual void Game() = 0;
      virtual void SetSprite(int x, int y) = 0;
      virtual void UnsetSprite(int x, int y) = 0;
      virtual void Animation() = 0;
      virtual void startMenu() = 0;
  };
}

#endif		/*__IGRAPH_HPP__ */
