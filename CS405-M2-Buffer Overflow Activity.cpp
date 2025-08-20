// BufferOverflow.cpp : This file contains the 'main' function. Program execution begins and ends there.
/// Sources used: https://medium.com/@AlexanderObregon/secure-coding-practices-in-c-12b756af90fe
#include <iomanip>
#include <iostream>
#include <cstring>
#include <string>

int main()
{
    std::cout << "Buffer Overflow Example" << std::endl;

    // TODO: The user can type more than 20 characters and overflow the buffer, resulting in account_number being replaced -
    //  even though it is a constant and the compiler buffer overflow checks are on.
    //  You need to modify this method to prevent buffer overflow without changing the account_number
    //  variable, and its position in the declaration. It must always be directly before the variable used for input.
    //  You must notify the user if they entered too much data.

    const std::string account_number = "CharlieBrown42";
    char user_input[20]; // 20 is arbitrary. We need it low enough to test.

    // A while line for the user to try.
    while (true) {
        // Not sure if telling the user the max is truly the 'best' pratice.
        std::cout << "Enter a value (max " << sizeof(user_input) - 1 << " characters): ";

        // Get the line from the character input with the max amount of chars being user_input.
        std::cin.getline(user_input, sizeof(user_input));

        // Check for overflow: if the input was too long
        if (std::cin.fail()) {
            std::cin.clear(); // Clear 

            // Discard the rest of the line
            std::string discard;
            std::getline(std::cin, discard);
            std::cout << "Input too long. Please enter up to " << sizeof(user_input) - 1 << " characters.\n";

        }
        else {
            std::cout << "You entered: " << user_input << '\n';
            std::cout << "Account Number = " << account_number << std::endl;
            break;
        }
    }
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
