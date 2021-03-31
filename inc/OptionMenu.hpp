#pragma once
#include <string>
#include <vector>

#include "Menu.hpp"
class OptionMenu : public Menu {
protected:
    std::string title;
    std::vector<std::string> options;
    int CurrentStage;
    bool GetEffectiveInput;

    virtual void InitMenu() override;
    virtual void Draw() override;
    virtual void ProcessInput() override;
    virtual void DrawTitle();
    virtual void DrawOptions();

    void ReadDirection(char i);
    inline void PlusCurStage()
    {
        if (CurrentStage == options.size())
            return;
        else
            CurrentStage++;
    }
    inline void SubCurStage()
    {
        if (CurrentStage == 1)
            return;
        else
            CurrentStage--;
    }

public:
    void SetCurrentCursor(int CursorStage);
    int GetCurrentCursor() const;
    int GetStageSize();
    OptionMenu(std::string  MenuTitle);
    OptionMenu();
    inline void AddOption(const std::string& option)
    {
        options.push_back(option);
    }
};