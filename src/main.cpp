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

            int first = 0, second = 0, third = 0;
            do {
                if (first <= 10)
                    std::cout << "Enter first roll: ";
                else
                    std::cout << "Invalid Input! Number of pins cannot exceed 10.\nEnter first roll: ";
                std::cin >> first;
            } while (first > 10);
            game.roll(playerName, first);
            rollCount++;

            if (frame < 10) {
                if (first == 10) {
                    std::cout << "Strike! Moving to next frame." << std::endl;
                } else {
                    do {
                        if ((first + second) <= 10)
                            std::cout << "Enter second roll: ";
                        else
                            std::cout << "Total sum of a frame cannot be more than 10.\nEnter second roll: ";
                        std::cin >> second;
                    } while((first + second) > 10);
                    game.roll(playerName, second);
                    rollCount++;
                }
            } else {
                // 10th frame logic
                if (first == 10) {
                    std::cout << "Strike! Moving to the bonus roll!\n";
                } else {
                    std::cout << "Enter second roll: ";
                    std::cin >> second;
                    game.roll(playerName, second);
                    rollCount++;
                }

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