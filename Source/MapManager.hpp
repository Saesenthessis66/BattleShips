#ifndef MAPMANAGER_HPP
#define MAPMANAGER_HPP

#include "Map.hpp"
#include "List.hpp"
#include <memory>
#include <vector>

class MapManager
{
    Map _map;
    std::shared_ptr<std::array<std::array<char, 10>, 10>> _tiles;
    std::vector<int> _sizes;

    bool placeShip(Ship& s, int command);

    void showMap();

    void showMap(Ship& s);

public:

    MapManager()
    {
        _map = Map();
        _tiles = std::shared_ptr<std::array<std::array<char, 10>, 10>>(&_map.getTiles(), 
                [](std::array<std::array<char, 10>, 10>*) {});
        _sizes = std::vector<int>(6,0);
    }

    void getShipList();

    void placeShips();
};

#endif