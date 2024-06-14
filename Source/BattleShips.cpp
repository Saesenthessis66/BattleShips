#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
#include <fstream>
#include <iterator>

#include "Ship.h"

template <class T>
class ListElement
{
public:
	ListElement* Next;
	ListElement* Previous;
	T* Data;


	ListElement(T* value, ListElement* previous = nullptr, ListElement* next = nullptr)
		:Data(value), Previous(previous), Next(next) {}
};

template <class T>
class List
{
	ListElement<T>* Head;
	int size = 0;

public:
	List() :Head(nullptr) {}
	~List() { clear(); }

	ListElement<T>* getHead() { return Head; }

	void clear() {
		ListElement<T>* Current = Head;
		while (Current != nullptr)
		{
			ListElement<T>* temp = Current->Next;
			delete Current->Data;
			delete Current;
			Current = temp;
		}

		Head = nullptr;
	}
	void pushBack(T* value) {
		if (Head == nullptr)
		{
			Head = new ListElement<T>(value);
			size++;
		}
		else
		{
			ListElement<T>* Current = Head;
			while (Current->Next != nullptr)
			{
				Current = Current->Next;
			}

			ListElement<T>* Temp = new ListElement<T>(value, Current);
			Current->Next = Temp;
			size++;
		}
	}
	void popBack() {
		if (Head == nullptr)
		{
			throw ("Empty list cannot be poped");
		}

		if (Head->Next == nullptr)
		{
			delete Head;
			Head = nullptr;
			size--;
		}
		else
		{
			ListElement<T>* Current = Head;
			while (Current->Next != nullptr)
			{
				Current = Current->Next;
			}
			Current->Previous->Next = nullptr;
			delete Current;
			size--;
		}
	}
	int Size() { return size; };

};

class Map
{
	int maxShips;
	List <Ship> ships;
	std::vector<std::vector<std::string>> tiles;
	bool destroyed;
	
	std::random_device rd;
public:
	Map(int mShip,bool fill)
	{
		destroyed = false;
		maxShips = mShip;
		std::vector<std::string> row;
		for (int i = 0; i < 10; i++)
		{
			row.push_back(".");
		}
		for (int i = 0; i < 10; i++)
		{
			tiles.push_back(row);
		}
		
		if (fill)
		{
			autoFill();
		}
		else
		{
			Display();
			Fill(); 
		}
	}
	Map(const Map& map)
	{
		this->tiles = map.tiles;
		std::unique_ptr <int> uptr( new int );
	}
	Map(int mShip, bool fill, bool load) {
		destroyed = false;
		maxShips = mShip;
		std::vector<std::string> row;
		for (int i = 0; i < 10; i++)
		{
			row.push_back(".");
		}
		for (int i = 0; i < 10; i++)
		{
			tiles.push_back(row);
		}
		this->load("save.txt"); }
	~Map() {}

	friend std::ostream& operator<<(std::ostream& os, const Map& map)
	{
		os << std::endl << "   0 1 2 3 4 5 6 7 8 9 y" << std::endl;
		for (int i = 0; i < 10; i++)
		{
			os << " " << i << " ";
			for (int j = 0; j < 10; j++)
			{
				os << map.tiles[i][j] << " ";
			}
			os << "" << std::endl;
		}
		os << " x" << std::endl << "-----------------------" << std::endl;
		return os;
	}



