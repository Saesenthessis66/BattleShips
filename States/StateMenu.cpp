
#include "StateMenu.hpp"

void StateMenu::onEnter()
{
    State<States>::onEnter();
    system("cls");
    std::string message = "Hello from vsc";
    TextFunctions::setCursor(10,4);
    TextFunctions::printWithColor(message,TextColors::GREEN); 
    prompt->getPrompt();
    auto hej = prompt->retValues();
    TextFunctions::print(hej);
}

void StateMenu::onUpdate()
{
    State<States>::onUpdate();
}

void StateMenu::onExit()
{
    State<States>::onExit();
}
