#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(static_cast<unsigned int>(std::time(0))); // Seed random number generator
    int secretNumber = std::rand() % 100 + 1; // Random number between 1 and 100
    int guess;
    int attempts = 7;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "Guess the number between 1 and 100." << std::endl;
    std::cout << "You have " << attempts << " chances to guess correctly." << std::endl;

    for (int i = 1; i <= attempts; ++i) {
        std::cout << "Attempt " << i << ": ";
        std::cin >> guess;

        if (guess > secretNumber) {
            std::cout << "Too high!" << std::endl;
        } else if (guess < secretNumber) {
            std::cout << "Too low!" << std::endl;
        } else {
            std::cout << "Congratulations! You guessed the number in " << i << " attempts." << std::endl;
            return 0;
        }
    }

    std::cout << "Sorry, you've used all your chances. The correct number was: " << secretNumber << std::endl;
    return 0;
}