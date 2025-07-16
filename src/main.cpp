#include <iostream>
#include <string>
#include <vector>
#include "BowlingGame.h"
#include <limits>

int getValidRoll(const std::string& promt, int max = 10) {
    int roll;
    while (true) {
        std::cout << promt;
        std::cin >> roll;

        if (std::cin.fail() || roll < 0 || roll > max) {
            std::cout << "Invalid input, please enter a number between 0 and " << max << ".\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            return roll;
        }
    }
}

int main() {
    BowlingGame game;
    std::string playerName;

    std::cout << "Enter player name: ";
    std::getline(std::cin, playerName);

    try {
        game.addPlayer(playerName);

        int rollCount = 0;
        int frame = 1;

        while (frame <= 10) {
            std::cout << "\nFrame " << frame << std::endl;

            int first = 0, second = 0, third = 0;
            first = getValidRoll("Enter first roll: ", 10);
            game.roll(playerName, first);
            rollCount++;

            if (frame < 10) {
                if (first == 10) {
                    std::cout << "Strike! Moving to next frame." << std::endl;
                } else {
                    second = getValidRoll("Enter second roll: ", 10-first);
                    game.roll(playerName, second);
                    rollCount++;
                }
            } else {
                // 10th frame logic
                if (first == 10) {
                    std::cout << "Strike! Moving to the bonus roll!\n";
                } else {
                    second = getValidRoll("Enter second roll: ", 10-first);
                    game.roll(playerName, second);
                    rollCount++;
                }

                if (first == 10 || (first + second) == 10) {
                    third = getValidRoll("Bonus roll for strike or spare: ");
                    game.roll(playerName, third);
                    rollCount++;
                }
            }

            frame++;
        }

        std::cout << "\nFinal score for " << playerName << ": " << game.getScore(playerName) << std::endl;
    }
    catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }

    return 0;
}