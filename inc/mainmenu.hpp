#pragma once
#include <iostream>

#include "OptionMenu.hpp"
/*
 * 主界面类
 */
class MainMenu : public OptionMenu {
public:
    MainMenu();

protected:
    void ProcessInput() override;
    void DrawTitle() override;
    void InitMenu() override;
};
