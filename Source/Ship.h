#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <random>

class Ship
{
	int posX, posY, size;
	int vertical;

	std::random_device rd;
public:
	Ship()
	{
		std::uniform_int_distribution<int> dist(0, 9);
		size = (dist(rd) % 4) + 2;
		std::cout << size << " tile ship. Enter position: " << std::endl << "x: ";
		std::cin >> posX;
		std::cout << std::endl << "y: ";
		std::cin >> posY;
		std::cout << std::endl << "Horizontal/Vertical (0/1): ";
		std::cin >> vertical;
	}
	Ship(int i)
	{
		std::uniform_int_distribution<int> dist(0, 9);
		size = (dist(rd) % 4) + 2;
		posX = dist(rd);
		posY = dist(rd);
		vertical = dist(rd) % 2;
	}
	~Ship() {}

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