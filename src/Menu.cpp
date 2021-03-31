#include "Menu.hpp"

#include <iostream>
Menu::MenuStatus Menu::CurrentStatus = Menu::MenuStatus::MAIN_MENU;
bool Menu::StatusIsChanged = false;
void Menu::Run()
{
    InitMenu();
    while (!StatusIsChanged)
        SingleLoop();
}
void Menu::SingleLoop()
{
    ProcessInput();
    Draw();
}
