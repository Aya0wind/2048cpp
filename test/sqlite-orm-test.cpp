#include <exception>

#include "gtest/gtest.h"
#include "user-save/HighScore.hpp"


TEST(TestHighScore, test_highscore_rw)
{
    HighScoreManager high_score_manager("high_score.db");
    try {
        high_score_manager.addHighScore({0, "AAA", 100, 1});
    }
    catch (std::exception& _) {
    }
    auto highScore = high_score_manager.getHighScore("AAA");
    EXPECT_EQ(highScore.name, "AAA");
    EXPECT_EQ(highScore.score, 100);
    EXPECT_EQ(highScore.level, 1);
}
