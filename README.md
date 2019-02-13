# Arcade

## How to use

[SFML](https://www.sfml-dev.org/tutorials/2.5/start-linux.php) must be installed in `/usr/local/` and [ncurses](http://tldp.org/HOWTO/NCURSES-Programming-HOWTO/) installed wherever you want.

To install Arcade, just use the command `make` and then launch the menu in **SFML** : `./arcade lib/lib_arcade_sfml.so` or in **ncurses** : `./arcade lib/lib_arcade_ncurses.so`

If it doesn't work in SFML, you will need to export the library path : `export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/SFML/lib`


## Contact

If you have any problem or question, contact us quentin.baudet@epitech, guillaume.cauchois@epitech.eu or robin.grattepanche@epitech.eu
