#include "ScoreBoard.hpp"
#include "Resources.hpp"
#include <iomanip>
std::ostringstream& operator<<(std::ostringstream& out, ScoreBoard& board)
{
    out<< std::left << std::setfill(' ');
    out<< std::left << std::setw(15)<< Resources::ScoreBoardItems[ 0 ] + std::to_string(board.score);
    out<< std::left << std::setfill(' ') << std::setw(15)<< Resources::ScoreBoardItems[ 1 ] + std::to_string(board.bestscore);
    out<< std::left << std::setfill(' ') << std::setw(15)<< Resources::ScoreBoardItems[ 2 ] + std::to_string(board.steps);
    out << '\n';
    return out;
}
