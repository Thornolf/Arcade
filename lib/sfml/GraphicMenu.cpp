/*
** GraphicMenu.cpp for cpp_arcade
**
** Made by Guillaume CAUCHOIS
** Login   <guillaume.cauchois@epitech.eu>
**
** Started on  Wed Mar 29 15:27:57 2017 Guillaume CAUCHOIS
** Last update Wed Mar 29 15:27:57 2017 Guillaume CAUCHOIS
*/

#include "GraphicMenu.hpp"

Graph::GraphicMenu::GraphicMenu() {}

Graph::GraphicMenu::GraphicMenu(const Graph::GraphicMenu &obj)
{
  (void)obj;
}

Graph::GraphicMenu::~GraphicMenu() {}

Graph::GraphicMenu	&Graph::GraphicMenu::operator=(const Graph::GraphicMenu &obj)
{
  (void)obj;
  return (*this);
}

void	Graph::GraphicMenu::SetLibraryChoices(const std::vector<std::string> &ListGraphics)
{
  this->_choicesLibraries = ListGraphics;
}

void	Graph::GraphicMenu::displayRulesMenu(void) const
{
  /**
   mvprintw(6, 3, "1- Select the graphic library to use for the display");
  mvprintw(7, 3, "2- Select the game to play");
  mvprintw(8, 3, "3- Play!");
  mvprintw(LINES - 2, 0, "Press ESC to exit");
   */
}

void	Graph::GraphicMenu::LaunchMenuSound(sf::Music &music, const std::string &filepath) const
{
  sf::Time	offset_music = sf::seconds(15.8f);

  if (!music.openFromFile(filepath))
    throw Arcade::ArcadeException("Cannot load the music : " + filepath);
  music.setLoop(true);
  music.play();
  music.setPlayingOffset(offset_music);
  music.setVolume(100);
}

sf::Sprite	Graph::GraphicMenu::createSpriteFromFile(sf::Texture &texture, const std::string &filepath, bool smooth) const
{
  sf::Sprite	sprite;

  if (!texture.loadFromFile(filepath))
    throw Arcade::ArcadeException("Cannot load the background");
  if (smooth)
    texture.setSmooth(true);
  sprite.setTexture(texture);
  return (sprite);
}

void		displayTitle(sf::RenderWindow &window, const std::string &title)
{
  sf::Font	font;
  sf::Text	text;

  if (!font.loadFromFile("assets/fonts/basic-regular.ttf"))
    throw Arcade::ArcadeException("Cannot load a font");
  text.setFont(font);
  text.setString(title);
  text.setCharacterSize(37);
  text.setPosition(715, 70);
  window.draw(text);
}

void		displayListItems(sf::RenderWindow &window, const std::vector<std::string> &listItems)
{
  sf::RectangleShape	rectangle(sf::Vector2f(500, 50));
  sf::Font		font;
  sf::Text		text;
  int			pos_y;

  if (!font.loadFromFile("assets/fonts/basic-regular.ttf"))
    throw Arcade::ArcadeException("Cannot load a font");
  text.setFont(font);
  pos_y = 200;
  rectangle.setFillColor(sf::Color(26, 188, 156));
  for (auto it = listItems.begin(); it != listItems.end(); ++it)
  {
    text.setString(*it);
    text.setPosition(720, pos_y + 5);
    rectangle.setPosition(700, pos_y);
    window.draw(rectangle);
    window.draw(text);
    pos_y += rectangle.getSize().y + 30;
  }
}

void		displayNextButton(sf::RenderWindow &window, const std::string &title_button)
{
  sf::RectangleShape	rectangle(sf::Vector2f(150, 50));
  sf::Font		font;
  sf::Text		text;

  if (!font.loadFromFile("assets/fonts/basic-regular.ttf"))
    throw Arcade::ArcadeException("Cannot load a font");
  text.setFont(font);
  rectangle.setFillColor(sf::Color(231, 76, 60));
  text.setString(title_button);
  text.setPosition(1090, 605);
  rectangle.setPosition(1050, 600);
  window.draw(rectangle);
  window.draw(text);
}

std::string	Graph::GraphicMenu::MenuLoop(sf::RenderWindow &window,
						sf::Sprite &sprite_bg,
						sf::Sprite &sprite_logo,
						const std::string &title,
						std::vector<std::string> listItems)
{
  sf::Event		event;
  int			alpha = 170;
  int			cursorSpeedFadeEffect = 0;
  int			cursorFadeEffect = 1;
  bool			selected = false;

  (void)listItems;
  (void)title;
  while (!selected)
  {
    sprite_logo.setColor(sf::Color(255, 255, 255, alpha)); // à moitié transparent
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
	window.close();
      else if (event.type == sf::Event::KeyPressed)
	selected = true;
    }
    window.clear();
    window.draw(sprite_bg);
    window.draw(sprite_logo);
    displayTitle(window, title);
    displayListItems(window, listItems);
    displayNextButton(window, "Next");
    window.display();
    if (cursorSpeedFadeEffect >= SFML_LOGO_FADE_EFFECT_SPEED)
    {
      cursorSpeedFadeEffect = 0;
      alpha += cursorFadeEffect;
      cursorFadeEffect = (alpha == 255) ? -1 : cursorFadeEffect;
      cursorFadeEffect = (alpha == 110) ? 1 : cursorFadeEffect;
    }
    cursorSpeedFadeEffect++;
  }
  return ("lib1");
}

std::pair<std::string, std::string>	Graph::GraphicMenu::startMenu(const std::vector<std::string> &listGraphics, const std::vector<std::string> &listGames)
{
  sf::RenderWindow	window(sf::VideoMode(1280, 720), "ARCADE - C++ 2020");
  sf::Sprite		sprite_bg;
  sf::Sprite		sprite_logo;
  sf::Texture		texture_bg;
  sf::Texture		texture_logo;
  sf::Music		music;
  std::string		library_graphic_chosen;
  std::string		library_games_chosen;

  try
  {
    sprite_bg	= this->createSpriteFromFile(texture_bg, "assets/img/bg_menu.png", false);
    sprite_logo	= this->createSpriteFromFile(texture_logo, "assets/img/logo.png", true);
  }
  catch (Arcade::ArcadeException &e)
  {
    throw e;
  }
  sprite_bg.setScale(0.6667, 0.6667);
  sprite_logo.setScale(0.8, 0.8);
  sprite_logo.setPosition(50, 100);
  this->LaunchMenuSound(music, "assets/music/menu.ogg");
  library_graphic_chosen = this->MenuLoop(window, sprite_bg, sprite_logo, "Please select a graphic library", listGraphics);
  if (!library_graphic_chosen.empty())
  library_games_chosen = this->MenuLoop(window, sprite_bg, sprite_logo, "Please select a game library", listGames);
  return (std::make_pair(library_graphic_chosen, library_games_chosen));
}

extern "C"
{
  Graph::IGraph	*getInstanceGraphicMenu()
  {
    return (new Graph::GraphicMenu());
  }
}

/* Unused pure methods */
void	Graph::GraphicMenu::createMap(void) {}
void	Graph::GraphicMenu::Game(void)  {}
void	Graph::GraphicMenu::SetSprite(int x, int y)  {(void)x; (void)y;}
void	Graph::GraphicMenu::UnsetSprite(int x, int y) {(void)x; (void)y;}
void	Graph::GraphicMenu::Animation() {}
void	Graph::GraphicMenu::displayMap(int **ptr){(void)ptr;};