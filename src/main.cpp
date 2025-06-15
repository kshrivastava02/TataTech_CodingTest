#include <iostream>
#include <string>
#include <vector>
#include "BowlingGame.h"

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

            int first, second = 0, third = 0;
            std::cout << "Enter first roll: ";
            std::cin >> first;
            game.roll(playerName, first);
            rollCount++;

            if (frame < 10) {
                if (first == 10) {
                    std::cout << "Strike! Moving to next frame." << std::endl;
                } else {
                    std::cout << "Enter second roll: ";
                    std::cin >> second;
                    game.roll(playerName, second);
                    rollCount++;
                }
            } else {
                // 10th frame logic
                std::cout << "Enter second roll: ";
                std::cin >> second;
                game.roll(playerName, second);
                rollCount++;

                if (first == 10 || (first + second) == 10) {
                    std::cout << "Bonus roll for strike or spare: ";
                    std::cin >> third;
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
