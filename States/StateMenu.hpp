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
    std::unique_ptr<PromptSingleton> prompt = std::move(PromptSingleton::getInstance());

public:
    explicit StateMenu(FiniteStateMachine<States>& fsm)

    : State<States>(fsm, States::MENU, "MENU"){}

    void onEnter() override;
    void onUpdate() override;
    void onExit() override;
};

#endif