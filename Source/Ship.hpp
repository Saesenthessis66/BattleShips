#include <iostream>
#include <vector>
#include <string>
#include <random>

class Ship
{
	int posX, posY, size;
	bool vertical, destroyed;

public:
	Ship(int s, int x = 0, int y = 0, bool vert = false) : size(s), posX(x), posY(y), vertical(vert) { destroyed = false;}

	void rotate();

	void incrementPosX();

	void incrementPosY();

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
	bool isDestroyed()
	{
		return destroyed;
	}
};