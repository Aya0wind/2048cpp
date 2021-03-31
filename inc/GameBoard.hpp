#pragma once
/*
 * 游戏界面类
 */
#include <map>
#include <string>
#include <vector>

#include "Menu.hpp"
#include "ScoreBoard.hpp"
class GameBoard : public Menu {
    enum class State { IN_GAME, GAME_OVER, PAUSE, TIME_UP };
    bool pause;
    bool need_add_num{};
    size_t width;
    size_t height;
    size_t size;
    ScoreBoard scoreboard;
    std::vector<std::vector<size_t>> nums;
    std::vector<std::string> buffer;
    std::ostringstream& DrawUpLine(std::ostringstream& tmp) const;
    std::ostringstream& DrawSpaceLine(std::ostringstream& tmp);
    std::ostringstream& DrawNumLine(size_t line_num, std::ostringstream& tmp);
    std::ostringstream& DrawMiddleLine(std::ostringstream& tmp) const;
    std::ostringstream& DrawDownLine(std::ostringstream& tmp) const;
    static std::ostringstream& DrawPrompt(std::ostringstream& tmp);
    void DrawBoard();
    void MoveNums(InputReader::Direction);
    void AddNewNum();
    bool Check();
    void MoveUp();
    void MoveDown();
    void MoveLeft();
    void MoveRight();

protected:
    void InitMenu() override;
    void Draw() override;
    void ProcessInput() override;

public:
    GameBoard(size_t size, size_t width, size_t height);
    GameBoard();
    ~GameBoard()
    {
        std::cout << "\033[?25h" << std::endl;
    }
};