#include "Player.h"
#include <stdexcept>
#include <iostream>

Player::Player() : name("Unnamed") {}
Player::Player(const std::string& name) : name(name) {}

void Player::roll(int pins) {
    if (frames.empty()) {
        frames.emplace_back();
    }

    if (frames.back().isComplete()) {
        if (frames.size() < 10) {
            frames.emplace_back();
        } else if (frames.size() == 10) {
            std::vector<int> rolls = frames.back().getRolls();
            if (rolls.size() < 3 && (rolls[0] == 10 || (rolls[0] + rolls[1] == 10))) {
                // allow adding to last frame
            } else {
                throw std::logic_error("Cannot have more than 10 frames");
            }
        } else {
            throw std::logic_error("Cannot have more than 10 frames");
        }
    }
    frames.back().addRoll(pins);
}

int Player::getTotalScore() const {
    std::vector<int> allRolls;
    for (const auto& f : frames) {
        for (int r : f.getRolls()) {
            allRolls.push_back(r);
        }
    }

    int score = 0;
    int rollIndex = 0;

    for (int frame = 0; frame < 10; ++frame) {
        if (rollIndex >= allRolls.size()) break;

        int first = allRolls[rollIndex];
        int second = (rollIndex + 1 < allRolls.size()) ? allRolls[rollIndex + 1] : 0;
        int third = (rollIndex + 2 < allRolls.size()) ? allRolls[rollIndex + 2] : 0;

        if (first == 10) {  // strike
            score += 10 + second + third;
            rollIndex += 1;
        } else if (first + second == 10) {  // spare
            score += 10 + third;
            rollIndex += 2;
        } else {  // open frame
            score += first + second;
            rollIndex += 2;
        }
    }
    return score;
}

std::string Player::getName() const {
    return name;
}
