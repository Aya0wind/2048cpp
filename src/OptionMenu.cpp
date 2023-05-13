#include "OptionMenu.hpp"

#include <iostream>
#include <utility>

#include "Color.hpp"
#include "Resources.hpp"

namespace {
void clear()
{
#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#elif __linux__
    system("clear");
#else
    system("clear");
#endif
}
}  // namespace

int OptionMenu::GetCurrentCursor() const
{
    return CurrentStage;
}
void OptionMenu::SetCurrentCursor(int CursorStage)
{
    CurrentStage = CursorStage;
}
void OptionMenu::DrawTitle()
{
    std::ostringstream Title_tmp;
    Title_tmp << Color::light_green(Resources::OptionMenuTitle);
    std::cout << Title_tmp.str() << std::endl;
}
void OptionMenu::DrawOptions()
{
    if (options.empty())
        return;
    std::ostringstream Options_tmp;
    for (int stage = 0; stage < options.size(); ++stage) {
        Options_tmp << "\n\t";
        if (stage == CurrentStage - 1)
            Options_tmp << "->";
        Options_tmp << Color::light_green(options[ stage ]);
    }
    std::cout << Options_tmp.str() << std::endl;
}
void OptionMenu::ReadDirection(char keyValue)
{
    using Direction = InputReader::Direction;
    Direction curDirection = InputReader::GetDirection(keyValue);
    switch (curDirection) {
        case Direction::UP:
            GetEffectiveInput = true;
            SubCurStage();
            break;
        case Direction::DOWN:
            GetEffectiveInput = true;
            PlusCurStage();
            break;
        default:
            break;
    }
}
void OptionMenu::ProcessInput()
{
    using Direction = InputReader::Direction;
    using Key = InputReader::Key;
    char keyValue = InputReader::ReadInput();
    ReadDirection(keyValue);
    switch (InputReader::GetEffectiveOption(keyValue)) {
        case Key::SPACE:
            if (CurrentStage == 1) {
                Menu::CurrentStatus = MenuStatus::GAME_WINDOW;
                Menu::StatusIsChanged = true;
            }
            else if (CurrentStage == 3) {
                Menu::CurrentStatus = MenuStatus::MAIN_MENU;
                Menu::StatusIsChanged = true;
            }
        default:
            break;
    }
}
int OptionMenu::GetStageSize()
{
    return options.size();
}
void OptionMenu::Draw()
{
    if (GetEffectiveInput) {
        ::clear();
        DrawTitle();
        DrawOptions();
        GetEffectiveInput = false;
    }
}

void OptionMenu::InitMenu()
{
    for (auto MainMenuItem : Resources::MainMenuItems) {
        AddOption(MainMenuItem);
    }
    DrawTitle();
    DrawOptions();
}

OptionMenu::OptionMenu(std::string MenuTitle)
    : CurrentStage(1)
    , title(std::move(MenuTitle))
    , GetEffectiveInput(false)
{
}
OptionMenu::OptionMenu()
    : CurrentStage(1)
    , title(Resources::OptionMenuTitle)
    , GetEffectiveInput(false)
{
}
