#pragma once
#include <iostream>
#include <sstream>
struct ScoreBoard {
    int score;
    int bestscore;
    int time;
    int steps;
    ScoreBoard()
        : score(0)
        , bestscore(0)
        , time(0)
        , steps(0)
    {
    }
    friend std::ostringstream& operator<<(std::ostringstream& out, ScoreBoard& board);
};
