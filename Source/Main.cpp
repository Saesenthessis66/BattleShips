
#include "..//Engine/Engine.hpp"

#include <iostream>
#include <cstdlib>

std::unique_ptr<PromptSingleton> PromptSingleton::instancePtr = nullptr;

int main()
{
    auto p = std::move(PromptSingleton::getInstance());

	int x = 0;
	int xpp;
	while(1)
	{
		std::cout<<std::endl<<x;
		xpp = p->getPressedKey();
		if(xpp == cmd::KeyPressed::RIGHT) x++;
		if(xpp == cmd::KeyPressed::LEFT) x--;

		system("cls");
	}

    // Engine engine = Engine();

    // while(1)
    // {
    //     engine.run();
    // }

    return 0;
}
