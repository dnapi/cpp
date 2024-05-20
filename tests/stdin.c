#include <iostream>
#include <limits>
#include <string>

int main() {
    std::string str;

    // Attempt to read a line
    std::cout << "Enter a line of text: ";
    if (!std::getline(std::cin, str)) {
        if (std::cin.eof()) {
            std::cout << "End-of-file reached." << std::endl;
        } else {
            std::cout << "Input error occurred." << std::endl;
        }

        // Clear the error flags
        std::cin.clear();

        // Ignore the rest of the input buffer (though usually not necessary after EOF)
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } else {
        std::cout << "You entered: " << str << std::endl;
    }

    // Attempt to read input again after clearing the stream
    std::cout << "Enter another line of text: ";
    if (std::getline(std::cin, str)) {
        std::cout << "You entered: " << str << std::endl;
    } else {
        std::cout << "Failed to read input again." << std::endl;
    }

    return 0;
}

