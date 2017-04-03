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
# include	<vector>
# include	<ncurses.h>

namespace Graph
{
  class IGraph
  {
    public:
      virtual ~IGraph(void) {}
      virtual void					createMap() = 0;
      virtual void					Game() = 0;
      virtual void					SetSprite(int x, int y) = 0;
      virtual void					UnsetSprite(int x, int y) = 0;
      virtual void					Animation() = 0;
      virtual std::pair<std::string, std::string>	startMenu(const std::vector<std::string> &, const std::vector<std::string> &) const = 0;
  };
}

#endif		/*__IGRAPH_HPP__ */
