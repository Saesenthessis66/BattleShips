
#include "..//Engine/Engine.hpp"

#include <iostream>
#include <cstdlib>

std::unique_ptr<PromptSingleton> PromptSingleton::instancePtr = nullptr;
#include"MapManager.hpp"
int main()
{
	MapManager m;
	Ship s(3);
	Ship ss(4);
    auto p = std::move(PromptSingleton::getInstance());

	int x = 0;
	int xpp = 0;
	m.showMap(s);
	do
	{	
		xpp = p->getPressedKey();
		system("cls");
	} while(!m.placeShip(s,xpp));

		m.showMap();
	do
	{	
		xpp = p->getPressedKey();
		system("cls");
	} while(!m.placeShip(ss,xpp));
	m.showMap();
    // Engine engine = Engine();

    // while(1)
    // {
    //     engine.run();
    // }

    return 0;
}
