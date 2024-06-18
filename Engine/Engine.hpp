//
// Created by lucja on 14.06.2024.
//

#ifndef ENGINE_HPP
#define ENGINE_HPP

#include "..//Engine/StateMachine.hpp"
#include "..//States/StatesWrapper.hpp"

class Engine
{
    std::unique_ptr<FiniteStateMachine<States>> fsm = nullptr;
public:
    Engine();
    void run();
};

#endif //ENGINE_HPP