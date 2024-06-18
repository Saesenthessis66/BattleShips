//
// Created by lucja on 18.06.2024.
//

#ifndef STATEMENU_HPP
#define STATEMENU_HPP

#include <iostream>
#include <vector>
#include "StatesConf.hpp"
#include "../Engine/StateMachine.hpp"
#include "../Engine/State.hpp"
#include "../Source/PromptSingleton.hpp"
#include "..//Engine/TextFormatter.hpp"

class StateMenu : public State<States>{
    PromptSingleton* prompt = PromptSingleton::getInstance();
    std::vector<std::string> dict = {
        "continue",
        "new game"
};
public:
    explicit StateMenu(FiniteStateMachine<States>& fsm)

    : State<States>(fsm, States::MENU, "MENU"){}

    void onEnter() override;
    void onUpdate() override;
    void onExit() override;
};


#endif //STATEMENU_HPP
