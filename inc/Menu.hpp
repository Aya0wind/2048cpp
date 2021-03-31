#pragma once
#include "InputReader.hpp"
class Menu {
public:
    enum class MenuStatus {
        MAIN_MENU = 0,

        SCORE_MENU = 1,

        START_MENU = 3,

        GAME_WINDOW = 4,

        OVER_WINDOW = 5,

        EXIT = 6
    };
    static MenuStatus CurrentStatus;
    static bool StatusIsChanged;
    void Run();
    void SingleLoop();

protected:
    virtual void InitMenu() = 0;
    virtual void Draw() = 0;
    virtual void ProcessInput() = 0;
};
