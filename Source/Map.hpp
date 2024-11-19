#ifndef MAP_HPP
#define MAP_HPP

#include"List.hpp"
#include"Ship.hpp"
#include <array>

class Map
{
	List <Ship> _ships;
	std::array<std::array<char, 10>, 10> _tiles;

	void initTiles();

public:

	Map(){initTiles();}

	void writeShip(Ship& s);

	bool canPlaceShip(Ship& s);	

	List <Ship> getShips() const {return _ships;}

	std::array<std::array<char, 10>, 10>& getTiles() {return _tiles;}
};

#endif