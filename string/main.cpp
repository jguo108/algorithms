#include <iostream>
#include <vector>

#include "exercise.h"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Usage: a.out case" << std::endl;
        return -1;
    }

    long testCase = strtol(argv[1], NULL, 0);

    switch (testCase) {
        case 1: { // String/Integer conversion 
            std::string number = "123";
            int result = Exercise::stringToInteger(number); 
            std::cout << "Result is: " << result << std::endl;
        } break;
        case 2: { // Base conversion 
            std::string result = Exercise::baseConverstion("615", 7, 13); 
            std::cout << "Result is: " << result << std::endl;
        } break;
        case 3: { // Spreadsheet column id to integer
            std::cerr << "Not implemented" << std::endl;
        } break;
        case 4: { // Replace and remove
            std::vector<char> input = { 'a', 'b', 'b', 'c', 'd', 'a', 'b', 'a', 'c', 'd', 'b' };
            Exercise::replaceAndRemove(input);
            Util::print(input);
        } break;
        case 5: { // Is palindrome
            std::string input = "A man, a plan, a canal, Panama";
            std::cout << "Is palindrome: " << Exercise::isPalindrome(input) << std::endl;
        } break;
        case 6: { // Reverse words
            std::cerr << "Not implemented" << std::endl;
        } break;
        case 7: { // Mnemonics for phone number
            std::string input = "234";
            std::vector<std::string> result = Exercise::mnemonicsForPhoneNumber(input);
            Util::print(result);
        } break;
        case 8: { // Look and day
            std::cerr << "Not implemented" << std::endl;
        } break;
        case 9: { // Convert Roman to decimal 
            std::string romanNumber = "LIX";
            std::cout << "Number is: " << Exercise::convertRomanToDecimal(romanNumber) << std::endl;
        } break;
        case 10: { // All valid ip addresses
            std::string input = "19216811";
            std::vector<std::vector<int>> result = Exercise::allValidIPAddresses(input);
            for (const auto& ipAddress : result) {
                Util::print(ipAddress);
            }
        } break;
        case 11: { // String sinusoidal
            std::string input = "Hello World!";
            std::cout << Exercise::stringSinusoidal(input) << std::endl;
        } break;
        case 12: { // Run-length encode/decode
            std::string input = "aaaabcccaa";
            std::cout << Exercise::runLengthEncode(input) << std::endl;
        } break;
        default: {
            std::cerr << "Unknown test case" << std::endl;
        } break;

    }

    return 0;
}

