#include <gtest/gtest.h>
#include "Baguette.h"
#include "Knife.h"

class BaguetteTest : public ::testing::Test {
protected:
    Knife* knife;
    Baguette* baguette;
    Graph* map;

    void SetUp() override {
        knife = new Knife();
        baguette = new Baguette(knife);
        map = new Graph(20, 20);
        map->getNode(8, 5)->setID(TILE);
    }

    void TearDown() override {
        delete baguette;
        delete map;
    }
};

TEST_F(BaguetteTest, InitializesAtCorrectPosition) {
    EXPECT_EQ(baguette->getPosX(), 7);
    EXPECT_EQ(baguette->getPosY(), 5);
}

TEST_F(BaguetteTest, MovesRightIfWalkable) {
    baguette->right = true;
    //sf::sleep(sf::seconds(0.06f));
    baguette->update(map);
    EXPECT_EQ(baguette->getPosX(), 8);
}

TEST_F(BaguetteTest, DoesNotMoveIfNotWalkable) {
    baguette->left = true;
    //sf::sleep(sf::seconds(0.06f));
    baguette->update(map);
    EXPECT_EQ(baguette->getPosX(), 7);
}