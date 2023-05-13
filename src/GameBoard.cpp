#include "GameBoard.hpp"

#include <ctime>
#include <iomanip>

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

GameBoard::GameBoard(size_t size, size_t width = 6, size_t height = 2)
    : height(height)
    , buffer(height)
    , width(width)
    , size(size)
    , nums(size)
    , pause(false)
{
    std::cout << "\033[?25l" << std::endl;
    for (auto& num : nums)
        num.resize(size);
}
GameBoard::GameBoard()
    : height(2)
    , width(6)
    , buffer(height)
    , size(4)
    , nums(size)
    , pause(false)
{
    std::cout << "\033[?25l" << std::endl;
    for (auto& num : nums)
        num.resize(size);
}
void GameBoard::InitMenu()
{
    srand(( unsigned int )time(0));
    nums[ rand() % size ][ rand() % size ] = 2;
    DrawBoard();
}
void GameBoard::Draw()
{
    if (pause)
        return;
    DrawBoard();
}
void GameBoard::ProcessInput()
{
    using Direction = InputReader::Direction;
    using Option = InputReader::Key;
    char keyValue = InputReader::ReadInput();
    Direction direction = InputReader::GetDirection(keyValue);
    Option option = InputReader::GetEffectiveOption(keyValue);
    if (direction != Direction::NONE) {
        if (!pause) {
            MoveNums(direction);
            scoreboard.steps++;
            if (need_add_num)
                AddNewNum();
            if (Check()) {
                Menu::CurrentStatus = Menu::MenuStatus::OVER_WINDOW;
                Menu::StatusIsChanged = true;
            }
        }
    }
    else if (option != Option::INVAILD) {
        if (option == Option::EXIT) {
            CurrentStatus = Menu::MenuStatus::MAIN_MENU;
            Menu::StatusIsChanged = true;
            return;
        }
        else {
            pause = !pause;
            DrawBoard();
        }
    }
}

void GameBoard::DrawBoard()
{
    std::ostringstream tmp;
    size_t middle = height / 2;
    ::clear();
    tmp << scoreboard << '\n';
    DrawUpLine(tmp);
    int line_num = 0;
    size_t maxLine = size * height;
    for (size_t line = 1; line < maxLine; line++) {
        if (line % height == 0)
            DrawMiddleLine(tmp);
        else if (line % height == middle) {
            DrawNumLine(line_num, tmp);
            ++line_num;
        }
        else
            DrawSpaceLine(tmp);
    }
    DrawDownLine(tmp);
    DrawPrompt(tmp);
    if (pause)
        tmp << "\n\n\tGame paused!";
    std::cout << tmp.str() << std::flush;
}
std::ostringstream& GameBoard::DrawUpLine(std::ostringstream& tmp) const
{
    using namespace Resources;
    tmp << border_left_up;
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < width; j++) {
            tmp << horizontal_line;
        }
        if (i == size - 1)
            tmp << border_right_up;
        else
            tmp << border_middle_up;
    }
    tmp << '\n';
    return tmp;
}
std::ostringstream& GameBoard::DrawSpaceLine(std::ostringstream& tmp)
{
    using namespace Resources;
    tmp << vertical_line;
    for (size_t i = 0; i < size; i++) {
        for (size_t i = 0; i < width; i++) {
            tmp << ' ';
        }
        tmp << vertical_line;
    }
    tmp << '\n';
    return tmp;
}

std::ostringstream& GameBoard::DrawNumLine(size_t line_num, std::ostringstream& tmp)
{
    using namespace Resources;
    auto num_position = width / 2;
    tmp << vertical_line;
    for (size_t i = 0; i < size; i++) {
        auto ColoredNum = Color::GetRandomColor(nums[ line_num ][ i ]);
        size_t num = 0;
        tmp << std::right << std::setfill(' ');
        if (nums[ line_num ][ i ] == 0)
            tmp << std::setw(width) << ' ';
        else
            tmp << std::setw(17) << ColoredNum;
        tmp << vertical_line;
    }
    tmp << '\n';
    return tmp;
}
std::ostringstream& GameBoard::DrawMiddleLine(std::ostringstream& tmp) const
{
    using namespace Resources;
    tmp << border_left;
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < width; j++) {
            tmp << horizontal_line;
        }
        if (i == size - 1)
            tmp << border_right;
        else
            tmp << border_middle;
    }
    tmp << '\n';
    return tmp;
}
std::ostringstream& GameBoard::DrawDownLine(std::ostringstream& tmp) const
{
    using namespace Resources;
    tmp << border_left_down;
    for (size_t i = 0; i < size; i++) {
        for (size_t j = 0; j < width; j++) {
            tmp << horizontal_line;
        }
        if (i == size - 1)
            tmp << border_right_down;
        else
            tmp << border_middle_down;
    }
    tmp << '\n';
    return tmp;
}
std::ostringstream& GameBoard::DrawPrompt(std::ostringstream& tmp)
{
    using namespace Resources;
    tmp << Prompts;
    return tmp;
}
void GameBoard::MoveNums(InputReader::Direction direction)
{
    using Direction = InputReader::Direction;
    switch (direction) {
        case Direction::UP:
            MoveUp();
            return;

        case Direction::DOWN:
            MoveDown();
            return;

        case Direction::LEFT:
            MoveLeft();
            return;

        case Direction::RIGHT:
            MoveRight();
            return;

        default:
            break;
    }
}

