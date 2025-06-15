#include "BowlingGame.h"
#include <iostream>
#include <stdexcept>

BowlingGame::BowlingGame() {}

void BowlingGame::addPlayer(const std::string& name) {
    if (players.find(name) != players.end())
        throw std::invalid_argument("Player already exists");
    players.emplace(name, Player(name));
}

void BowlingGame::roll(const std::string& playerName, int pins) {
    if (players.find(playerName) == players.end())
        throw std::invalid_argument("Player not found");
    players[playerName].roll(pins);
}

int BowlingGame::getScore(const std::string& playerName) {
    if (players.find(playerName) == players.end())
        throw std::invalid_argument("Player not found");
    return players[playerName].getTotalScore();
}

void BowlingGame::displayScores() const {
    for (const auto& entry : players) {
        std::cout << entry.first << ": " << entry.second.getTotalScore() << std::endl;
    }
}
