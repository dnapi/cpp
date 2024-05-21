#include <iostream>
#include <limits> // for std::numeric_limits

int main() {
    int value;

    while (true) {
        std::cout << "Enter an integer: ";

        // Read input
        std::cin >> value;

        // Check for EOF
        if (std::cin.eof()) {
            std::cout << "EOF encountered. Recovering the stream." << std::endl;
            // Clear the EOF state
            std::cin.clear(std::ios::eofbit);
            // Ignore remaining input
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        // Check for other errors
        if (std::cin.fail()) {
            std::cout << "Input error. Clearing and trying again." << std::endl;
            // Clear the error state
            std::cin.clear();
            // Ignore remaining input
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        // If input is successful
        std::cout << "You entered: " << value << std::endl;
    }

    return 0;
}