void GameBoard::MoveUp()
{
    for (int i = 0; i < size; ++i) {
        for (int j = 1, k = 0; j < size; ++j) {
            if (nums[ j ][ i ] > 0) {
                if (nums[ k ][ i ] == nums[ j ][ i ]) {
                    scoreboard.score += nums[ k++ ][ i ] *= 2;
                    nums[ j ][ i ] = 0;
                    need_add_num = true;
                }
                else if (nums[ k ][ i ] == 0) {
                    nums[ k ][ i ] = nums[ j ][ i ];
                    nums[ j ][ i ] = 0;
                    need_add_num = true;
                }
                else {
                    nums[ ++k ][ i ] = nums[ j ][ i ];
                    if (j != k) {
                        nums[ j ][ i ] = 0;
                        need_add_num = 1;
                    }
                }
            }
        }
    }
}
void GameBoard::MoveDown()
{
    for (int i = 0; i < size; ++i) {
        for (int j = 2, k = size - 1; j >= 0; --j) {
            if (nums[ j ][ i ] > 0) {
                if (nums[ k ][ i ] == nums[ j ][ i ]) {
                    scoreboard.score += nums[ k-- ][ i ] *= 2;
                    nums[ j ][ i ] = 0;
                    need_add_num = true;
                }
                else if (nums[ k ][ i ] == 0) {
                    nums[ k ][ i ] = nums[ j ][ i ];
                    nums[ j ][ i ] = 0;
                    need_add_num = true;
                }
                else {
                    nums[ --k ][ i ] = nums[ j ][ i ];
                    if (j != k) {
                        nums[ j ][ i ] = 0;
                        need_add_num = true;
                    }
                }
            }
        }
    }
}
void GameBoard::MoveLeft()
{
    for (int i = 0; i < size; ++i) {
        for (int j = 1, k = 0; j < size; ++j) {
            if (nums[ i ][ j ] > 0) {
                if (nums[ i ][ k ] == nums[ i ][ j ]) {
                    scoreboard.score += nums[ i ][ k++ ] *= 2;
                    nums[ i ][ j ] = 0;
                    need_add_num = true;
                }
                else if (nums[ i ][ k ] == 0) {
                    nums[ i ][ k ] = nums[ i ][ j ];
                    nums[ i ][ j ] = 0;
                    need_add_num = true;
                }
                else {
                    nums[ i ][ ++k ] = nums[ i ][ j ];
                    if (j != k) {
                        nums[ i ][ j ] = 0;
                        need_add_num = true;
                    }
                }
            }
        }
    }
}
void GameBoard::MoveRight()
{
    for (int i = 0; i < size; ++i) {
        for (int j = 2, k = size - 1; j >= 0; --j) {
            if (nums[ i ][ j ] > 0) {
                if (nums[ i ][ k ] == nums[ i ][ j ]) {
                    scoreboard.score += nums[ i ][ k-- ] *= 2;
                    nums[ i ][ j ] = 0;
                    need_add_num = true;
                }
                else if (nums[ i ][ k ] == 0) {
                    nums[ i ][ k ] = nums[ i ][ j ];
                    nums[ i ][ j ] = 0;
                    need_add_num = 1;
                }
                else {
                    nums[ i ][ --k ] = nums[ i ][ j ];
                    if (j != k) {
                        nums[ i ][ j ] = 0;
                        need_add_num = true;
                    }
                }
            }
        }
    }
}
void GameBoard::AddNewNum()
{
    size_t maxsize = size * size;
    size_t n = rand() % maxsize;
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            if (nums[ i ][ j ] == 0 && n-- == 0) {
                nums[ i ][ j ] = (rand() % 5 ? 2 : 4);
                return;
            }
        }
    }
}
bool GameBoard::Check()
{
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size - 1; ++j) {
            if (nums[ i ][ j ] == nums[ i ][ j + 1 ] || nums[ j ][ i ] == nums[ j + 1 ][ i ])
                return false;
        }
    }
    return true;
}
