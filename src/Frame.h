#ifndef FRAME_H
#define FRAME_H

#include <vector>

class Frame {
public:
    Frame();
    void addRoll(int pins);
    int getScore() const;
    bool isStrike() const;
    bool isSpare() const;
    bool isComplete() const;
    std::vector<int> getRolls() const;

private:
    std::vector<int> rolls;
};

#endif
