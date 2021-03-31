#pragma once
#include <iostream>

#include "OptionMenu.hpp"

class MainMenu : public OptionMenu {
public:
    MainMenu();

protected:
    void ProcessInput() override;
    void DrawTitle() override;
    void InitMenu() override;
};
