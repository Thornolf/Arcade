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
# include <utility>
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
      std::pair<std::string, std::string>	startMenu(const std::vector<std::string> &, const std::vector<std::string> &) const;

      /* Member Methods */
      void		SetLibraryChoices(const std::vector<std::string> &ListGraphics);
      void		initScreen() const;
      std::string	MenuLoop(const std::string &, WINDOW *, MENU*) const;
      void		displayAofARCADE(void) const;
      void		displayRofARCADE(void) const;
      void		displayCofARCADE(void) const;
      void		displayA_BIS_ofARCADE(void) const;
      void		displayDofARCADE(void) const;
      void		displayEofARCADE(void) const;
      void		displayArcadeTitle(void) const;
      void		displayRulesMenu(void) const;
      void		postMenuInWindow(WINDOW *, MENU *, const std::string &) const;
    public:
      std::vector<std::string>	_choicesLibraries;
  };
}

#endif		/* _NCRUSRS_MENU__HPP_ */