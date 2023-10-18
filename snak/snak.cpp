#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>

// Game settings
const int BoardSize = 16;
const char BorderChar = '#';
const char SnakeChar = 'o';
const char AppleChar = 'g';
const int MaxApples = 100;

// Function to print the game board
void printBoard(int score, int snakeX, int snakeY, int appleX, int appleY) {
    std::cout << "Score: " << score << std::endl;
    for (int i = 0; i < BoardSize + 2; ++i) {
        std::cout << BorderChar;
    }
    std::cout << std::endl;

    for (int i = 0; i < BoardSize; ++i) {
        std::cout << BorderChar;
        for (int j = 0; j < BoardSize; ++j) {
            if (i == snakeY && j == snakeX) {
                std::cout << SnakeChar;
            } else if (i == appleY && j == appleX) {
                std::cout << AppleChar;
            } else {
                std::cout << " ";
            }
        }
        std::cout << BorderChar << std::endl;
    }

    for (int i = 0; i < BoardSize + 2; ++i) {
        std::cout << BorderChar;
    }
    std::cout << std::endl;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    std::cout << "SNAK" << std::endl;
    std::cout << "Start game? [Y/n]: ";
    char choice;
    std::cin >> choice;

    if (choice == 'Y' || choice == 'y') {
        int score = 0;
        int snakeX = BoardSize / 2;
        int snakeY = BoardSize / 2;
        int appleX = rand() % BoardSize;
        int appleY = rand() % BoardSize;

        // Main game loop
        while (score < MaxApples) {
            // Print the game board
            printBoard(score, snakeX, snakeY, appleX, appleY);

            // Get the user input for direction
            std::cout << "Enter direction (1: up, 2: down, 3: left, 4: right): ";
            int direction;
            std::cin >> direction;

            // Update the snake's position based on the user's input
            if (direction == 1) {
                // Move up
                snakeY--;
            } else if (direction == 2) {
                // Move down
                snakeY++;
            } else if (direction == 3) {
                // Move left
                snakeX--;
            } else if (direction == 4) {
                // Move right
                snakeX++;
            } else {
                std::cout << "Invalid direction. Please try again." << std::endl;
                continue;
            }

            // Check for collisions with the walls
            if (snakeX < 0 || snakeX >= BoardSize || snakeY < 0 || snakeY >= BoardSize) {
                std::cout << "Game over! You hit the wall." << std::endl;
                break;
            }

            // Check if the snake has reached the apple
            if (snakeX == appleX && snakeY == appleY) {
                // Increment the score
                score++;

                // Generate a new random apple
                appleX = rand() % BoardSize;
                appleY = rand() % BoardSize;
            }

            // Check for the game-over condition
            if (score >= MaxApples) {
                std::cout << "Congratulations! You won the game." << std::endl;
                std::ifstream flagFile("flag.txt");
                if (flagFile.is_open()) {
                    std::string flag;
                    flagFile >> flag;
                    std::cout << "Here's the flag: " << flag << std::endl;
                    flagFile.close();
                } else {
                    std::cout << "Flag file not found." << std::endl;
                }
                break;
            }
        }
    } else {
        std::cout << "Game stopped." << std::endl;
    }

    return 0;
}
