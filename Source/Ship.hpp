#include <iostream>
#include <vector>
#include <string>
#include <random>

class Ship
{
	int posX, posY, size;
	bool vertical;

public:
	Ship(int x, int y, int s, bool vert) : posX(x), posY(y), size(s), vertical(vert) {}

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