#pragma once
#include "InputReader.hpp"
/*
 * 界面基类
 */
class Menu {
public:
    //菜单状态
    enum class MenuStatus {
        //主菜单
        MAIN_MENU = 0,
        //分数菜单
        SCORE_MENU = 1,
        //开始菜单
        START_MENU = 3,
        //游戏界面
        GAME_WINDOW = 4,
        //结束菜单
        OVER_WINDOW = 5,
        //退出游戏
        EXIT = 6
    };
    static MenuStatus CurrentStatus;
    static bool StatusIsChanged;
    void Run();
    void SingleLoop();

protected:
    //初始化菜单
    virtual void InitMenu() = 0;
    //绘制菜单
    virtual void Draw() = 0;
    //读取用户输入
    virtual void ProcessInput() = 0;
};
