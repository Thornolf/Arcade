/*
** GraphicInit.hpp for cpp_arcade
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed Apr 05 16:41:34 2017 Guillaume CAUCHOIS
** Last update Sat Apr 08 14:51:09 2017 Quentin Baudet
*/

#ifndef		_GRAPHIC_INIT__HPP_
# define	_GRAPHIC_INIT__HPP_

# include "IGraph.hpp"
# include "ArcadeException.hpp"
# include <ncurses.h>

namespace Graph
{
  class GraphicInit : public Graph::IGraph
  {
    public:
      /* Canonical form */
      GraphicInit();
      GraphicInit(const GraphicInit &);
      virtual ~GraphicInit();
      GraphicInit	&operator=(const GraphicInit &);

      /* Unused pure methods */
      std::pair<std::string, std::string>	startMenu(const std::vector<std::string> &, const std::vector<std::string> &);
      void	createMap();
      void	Game();
      void	SetSprite(int, int, Game::IGame *);
      void	UnsetSprite(int, int, Game::IGame *);
      void	Animation();
      void	displayMap(int **);
      void 	displayMap(int **, int, int, int);
      void	drawMap(int, int, char);
      void	drawPlayer(std::vector<Game::IGame*>, char);
      void	drawScore(int, int);
      void	drawFood(int, int, char);
      void	drawLoose(void);
      int	recoverKey(void);
      bool	checkSizeWindow(int x, int y);
  };
}

#endif		/* !_GRAPHIC_INIT__HPP_ */
