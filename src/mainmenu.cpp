#include "mainmenu.hpp"

#include "Color.hpp"
#include "Resources.hpp"

void MainMenu::ProcessInput()
{
    using MenuStatus = Menu::MenuStatus;
    using Direction = InputReader::Direction;
    using Character = InputReader::Character;
    InputReader::ReadInput();
    ReadDirection();
    if (InputReader::GetEffectiveOption() == Character::SPACE) {
        if (CurrentStage == 1) {
            Menu::CurrentStatus = MenuStatus::START_MENU;
            Menu::StatusIsChanged = true;
        }
        else if (CurrentStage == 3) {
            Menu::CurrentStatus = MenuStatus::EXIT;
            Menu::StatusIsChanged = true;
        }
    }
}
void MainMenu::DrawTitle()
{
    std::ostringstream main_menu_out;
    main_menu_out << Color::light_green(Resources::title_2048);
    std::cout << main_menu_out.str();
}

void MainMenu::InitMenu()
{
    for (auto MainMenuItem : Resources::MainMenuItems) {
        AddOption(MainMenuItem);
    }
    DrawTitle();
    DrawOptions();
}
MainMenu::MainMenu()
    : OptionMenu(Resources::title_2048)
{
}
