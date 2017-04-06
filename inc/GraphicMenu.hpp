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
# include <cstring>
# include <ncurses.h>
# include <menu.h>
# include <SFML/Audio.hpp>
# include <SFML/Graphics.hpp>

# define SFML_LOGO_FADE_EFFECT_SPEED (5)

struct		s_menu_item
{
  std::string		value;
  sf::RectangleShape	shape_menu;
};

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
      void	SetSprite(int, int, Game::IGame *);
      void	UnsetSprite(int, int, Game::IGame *);
      void	Animation();
      void	displayMap(int **);
      void	drawMap(int, int, char);
      void	drawPlayer(std::vector<Game::IGame*>, char);
      void	drawScore(int, int);
      void	drawFood(int, int, char);
      void	drawLoose(void);
      int	recoverKey(void);
      bool	checkSizeWindow(int x, int y);

      /* Pure Methods */
      std::pair<std::string, std::string>	startMenu(const std::vector<std::string> &, const std::vector<std::string> &);

      /* Member Methods */
      void		SetLibraryChoices(const std::vector<std::string> &ListGraphics);
      std::string	MenuLoop(const std::string &, WINDOW *, MENU*) const;
      std::string	MenuLoop(sf::RenderWindow &, sf::Sprite &, sf::Sprite &, const std::string &, std::vector<std::string>);
      void		displayAofARCADE(void) const;
      void		displayRofARCADE(void) const;
      void		displayCofARCADE(void) const;
      void		displayA_BIS_ofARCADE(void) const;
      void		displayDofARCADE(void) const;
      void		displayEofARCADE(void) const;
      void		displayArcadeTitle(void) const;
      void		displayRulesMenu(void) const;
      void		postMenuInWindow(WINDOW *, MENU *, const std::string &) const;
      void		LaunchMenuSound(sf::Music &, const std::string &) const;
      sf::Sprite	createSpriteFromFile(sf::Texture &, const std::string&, bool) const;

    public:
      typedef s_menu_item t_menu_item;
      std::vector<std::string>	_choicesLibraries;
  };
}

#endif		/* _NCRUSRS_MENU__HPP_ */