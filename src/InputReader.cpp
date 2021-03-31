#include "InputReader.hpp"
#ifdef __linux__
#include <termios.h>
#include <unistd.h>
void InputReader::ReadInput()
{
    struct termios save, current;
    tcgetattr(0, &save);  // �õ�ԭ�����ն�����
    current = save;
    current.c_lflag &= ~ICANON;  // ���÷�����ģʽ���������ÿ��Ҫ���ն˶�ȡһ���ַ��Ļ������Ǳ����
    current.c_lflag &= ~ECHO;         // �رջ���
    current.c_cc[ VMIN ] = 1;         // ���÷�����ģʽ�µ���С�ַ���
    current.c_cc[ VTIME ] = 0;        // ���÷�����ģʽ�µĶ���ʱ
    tcsetattr(0, TCSANOW, &current);  // �����µ��ն�����
    inputchar = getchar();
    tcsetattr(0, TCSANOW, &save);
}
#elif defined(_WIN32)
#include <conio.h>
char InputReader::ReadInput()
{
    return static_cast<char>(_getch());
}
#endif

InputReader::Key InputReader::GetEffectiveOption(const char inputKey)
{
    switch (inputKey) {
        case ' ':
            return Key::SPACE;
        case 'E':
        case 'e':
            return Key::EXIT;
        case 'P':
        case 'p':
            return Key::PAUSE;
        case 'I':
        case 'i':
            return Key::SAVE;
        default:
            return Key::INVAILD;
    }
}
InputReader::Direction InputReader::GetDirection(const char inputKey)
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
