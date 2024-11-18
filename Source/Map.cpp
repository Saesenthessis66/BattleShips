#include"Map.hpp"

	void Map::initTiles()
	{
		for(auto& row : _tiles)
		{
			row.fill('.');
		}
	}

	void Map::writeShip(Ship& s)
	{
		int xPos = s.getPosX();
		int yPos = s.getPosY();
		int size = s.getSize();
		if(s.getVertical())
		{			
			for(int i = 0; i < size; i++)
			{
				_tiles[xPos+i][yPos] = 'S';
			}			
		}
		else
		{
			for(int i = 0; i < size; i++)
			{
				_tiles[xPos][yPos+i] = 'S';
			}	
		}
		_ships.pushBack(s);
	}

	bool Map::canPlaceShip(Ship& s)
	{
		int xPos = s.getPosX();
		int yPos = s.getPosY();
		int size = s.getSize();
		if(s.getVertical())
		{			
			for(int i = 0; i < size; i++)
			{
				if(_tiles[xPos+i][yPos] == 'S') return false;

				if(yPos<10)
				{
					if(_tiles[xPos+i][yPos+1] != '.' ) return false;
				}

				if(yPos>0)
				{
					if(_tiles[xPos+i][yPos-1] != '.' ) return false;
				}
			}

			if(xPos>0)
			{
				if(_tiles[xPos-1][yPos] != '.' ) return false;
			}

			if(xPos<10)
			{
				if (_tiles[xPos+size][yPos] != '.' ) return false;
			}
		}
		else
		{
			for(int i = 0; i < size; i++)
			{
				if(_tiles[xPos][yPos+i] == 'S') return false;

				if(xPos<10)
				{
					if(_tiles[xPos+1][yPos+i] != '.' ) return false;
				}

				if(xPos>0)
				{
					if(_tiles[xPos-1][yPos+i] != '.' ) return false;
				}
			}

			if(yPos>0)
			{
				if(_tiles[xPos][yPos-1] != '.' ) return false;
			}

			if(yPos<10)
			{
				if (_tiles[xPos][yPos+size] != '.' ) return false;
			}
		}

		return true;
	}