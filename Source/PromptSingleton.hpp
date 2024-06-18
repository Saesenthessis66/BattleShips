//
// Created by lucja on 18.06.2024.
//

#ifndef PROMPTSINGLETON_HPP
#define PROMPTSINGLETON_HPP

#include <string>
#include <iostream>
#include <vector>

class PromptSingleton{
private:
    std::string prompt;
    static PromptSingleton* instancePtr;
    PromptSingleton()= default;
public:
    PromptSingleton(const PromptSingleton& obj) = delete;

    static PromptSingleton* getInstance();

    void setValues(std::string& val);

    std::string retValues(){ return prompt; }

    void getPrompt();

    void getPromptAuto(std::vector<std::string> dict);
};

#endif //PROMPTSINGLETON_HPP
