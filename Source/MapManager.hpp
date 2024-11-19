#ifndef MAPMANAGER_HPP
#define MAPMANAGER_HPP

#include "Map.hpp"

class MapManager
{
    public:
    Map _map;
    std::shared_ptr<std::array<std::array<char, 10>, 10>> _tiles;



    MapManager()
    {
        _map = Map();
        _tiles = std::shared_ptr<std::array<std::array<char, 10>, 10>>(&_map.getTiles(), 
                [](std::array<std::array<char, 10>, 10>*) {
});

    }

    void showMap();

    void showMap(Ship& s);

    bool placeShip(Ship& s, int command);
};

#endif