	Map& operator=(const Map& m)
	{
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				tiles[i][j] = m.tiles[i][j];
			}
		}
	}

	void Display()
	{
		std::cout << std::endl << "   0 1 2 3 4 5 6 7 8 9 y" << std::endl;
		for (int i = 0; i < 10; i++)
		{
			std::cout << " " << i << " ";
			for (int j = 0; j < 10; j++)
			{
				std::cout << tiles[i][j] << " ";
			}
			std::cout <<""<< std::endl;
		}
		std::cout <<" x"<< std::endl << "-----------------------" << std::endl;
	}
	void displayBot()
	{
		std::cout << std::endl << "   0 1 2 3 4 5 6 7 8 9 y" << std::endl;
		for (int i = 0; i < 10; i++)
		{
			std::cout << " " << i << " ";
			for (int j = 0; j < 10; j++)
			{
				if (tiles[i][j] == "S")
				{
					std::cout << ". ";
				}
				else 
				{
					std::cout << tiles[i][j] << " ";
				}
			}
			std::cout << "" << std::endl;
		}
		std::cout << " x" << std::endl << "-----------------------" << std::endl;
	}

	void update(Ship* s)
	{
		if (s->getVertical())
		{
			for (int i = 0; i < s->getSize(); i++)
			{
				tiles[s->getPosX() + i][s->getPosY()] = "S";
			}
		}
		else
		{		
			for (int i = 0; i < s->getSize(); i++)
			{
				tiles[s->getPosX()][s->getPosY() + i] = "S";
			}
		}
	}

	void update(int x, int y)
	{
		if (tiles[x][y] == ".")
		{
			tiles[x][y] = "O";
		}
		else if (tiles[x][y] == "S")
		{
			tiles[x][y] = "X";
		}	
		int shipTile = 0;
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (tiles[i][j] == "S")
				{
					shipTile++;
				}
			}
		}

		if (shipTile == 0)
		{
			destroyed = true;
		}
	}

	bool checkShip(Ship* ship)
	{
		if (ship->getPosX() >= 0 && ship->getPosX() <= 9 && ship->getPosY() >= 0 && ship->getPosX() <= 9)
		{
			if (ship->getVertical())
			{
				return checkVship(ship);
			}
			else
			{
				return checkHship(ship);
			}
		}
		else return false;
	}

	bool checkVship(Ship* ship)
	{
		if (ship->getPosX() + ship->getSize() < 9)
		{
			if (ship->getPosX() == 0)
			{
				if (tiles[ship->getPosX() + ship->getSize()][ship->getPosY()] == ".")
				{
					for (int i = 0; i < ship->getSize(); i++)
					{
						if (ship->getPosY() == 0)
						{
							if (tiles[ship->getPosX() + i][ship->getPosY() + 1] == ".")
							{

							}
							else return false;
						}
						else if (ship->getPosY() == 9)
						{
							if (tiles[ship->getPosX() + i][ship->getPosY() - 1] == "." )
							{

							}
							else return false;
						}
						else
						{
							if (tiles[ship->getPosX() + i][ship->getPosY() - 1] == "." && tiles[ship->getPosX() + i][ship->getPosY() + 1] == ".")
							{

							}
							else return false;
						}
					}
					return true;
				}
				else return false;
			}
			else
			{
				if (tiles[ship->getPosX() - 1][ship->getPosY()] == "." && tiles[ship->getPosX() + ship->getSize()][ship->getPosY()] == ".")
				{
					for (int i = 0; i < ship->getSize(); i++)
					{
						if (ship->getPosY() == 0)
						{
							if (tiles[ship->getPosX() + i][ship->getPosY() + 1] == ".")
							{

							}
							else return false;
						}
						else if (ship->getPosY() == 9)
						{
							if (tiles[ship->getPosX() + i][ship->getPosY() - 1] == ".")
							{

							}
							else return false;
						}
						else
						{
							if (tiles[ship->getPosX() + i][ship->getPosY() - 1] == "." && tiles[ship->getPosX() + i][ship->getPosY() + 1] == ".")
							{

							}
							else return false;
						}
					}
					return true;
				}
				else return false;
			}
		}
		else return false;
	}
	bool checkHship(Ship* ship)
	{
		if (ship->getPosY() + ship->getSize() < 9)
		{
			if (ship->getPosY() == 0)
			{
				if (tiles[ship->getPosX()][ship->getPosY() + ship->getSize()] == ".")
				{
					for (int i = 0; i < ship->getSize(); i++)
					{
						if (ship->getPosX() == 0)
						{
							if (tiles[ship->getPosX() + 1][ship->getPosY() + i] == ".")
							{

							}
							else return false;
						}
						else if (ship->getPosX() == 9)
						{
							if (tiles[ship->getPosX() - 1][ship->getPosY() + i] == "." )
							{

							}
							else return false;
						}
						else
						{
							if (tiles[ship->getPosX() - 1][ship->getPosY() + i] == "." && tiles[ship->getPosX() + 1][ship->getPosY() + i] == ".")
							{

							}
							else return false;
						}
					}
					return true;
				}
				else return false;
			}
			else
			{
				if (tiles[ship->getPosX()][ship->getPosY() - 1] == "." && tiles[ship->getPosX()][ship->getPosY() + ship->getSize()] == ".")
				{
					for (int i = 0; i < ship->getSize(); i++)
					{
						if (tiles[ship->getPosX() - 1][ship->getPosY() + i] == "." && tiles[ship->getPosX() + 1][ship->getPosY() + i] == ".")
						{

						}
						else return false;
					}
					return true;
				}
				else return false;
			}
		}
		else return false;
	}
	bool isDestroyed()
	{
		return destroyed;
	}

	void Fill()
	{
		while (ships.Size() < maxShips)
		{
			Ship* ship = new Ship();
			if (checkShip(ship))
			{
				ships.pushBack(ship);
				system("cls");
				this->update(ship);
				this->Display();
			}
			else std::cout << "Incorrect place. Try again." << std::endl;
		}
	}

	void autoFill()
	{
		while (ships.Size() < maxShips)
		{
			Ship* ship = new Ship(1);
			if (checkShip(ship))
			{
				ships.pushBack(ship);
				this->update(ship);
			}
		}
	}

	std::string getTile(int x, int y)
	{
		return tiles[x][y];
	}

	void shoot()
	{
		int x, y;
		std::cout << "Shoot to:\nx: ";
		std::cin >> x;
		std::cout << "y: ";
		std::cin >> y;

		update(x, y);
	}
	void autoShoot()
	{
		std::uniform_int_distribution<int> dist(0, 9);
		int x, y;
		x = dist(rd);
		y = dist(rd);
		update(x, y);
	}

	void save()
	{
		std::ofstream fs("save.txt");
		for (int i = 0; i < 9; i++)
		{
			std::copy(tiles[i].begin(), tiles[i].end(), std::ostream_iterator<std::string>(fs, " "));
			fs << std::endl;
		}
		fs.close();
	}
	void load(std::string f)
	{
		std::string number;
		std::fstream file;
		file.open(f);
		if (file.is_open())
		{
			int j = 0;
			while (std::getline(file, number))
			{
				number.erase(std::remove_if(number.begin(), number.end(), ::isspace), number.end());
				for (int i = 0; i < number.length(); i++)
				{
					tiles[j][i] = number[i];
				}
				j++;

			}
		}
	}

};

class Game
{
	int shipAmount;
	Map* playerMap;
	Map* botMap;
public:
	Game(int x)
	{
		shipAmount = x;
		playerMap = new Map(shipAmount, false);
		botMap = new Map(shipAmount, true);
		system("cls");
		save();
	}
	void run()
	{
		while(!playerMap->isDestroyed() && !botMap->isDestroyed())
		{
			botMap->Display();
			playerMap->Display();
			botMap->displayBot();
			botMap->shoot();
			playerMap->autoShoot();
			system("cls");
			if (playerMap->isDestroyed())
			{
				playerMap->Display();
				botMap->displayBot();
				std::cout << "You lost.";
				break;
			}
			if (botMap->isDestroyed())
			{
				playerMap->Display();
				botMap->displayBot();
				std::cout << "You won.";
				break;
			}
		}
	}
	void save()
	{
		playerMap->save();
	}
	void load()
	{
		playerMap->load("save.txt");
	}
};

