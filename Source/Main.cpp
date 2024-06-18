//
// Created by lucja on 14.06.2024.
//
#include "..//Engine/Engine.hpp"


PromptSingleton* PromptSingleton::instancePtr = nullptr;

int main()
{
    Engine engine = Engine();

    while(1)
    {
        engine.run();
    }

    return 0;
}
