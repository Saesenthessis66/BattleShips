#ifndef PROMPTSINGLETON_HPP
#define PROMPTSINGLETON_HPP

#include <string>
#include <iostream>
#include <vector>
#include <memory>

class PromptSingleton{
private:
    std::string prompt;
    static std::unique_ptr<PromptSingleton> instancePtr;
    PromptSingleton()= default;
public:
    PromptSingleton(const PromptSingleton& obj) = delete;

    static std::unique_ptr<PromptSingleton>& getInstance();

    void setValues(std::string& val);

    std::string retValues(){ return prompt; }

    void getPrompt();

    void getPromptAuto(std::vector<std::string> dict);

    int getPressedKey();
};

#endif