#pragma once
#include "InputReader.hpp"
/*
 * �������
 */
class Menu {
public:
    //�˵�״̬
    enum class MenuStatus {
        //���˵�
        MAIN_MENU = 0,
        //�����˵�
        SCORE_MENU = 1,
        //��ʼ�˵�
        START_MENU = 3,
        //��Ϸ����
        GAME_WINDOW = 4,
        //�����˵�
        OVER_WINDOW = 5,
        //�˳���Ϸ
        EXIT = 6
    };
    static MenuStatus CurrentStatus;
    static bool StatusIsChanged;
    void Run();
    void SingleLoop();

protected:
    //��ʼ���˵�
    virtual void InitMenu() = 0;
    //���Ʋ˵�
    virtual void Draw() = 0;
    //��ȡ�û�����
    virtual void ProcessInput() = 0;
};
