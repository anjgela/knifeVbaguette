#include <gtest/gtest.h>
#include "Match.h"

class MatchTest : public Match {
public:
    using Match::status;           // expose status
    using Match::playingTime;      // expose accumulated time
    using Match::timer;            // expose timer

    unsigned int getGameStatus() const {
        return status;
    }
};

class MatchFixture : public ::testing::Test {
protected:
    MatchTest match;

    void fastForward(sf::Time dt) {
        match.playingTime += dt;
        match.timer.restart();
    }
};

TEST_F(MatchFixture, StartsInPlayingState) {
    EXPECT_TRUE(match.isWindowOpen());
    EXPECT_EQ(match.getGameStatus(), PLAYING);
}

TEST_F(MatchFixture, UpdateDoesNotCrashInPlaying) {
    EXPECT_NO_THROW(match.update());
    EXPECT_EQ(match.getGameStatus(), PLAYING);
}

TEST_F(MatchFixture, TransitionToWin) {
    fastForward(sf::seconds(46));
    match.update();
    EXPECT_EQ(match.getGameStatus(), WIN);
}

TEST_F(MatchFixture, TransitionsToGameOverOnCollision) {
    float x = 100.f, y = 150.f;
    match.setKnifePosition(x, y);
    match.setBaguettePosition(x, y);
    match.update();
    EXPECT_EQ(match.getStatus(), GAME_OVER);
}

TEST_F(MatchFixture, PauseToggle) {
    EXPECT_FALSE(match.isPaused());
    match.togglePause();
    EXPECT_TRUE(match.isPaused));
    match.togglePause();
    EXPECT_FALSE(match.isPaused());
}