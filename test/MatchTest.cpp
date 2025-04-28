#include <gtest/gtest.h>
#include "../Match.h"


TEST(Match, StartsInPlaying){
    Match* match;
    match = new Match();
    ASSERT_EQ(match->checkGameStatus(), gameStatus::PLAYING);
}

TEST(Match, TransitionToWin) {
    Match* match;
    match = new Match();
    match->fastForwardTimer(sf::seconds(46));
    match->update();
    EXPECT_EQ(match->checkGameStatus(), gameStatus::WIN);
}

TEST(Match, TransitionsToGameOverOnCollision) {
    Match* match;
    match = new Match();
    match->getKnife()->setPosX(7);
    match->getKnife()->setPosY(5);
    EXPECT_EQ(match->checkGameStatus(), gameStatus::GAME_OVER);
}

TEST(Match, PauseToggle) {
    Match* match;
    match = new Match();
    EXPECT_FALSE(match->isPaused());
    match->togglePause();
    EXPECT_TRUE(match->isPaused());
    match->togglePause();
    EXPECT_FALSE(match->isPaused());
}