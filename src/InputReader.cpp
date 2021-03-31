#include "InputReader.hpp"

#include <iostream>
#ifdef __linux__
#include <termios.h>
#include <unistd.h>
void InputReader::ReadInput()
{
    struct termios save, current;
    tcgetattr(0, &save);  // 得到原来的终端属性
    current = save;
    current.c_lflag &= ~ICANON;  // 设置非正规模式，如果程序每次要从终端读取一个字符的话，这是必须的
    current.c_lflag &= ~ECHO;         // 关闭回显
    current.c_cc[ VMIN ] = 1;         // 设置非正规模式下的最小字符数
    current.c_cc[ VTIME ] = 0;        // 设置非正规模式下的读延时
    tcsetattr(0, TCSANOW, &current);  // 设置新的终端属性
    inputchar = getchar();
    tcsetattr(0, TCSANOW, &save);
}
#elif defined(_WIN32)
#include <conio.h>
void InputReader::ReadInput()
{
    inputKey = static_cast<char>(_getch());
}
#endif

InputReader::Direction InputReader::direction = InputReader::Direction::NONE;
InputReader::Character InputReader::character = InputReader::Character::INVAILD;
char InputReader::inputKey = '^';
char InputReader::GetInputChar()
{
    return inputKey;
}
InputReader::Character InputReader::GetEffectiveOption()
{
    switch (inputKey) {
        case ' ':
            return Character::SPACE;
        case 'E':
        case 'e':
            return Character::EXIT;
        case 'P':
        case 'p':
            return Character::PAUSE;
        case 'I':
        case 'i':
            return Character::SAVE;
        default:
            return Character::INVAILD;
    }
}
InputReader::Direction InputReader::GetDirection()
{
    switch (inputKey) {
        case 'W':
        case 'w':
            return Direction::UP;

        case 'A':
        case 'a':
            return Direction::LEFT;

        case 'S':
        case 's':
            return Direction::DOWN;

        case 'D':
        case 'd':
            return Direction::RIGHT;

        default:
            return Direction::NONE;
    }
}
