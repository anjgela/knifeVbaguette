#include <gtest/gtest.h>
#include "../Baguette.h"

class BaguetteFixture : public ::testing::Test {
protected:
    Knife* knife;
    Graph* map;
    Baguette* baguette;

    void SetUp() override {
        knife = new Knife();
        map = new Graph();
        baguette = new Baguette(knife, map);
        map->setWidth(20);
        map->setHeight(20);
    }

    void TearDown() override {
        delete knife;
        delete map;
    }
};
TEST_F(BaguetteFixture, InitializesAtCorrectPosition) {
    EXPECT_EQ(baguette->getPosX(), 7);
    EXPECT_EQ(baguette->getPosY(), 5);
}

TEST_F(BaguetteFixture, MovesRightIfWalkable) {

    map->getNode(8,5)->setID(TILE);
    baguette->right = true;
    sf::sleep(sf::seconds(0.06f));
    baguette->update(map);
    EXPECT_EQ(baguette->getPosX(), 8);
}

TEST_F(BaguetteFixture, DoesNotMoveIfNotWalkable) {
    map->getNode(6,5)->setID(OBSTACLE);
    baguette->left = true;
    sf::sleep(sf::seconds(0.06f));
    baguette->update(map);
    EXPECT_EQ(baguette->getPosX(), 7);
}
