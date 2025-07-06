#include <gtest/gtest.h>
#include "../src/Player.h"
#include "../src/BowlingGame.h"

// Helper to simulate a full game
void rollMany(BowlingGame& game, const std::string& player, const std::vector<int>& rolls) {
    game.addPlayer(player);
    for (int pins : rolls) {
        game.roll(player, pins);
    }
}

// Test 1: All gutter balls
TEST(BowlingGameTest, GutterGame) {
    BowlingGame game;
    rollMany(game, "Gutter", std::vector<int>(20, 0));
    EXPECT_EQ(game.getScore("Gutter"), 0);
}

// Test 2: All ones
TEST(BowlingGameTest, AllOnes) {
    BowlingGame game;
    rollMany(game, "Ones", std::vector<int>(20, 1));
    EXPECT_EQ(game.getScore("Ones"), 20);
}

// Test 3: One spare followed by 3
TEST(BowlingGameTest, OneSpare) {
    BowlingGame game;
    std::vector<int> rolls = {5, 5, 3};
    rolls.insert(rolls.end(), 17, 0);  // append 17 zeros
    rollMany(game, "Spare", rolls);
    EXPECT_EQ(game.getScore("Spare"), 16);
}

// Test 4: One strike followed by 3 and 4
TEST(BowlingGameTest, OneStrike) {
    BowlingGame game;
    std::vector<int> rolls = {10, 3, 4};
    rolls.insert(rolls.end(), 16, 0);  // append 16 zeros
    rollMany(game, "Strike", rolls);
    EXPECT_EQ(game.getScore("Strike"), 24);
}

// Test 5: Perfect game (12 strikes)
TEST(BowlingGameTest, PerfectGame) {
    BowlingGame game;
    rollMany(game, "Perfect", std::vector<int>(12, 10));
    EXPECT_EQ(game.getScore("Perfect"), 300);
}
