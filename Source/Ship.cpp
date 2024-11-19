#include"Ship.hpp"

	void Ship::incrementPosX()
	{
		if(vertical && posX < 10 - size) posX++;
		if(!vertical && posX < 9) posX++;
	}

	void Ship::incrementPosY()
	{
		if(!vertical && posY < 10 - size) posY++;
		if(vertical && posY < 9) posY++;
	}

    void Ship::rotate()
	{
        if(vertical)
        {
            if(posY > 10 - size) posY = 10 - size;
        }
        else
        {
            if(posX > 10 - size) posX = 10 - size;
        }

		vertical =! vertical;
	}