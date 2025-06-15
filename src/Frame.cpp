#include "Frame.h"
#include <stdexcept>

Frame::Frame() {}

void Frame::addRoll(int pins) {
    if (pins < 0 || pins > 10)
        throw std::invalid_argument("Invalid number of pins");

    if (rolls.size() >= 3)
        throw std::logic_error("Cannot add more than three rolls to a frame");

    rolls.push_back(pins);
}

int Frame::getScore() const {
    int score = 0;
    for (int pins : rolls) {
        score += pins;
    }
    return score;
}

bool Frame::isStrike() const {
    return rolls.size() >= 1 && rolls[0] == 10;
}

bool Frame::isSpare() const {
    return rolls.size() == 2 && (rolls[0] + rolls[1] == 10);
}

bool Frame::isComplete() const {
    if (rolls.size() == 3) return true;
    if (rolls.size() == 2 && !isStrike() && !isSpare()) return true;
    if (rolls.size() == 2 && (isStrike() || isSpare())) return false; //needs bonus
    return rolls.size() == 2 || isStrike(); 
}

std::vector<int> Frame::getRolls() const {
    return rolls;
}
