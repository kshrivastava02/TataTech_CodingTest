#ifndef BOWLINGGAME_H
#define BOWLINGGAME_H

#include <map>
#include <string>
#include "Player.h"

class BowlingGame {
public:
    BowlingGame();
    void addPlayer(const std::string& name);
    void roll(const std::string& playerName, int pins);
    int getScore(const std::string& playerName);
    void displayScores() const;

private:
    std::map<std::string, Player> players;
};

#endif
