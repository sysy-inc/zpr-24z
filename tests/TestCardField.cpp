//
// Created by adrwal on 11/6/24.
//
#include <gtest/gtest.h>

#include "../src/CardField.h"
#include "../src/Board.h"

TEST(TestCardField, CorrectInit)
{
    Board board;
    CardField cardField("CardField", board);
    EXPECT_EQ(1, 1);
}