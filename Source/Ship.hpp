#include <iostream>
#include <vector>
#include <string>
#include <random>

class Ship
{
	int posX, posY, size;
	bool vertical, destroyed;

public:
	Ship(int x, int y, int s, bool vert) : posX(x), posY(y), size(s), vertical(vert) { destroyed = false;}

	void incrementPosX()
	{
		if(posX<10) posX++;
	}

	void incrementPosY()
	{
		if(posY<10) posY++;
	}

	void decrementPosX()
	{
		if(posX>0) posX--;
	}

	void decrementPosY() 
	{
		if(posY>0) posY--;
	}

	int getPosX()
	{
		return posX;
	}
	int getPosY()
	{
		return posY;
	}
	int getSize()
	{
		return size;
	}
	int getVertical()
	{
		return vertical;
	}
};