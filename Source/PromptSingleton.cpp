//
// Created by lucja on 18.06.2024.
//

#include "PromptSingleton.hpp"
#include <utility>

std::string GetMatch(std::string &text, std::vector<std::string> dict) {
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

void PromptSingleton::SetValues(std::string &val) {
    this->prompt = val;
}

PromptSingleton *PromptSingleton::GetInstance() {
    if (instancePtr == nullptr)
    {
        instancePtr = new PromptSingleton();
        return instancePtr;
    }
    else
    {
        return instancePtr;
    }
}

void PromptSingleton::GetPrompt() {
    std::getline(std::cin, prompt);
}

void PromptSingleton::GetPromptAuto(std::vector<std::string> dict) {
    std::getline(std::cin, prompt);
    std::string t1 = this->RetValues();
    std::string temp = GetMatch(t1, std::move(dict));
    this->SetValues(temp);
}