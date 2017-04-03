/*
** NCursesMenu.hpp for cpp_arcade
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed Mar 29 15:07:47 2017 Guillaume CAUCHOIS
** Last update Wed Mar 29 15:07:47 2017 Guillaume CAUCHOIS
*/

#ifndef		_MENU__HPP_
# define	_MENU__HPP_

# include "IGraph.hpp"
# include "ArcadeException.hpp"
# include <vector>
# include <new>
# include <sstream>

# include <ncurses.h>
# include <menu.h>

namespace Graph
{
  class GraphicMenu : public IGraph
  {
    public:
      /* Canonical Methods */
      GraphicMenu();
      GraphicMenu(const GraphicMenu &);
      virtual ~GraphicMenu();
      GraphicMenu	&operator=(const GraphicMenu &);

      /* Unused pure methods */
      void	createMap();
      void	Game();
      void	SetSprite(int x, int y);
      void	UnsetSprite(int x, int y);
      void	Animation();

      /* Pure Methods */
      std::string	startMenu(const std::string &, const std::vector<std::string> &) const;

      /* Member Methods */
      void		SetLibraryChoices(const std::vector<std::string> &ListGraphics);
      std::string	MenuLoop(MENU*) const;
    public:
      std::vector<std::string>	_choicesLibraries;
  };
}

#endif		/* _NCRUSRS_MENU__HPP_ */