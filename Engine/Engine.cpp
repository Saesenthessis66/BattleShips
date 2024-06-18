//
// Created by lucja on 14.06.2024.
//

#include "Engine.hpp"

Engine::Engine()
{
    fsm = std::make_unique<FiniteStateMachine<States>>();

    State<States>& menuState = fsm->Add<StateMenu>(States::MENU);

    fsm->SetCurrentState(States::MENU);
}

void Engine::run()
{
    fsm->OnUpdate();
}
