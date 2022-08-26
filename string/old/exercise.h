#ifndef EXERCISE
#define EXERCISE

#include <iostream>
#include <vector>
#include "util.h"

class Exercise 
{
  public:
    static int stringToInteger(const std::string& number);
    static std::string integerToString(int number);
      // EPI, Problem 7.1, Page 86

    static std::string baseConverstion(const std::string& input,
                                       int                base1,
                                       int                base2);
      // EPI, Problem 7.2, Page 87

    static int spreadsheetColumnIdToInteger(const std::string& columnId);
      // EPI, Problem 7.3, Page 88 (similar to 7.2, essentially a base 26 problem)

    static void replaceAndRemove(std::vector<char>& input);
      // EPI, Problem 7.4, Page 89

    static bool isPalindrome(const std::string& input);
      // EPI, Problem 7.5, Page 90

    static void reverseWords(std::string& input);
      // EPI, Problem 7.6, Page 91 (skipped, seen many times)

    static std::vector<std::string> mnemonicsForPhoneNumber(const std::string& number);
      // EPI, Problem 7.7, Page 92

    static std::string lookAndSay(int n);
      // EPI, Problem 7.8, Page 93 (Skipped, too straight forward)

    static int convertRomanToDecimal(const std::string& romanNumber);
      // EPI, Problem 7.9, Page 94

    static std::vector<std::vector<int>> allValidIPAddresses(const std::string& input);
      // EPI, Problem 7.10, Page 95

    static std::string stringSinusoidal(const std::string& input);
      // EPI, Problem 7.11, Page 96

    static std::string runLengthEncode(const std::string& input);
    static std::string runLengthDecode(const std::string& input);
      // EPI, Problem 7.12, Page 97
};

#endif
