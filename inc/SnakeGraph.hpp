/*
** SnakeGraph.hpp for cpp_arcade in /home/caucho_g/workspace/epitech/cpp_arcade/inc/SnakeGraph.hpp
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Thu Apr 06 12:39:42 2017 Guillaume CAUCHOIS
** Last update Sat Apr 08 14:51:46 2017 Quentin Baudet
*/

#ifndef		_SNAKE_GRAPH__HPP_
# define	_SNAKE_GRAPH__HPP_

# include	<ncurses.h>
# include	<vector>
# include	<string>
# include	"SnakePart.hpp"
# include	"IGraph.hpp"
# include "ncurses/GraphicInit.hpp"

namespace Graph
{
  class SnakeGraph : Graph::IGraph
  {
    private:
      int			_key;
      Graph::GraphicInit	*_init;
    public:
      SnakeGraph ();
      virtual ~SnakeGraph ();
      SnakeGraph(const SnakeGraph &obj);
      SnakeGraph	&operator=(const SnakeGraph &obj);

      void	drawMap(int, int, char);
      void	drawPlayer(std::vector<Game::IGame*>, char);
      void	drawScore(int, int);
      void	drawFood(int, int, char);
      void	drawLoose(void);
      void	drawTitle(int y);
      int	recoverKey(void);
      bool	checkSizeWindow(int x, int y);

      /* Unused pure methods */
      void	createMap();
      void	Game();
      void	SetSprite(int, int, Game::IGame *);
      void	UnsetSprite(int, int, Game::IGame *);
      void	Animation();
      void	displayMap(int **);
      void 	displayMap(int **, int, int, int);
      std::pair<std::string, std::string>	startMenu(const std::vector<std::string> &, const std::vector<std::string> &);
  };
}

#endif		/* !_SNAKE_GRAPH__HPP_ */
