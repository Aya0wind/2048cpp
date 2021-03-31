#include "MenuManager.hpp"

#include "Color.hpp"
#include "GameBoard.hpp"
#include "Menu.hpp"
#include "OptionMenu.hpp"
#include "ScoreBoard.hpp"
#include "mainmenu.hpp"
void MenuManager::StartMenu()
{
    using MenuStatus = Menu::MenuStatus;
    while (Menu::CurrentStatus != Menu::MenuStatus::EXIT) {
        system("cls");
        Menu::StatusIsChanged = false;
        if (Menu::CurrentStatus == MenuStatus::MAIN_MENU) {
            MainMenu menu;
            menu.Run();
        }
        else if (Menu::CurrentStatus == MenuStatus::START_MENU) {
            OptionMenu menu;
            menu.Run();
        }
        else if (Menu::CurrentStatus == MenuStatus::GAME_WINDOW) {
            GameBoard menu;
            menu.Run();
        }
//        else(Menu::CurrentStatus==MenuStatus::OVER_WINDOW){
//         }
    }
    std::cout << Color::blue("\nThanks For Playing") << std::endl;
}
