#pragma once

class InputReader {
public:
    enum class Direction { UP = 100, DOWN = 101, RIGHT = 102, LEFT = 103, NONE = 104 };
    enum class Key { SPACE = 2049, EXIT = 2051, PAUSE = 2052, INVAILD = 2054, SAVE = 2055 };
    static Direction GetDirection(char inputKey);
    static Key GetEffectiveOption(char inputKey);
    static char ReadInput();
    InputReader() = delete;
    ~InputReader() = delete;
    InputReader(const InputReader&) = delete;

private:
    static Direction direction;
    static Key character;
};
