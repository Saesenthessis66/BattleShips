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

    static PromptSingleton* GetInstance();

    void SetValues(std::string& val);

    std::string RetValues(){ return prompt; }

    void GetPrompt();

    void GetPromptAuto(std::vector<std::string> dict);
};

#endif //PROMPTSINGLETON_HPP
