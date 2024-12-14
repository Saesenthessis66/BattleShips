
#include "..//Engine/Engine.hpp"

#include <iostream>
#include <cstdlib>

std::unique_ptr<PromptSingleton> PromptSingleton::instancePtr = nullptr;
#include"MapManager.hpp"
int main()
{
	MapManager m;
	m.getShipList();
	m.placeShips();

    // Engine engine = Engine();

    // while(1)
    // {
    //     engine.run();
    // }

    return 0;
}
