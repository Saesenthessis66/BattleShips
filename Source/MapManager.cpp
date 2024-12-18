#include "MapManager.hpp"
#include "../Engine/TextFormatter.hpp"
#include "../Engine/Texts.hpp"
#include "PromptSingleton.hpp"

bool MapManager::placeShip(Ship& s, int command)
{
    showMap(s);

   switch(command)
   {
        case cmd::KeyPressed::RIGHT:
        s.incrementPosY();
        break;

        case cmd::KeyPressed::LEFT:
        s.decrementPosY();
        break;

        case cmd::KeyPressed::UP:
        s.decrementPosX();
        break;

        case cmd::KeyPressed::DOWN:
        s.incrementPosX();
        break;

        case cmd::KeyPressed::ROTATE:
        s.rotate();
        break;

        case cmd::KeyPressed::ACCEPT:
        if(_map.canPlaceShip(s))
        { 
            _map.writeShip(s);
            return true;
        }
        break;
   }
    return false;
}

void MapManager::showMap()
{
    for( auto& row : *_tiles)
    {
        for( char c : row)
        {
            std::cout<<c<<" ";
        }
        std::cout<<std::endl;
    }
}

void MapManager::showMap(Ship& s)
{
    if(s.getVertical())
    {
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                if((i >= s.getPosX() && i < s.getPosX() + s.getSize()) &&(j == s.getPosY()))
                {
                    if(_map.canPlaceShip(s))  TextFunctions::printWithColor(Board::ship_indicator, TextColors::GREEN);
                    else  TextFunctions::printWithColor(Board::ship_indicator, TextColors::RED);
                   
                }
                else std::cout<<(*_tiles)[i][j]<<" ";
            }
            std::cout<<std::endl;
        }
    }
    else
    {
        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < 10; j++)
            {
                if((j >= s.getPosY() && j < s.getPosY() + s.getSize()) &&(i == s.getPosX()))
                {
                    if(_map.canPlaceShip(s))  TextFunctions::printWithColor(Board::ship_indicator, TextColors::GREEN);
                    else  TextFunctions::printWithColor(Board::ship_indicator, TextColors::RED);
                }
                else std::cout<<(*_tiles)[i][j]<<" ";
            }
            std::cout<<std::endl;
        }
    }
}

void MapManager::getShipList()
{
    _sizes[1] = 3;
    _sizes[2] = 2;
    _sizes[3] = 1;
}

void MapManager::placeShips()
{
    
    auto p = std::move(PromptSingleton::getInstance());
    for(int i = 1; i < 6; i++)
    {
        for(int j = _sizes[i]; j > 0; j--)
        {
            int command = 0;
            Ship s(i);
            showMap(s);	
            do
            {
        	    command = p->getPressedKey();
        	    system("cls");
            } while(!placeShip(s,command));
        }
    }
}