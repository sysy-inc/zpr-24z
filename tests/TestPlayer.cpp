//
// Created by adrwal on 11/6/24.
//
#include <gtest/gtest.h>

#include "../src/Board.h"
#include "../src/Player.h"
#include "../src/Constants.h"
#include  "../src/Fields/Property.h"
#include  "../src/Fields/Trains.h"


TEST(TestPlayer, InitPlayer)
{
    Board board;
    ConsolePlayer player("Player", 1000, board);
    EXPECT_EQ(player.getName(), "Player");
    EXPECT_EQ(player.getMoney(), 1000);
}

TEST(TestPlayer, SetPosition)
{
    Board board;
    ConsolePlayer player("Player", 1000, board);
    player.setPositionIdx(1);
    EXPECT_EQ(player.getPositionIdx(), 1);
}

TEST(TestPlayer, pushProperty)
{
    Board board;
    ConsolePlayer player("Player", 1000, board);
    auto property = std::make_shared<Property>("", board, 1, 1, 1, Color::BROWN);
    player.pushProperty(property);
    EXPECT_EQ(player.getProperties().size(), 1);
    EXPECT_EQ(player.getProperties()[0].get(), property.get());
}

TEST(TestPlayer, addMoney)
{
    Board board;
    ConsolePlayer player("Player", 1000, board);
    player.addMoney(300);
    EXPECT_EQ(player.getMoney(), 1300);
}

TEST(TestPlayerOwnsAllPropertiesOfColor, ownsAllPropertiesOfColor)
{
    Board board;
    auto player = std::make_unique<ConsolePlayer>("player", 1000, board);
    auto property1 = std::make_shared<Property>("", board, 1, 1, 1, Color::BROWN);
    auto property2 = std::make_shared<Property>("", board, 1, 1, 1, Color::BROWN);
    player->pushProperty(property1);
    player->pushProperty(property2);
    EXPECT_EQ(player->ownsAllPropertiesOf(Color::BROWN), true);
}

TEST(TestPlayerOwnsAllPropertiesOfColor, ownsAllPropertiesOfColorFalse)
{
    Board board;
    auto player = std::make_unique<ConsolePlayer>("player", 1000, board);
    auto property1 = std::make_shared<Property>("", board, 1, 1, 1, Color::BROWN);
    player->pushProperty(property1);
    EXPECT_EQ(player->ownsAllPropertiesOf(Color::BROWN), false);
}

TEST(TestPlayerGetNumberOfTrains, getNumberOfTrains)
{
    Board board;
    auto player = std::make_unique<ConsolePlayer>("player", 1000, board);
    auto train1 = std::make_shared<Trains>("", board, 1);
    auto train2 = std::make_shared<Trains>("", board, 1);
    player->pushTrain(train1);
    player->pushTrain(train2);
    EXPECT_EQ(player->getNumberOfTrains(), 2);
}

TEST(TestPlayer, pushCurrentTurnMadeDecisions)
{
    Board board;
    ConsolePlayer player("Player", 1000, board);
    player.saveTurnDecision(PlayerDecisionOutputs::NO_DECISION);
    EXPECT_EQ(player.getMadeTurnDecisions().size(), 1);
}
