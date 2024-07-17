//
// Created by lucja on 18.06.2024.
//

#include "StateMenu.hpp"

void StateMenu::onEnter()
{
    State<States>::onEnter();
    system("cls");
    std::string message = "Hello from vsc";
    TextFunctions::changeTextColor(TextColors::ROSE);
    TextFunctions::setCursor(10,4);
    TextFunctions::print(message); 
}

void StateMenu::onUpdate()
{
    State<States>::onUpdate();
}

void StateMenu::onExit()
{
    State<States>::onExit();
}
