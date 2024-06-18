//
// Created by lucja on 18.06.2024.
//

#include "StateMenu.hpp"

void StateMenu::OnEnter()
{
    State<States>::OnEnter();
    std::cout<<"HELLO!";
}

void StateMenu::OnUpdate()
{
    State<States>::OnUpdate();
}

void StateMenu::OnExit()
{
    State<States>::OnExit();
}
