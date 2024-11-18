#include "PromptSingleton.hpp"
#include "Globals.hpp"
#include <utility>

std::string getMatch(std::string &text, std::vector<std::string> dict) {
    bool nEqual = false;
    int len = dict.size();
    for (int i = 0; i < len; i++) {
        int size = (text.size()>dict[i].size() ? dict[i].size() : text.size());
        nEqual = false;
        for(int j = 0; j < size; j++)
        {
            if(text[j] != dict[i][j])
            {
                nEqual = true;
                break;
            }
        }
        if(!nEqual)
        {
            return dict[i];
        }
    }
    return text;
}

void PromptSingleton::setValues(std::string &val) {
    this->prompt = val;
}

std::unique_ptr<PromptSingleton>& PromptSingleton::getInstance() {
    if (instancePtr == nullptr)
    {
        instancePtr = std::unique_ptr<PromptSingleton>(new PromptSingleton());
    }
    return instancePtr; 
}

void PromptSingleton::getPrompt() {
    std::getline(std::cin, prompt);
}

void PromptSingleton::getPromptAuto(std::vector<std::string> dict) {
    std::getline(std::cin, prompt);
    std::string t1 = this->retValues();
    std::string temp = getMatch(t1, std::move(dict));
    this->setValues(temp);
}

int PromptSingleton::getPressedKey() {

    DWORD NumInputs = 0;
    DWORD InputsRead = 0;
    bool running = true;

    INPUT_RECORD irInput;

    GetNumberOfConsoleInputEvents(cmd::hInput, &NumInputs);

    ReadConsoleInput(cmd::hInput, &irInput, 1, &InputsRead);

    if (irInput.EventType == KEY_EVENT && irInput.Event.KeyEvent.bKeyDown)
    {
        switch(irInput.Event.KeyEvent.wVirtualKeyCode)
        {
            case VK_RETURN:
            return cmd::KeyPressed::ACCEPT;

            case VK_ESCAPE:
            return cmd::KeyPressed::BACK;

            case VK_R_KEY:
            return cmd::KeyPressed::ROTATE;

            case VK_UP:
            return cmd::KeyPressed::UP;

            case VK_DOWN:
            return cmd::KeyPressed::DOWN;

            case VK_RIGHT:
            return cmd::KeyPressed::RIGHT;

            case VK_LEFT:
            return cmd::KeyPressed::LEFT;
        } 
    }
    return -1;
}