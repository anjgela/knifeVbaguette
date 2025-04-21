#include <gtest/gtest.h>
#include "Knife.h"
#include "Baguette.h"
#include "Graph.h"

class KnifeTest : public ::testing::Test {
protected:
    Knife knife;
    Baguette* baguette;
    Graph graph{20, 20};

    void SetUp() override {
        baguette = new Baguette(&knife);
        graph.getNode(6, 5)->setID(TILE);
    }

    void TearDown() override {
        delete baguette;
    }
};

TEST_F(KnifeTest, InitializesAtCorrectPosition) {
    EXPECT_EQ(knife.getPosX(), 5);
    EXPECT_EQ(knife.getPosY(), 5);
}

TEST_F(KnifeTest, UpdatesWithoutCrashingWithTarget) {
    EXPECT_NO_THROW(knife.update(&graph));
}

TEST_F(KnifeTest, MovesTowardTargetIfPathExists) {
    baguette->getShape().setPosition(6 * TILE_SIZE, 5 * TILE_SIZE);
    //sf::sleep(sf::seconds(0.06f));
    knife.update(&graph);
    EXPECT_EQ(knife.getPosX(), 6);
}