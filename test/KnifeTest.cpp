#include <gtest/gtest.h>
#include <iostream>
#include "../Knife.h"
#include "../Baguette.h"
class KnifeFixture : public ::testing::Test {
protected:
    Knife* knife;
    Baguette* baguette;
    Graph* map;

    void SetUp() override {
        knife = new Knife();
        map = new Graph();
        baguette = new Baguette(knife, map);
        map->setWidth(20);
        map->setHeight(20);
        map->getNode(7,5)->setID(TILE);
    }

    void TearDown() override {
        delete baguette;
        delete map;
    }
};

TEST_F(KnifeFixture, InitializesAtCorrectPosition) {
    EXPECT_EQ(knife->getPosX(), 0);
    EXPECT_EQ(knife->getPosY(), 0);
}

TEST_F(KnifeFixture, UpdatesWithoutCrashingWithTarget) {
    EXPECT_NO_THROW(knife->update(map));
}

TEST_F(KnifeFixture, MovesTowardTargetIfPathExists) {
    knife->move(baguette->getPosX(), baguette->getPosY(), map);
    sf::Clock playingTime;
    playingTime.restart();
    knife->getClock().restart();
    while (playingTime.getElapsedTime() < sf::seconds(1.5f)) {
        knife->update(map);
    }
    if (!knife->pathFound()) {
        EXPECT_EQ(knife->getPosX(), 0);
        EXPECT_EQ(knife->getPosY(), 0);
    } else {
        EXPECT_EQ(knife->getPosX(), 7);
        EXPECT_EQ(knife->getPosY(), 5);
    }
}

TEST_F(KnifeFixture, FollowsPath) {
    knife->move(baguette->getPosX(), baguette->getPosY(), map);
    if (knife->pathFound()) {
        size_t pathIndex = 0;
        while (pathIndex < knife->getPath().size()) {
            knife->update(map);
            int newX = knife->getPath()[pathIndex].getX();
            int newY = knife->getPath()[pathIndex].getY();

            if (knife->getPosX() == newX && knife->getPosY() == newY) {
                EXPECT_EQ(knife->getPosX(), newX);
                EXPECT_EQ(knife->getPosY(), newY);
                ++pathIndex;
            }
        }
    } else {
        EXPECT_EQ(knife->getPosX(), 0);
        EXPECT_EQ(knife->getPosY(), 0);
    }
}