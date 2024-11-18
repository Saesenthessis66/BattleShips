#ifndef MAP_HPP
#define MAP_HPP

#include"List.hpp"
#include"Ship.hpp"
#include <array>

class Map
{
	public:
	List <Ship> _ships;
	std::array<std::array<char, 10>, 10> _tiles;

	void initTiles();

	void writeShip(Ship& s);

	bool canPlaceShip(Ship& s);	
};

#endif