/*
** ParserMap.cpp for pacman in /home/baudet_q/rendu/CPP/cpp_arcade/games/pacman
**
** Made by Quentin Baudet
** Login   <baudet_q@epitech.net>
**
** Started on  Mon Apr 03 17:45:24 2017 Quentin Baudet
** Last update Mon Apr 03 19:31:29 2017 Quentin Baudet
*/

#include "/home/baudet_q/rendu/CPP/cpp_arcade/inc/ParserMap.hpp"

/*Constructor */

ParserMap::ParserMap() {
	this->_mapHeight = 0;
	this->_mapLength = 0;
}

/* GETTER */

int		ParserMap::getMapHeight() {
	return(this->_mapHeight);
}

int		ParserMap::getMapLength() {
	return(this->_mapLength);

}

/* SETTER */

void 	ParserMap::setMapHeight(int newHeight) {
	this->_mapHeight = newHeight;
}

void 	ParserMap::setMapLength(int newLength) {
	this->_mapLength = newLength;
}

/* Get Info From Cnf */

void 	ParserMap::setMapIntel(std::string fileName) {

	/* Robin doit faire un regex pour vérifier que c'est bien un .cnf */

		int i = 0;
		std::string line;
	  	std::ifstream myfile (fileName);
		 if (myfile.is_open()) {
		    while (getline(myfile,line))
		    {
				if (i == 0)
					setMapHeight(std::stoi(line));
				else if (i == 1)
					setMapLength(std::stoi(line));
			  i++;
		    }
		    myfile.close();
		 } else {
		  	std::cerr << "Unable to open file" << std::endl;
	  }
}
/* Destructor */

ParserMap::~ParserMap() {}
