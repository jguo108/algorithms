#include "exercise.h"
#include "util.h"
#include <climits>
#include <algorithm>

#include <set>
#include <map>

// 7.1
int Exercise::stringToInteger(const std::string& number)
{
    int end = 0;
    if (number[0] == '-') {
        end = 1;
    }

    int size = number.size();
    int result = 0;
    int multiplier = 1;
    for(int i = size - 1; i >= end; --i) {
        int digit = number[i] - 48; 
        result += digit * multiplier;
        multiplier *= 10;
    }
    if (end == 1) {
        result *= -1;
    }
    return result;
}

std::string Exercise::integerToString(int number)
{
    return std::string();
}

// 7.2
static int charToDigit(char c)
{
    switch (c) {
      case 'A':
        return 10;
      case 'B':
        return 11;
      case 'C':
        return 12;
      case 'D':
        return 13;
      case 'E':
        return 14;
      case 'F':
        return 15;
      default:
        return c - 48;
    }
}

static char digitToChar(int d)
{
    switch (d) {
      case 10:
        return 'A';
      case 11:
        return 'B';
      case 12:
        return 'C';
      case 13:
        return 'D';
      case 14:
        return 'E';
      case 15:
        return 'F';
      default:
        return 48 + d;
    }
}

std::string Exercise::baseConverstion(const std::string& input,
                                      int                base1,
                                      int                base2)
{
    int base1Number = 0;
    int multiplier = 1;

    for (int i = input.size() - 1; i >= 0; --i) {
        int digit = charToDigit(input[i]);
        base1Number += digit * multiplier; 
        multiplier *= base1;
    }


    std::string result;
    while (base1Number > 0) {
        int digit = base1Number % base2; 
        result.push_back(digitToChar(digit));
        base1Number /= base2;
    }

    std::reverse(result.begin(), result.end());

    return result;
}

// 7.3
int Exercise::spreadsheetColumnIdToInteger(const std::string& columnId)
{
    return 0;
}

// 7.4
void Exercise::replaceAndRemove(std::vector<char>& input)
{
    int oldSize = input.size();
    int newSize = input.size();
    int bsRemoved = 0;

    int i = 0;
    int j = 0;
    while(j < oldSize) {
        while(j < oldSize && input[j] == 'b') {
            --newSize;
            ++bsRemoved;
            ++j;
        }
        if (j != oldSize) {
            input[i] = input[j];
        }
        if (input[j] == 'a') {
            ++newSize;
        }
        ++i;
        ++j;
    }

    for (int i = oldSize - bsRemoved - 1, j = newSize - 1; i >= 0; --i) {
        if (input[i] == 'a') {
            input[j--] = 'd';
            input[j--] = 'd';
        } else {
            input[j--] = input[i];
        }
    }
}

// 7.5
bool Exercise::isPalindrome(const std::string& input)
{
    int i = 0;
    int j = input.size() - 1;

    while (i < j) {
        while (!isalnum(input[i]) && i < j) {
            ++i;
        }
        while (!isalnum(input[j]) && j > i) {
            --j;
        }
        if (tolower(input[i]) != tolower(input[j])) {
            return false;
        }
        ++i;
        --j;
    }
    return true;
}

// 7.6
void Exercise::reverseWords(std::string& input)
{
}

// 7.7
static std::map<char, std::set<char>> keyPad =
{
    {'2', {'A', 'B', 'C'}},
    {'3', {'D', 'E', 'F'}},
    {'4', {'G', 'H', 'I'}},
    {'5', {'J', 'K', 'L'}},
    {'6', {'M', 'N', 'O'}},
    {'7', {'P', 'Q', 'R', 'S'}},
    {'8', {'T', 'U', 'V'}},
    {'9', {'W', 'X', 'Y', 'Z'}}
};

static void mnemonicsForPhoneNumberImpl(std::vector<std::string>& result,
                                        const std::string&        number,
                                        int                       index,
                                        std::string&              mnemonic)
{
    if (index == number.size()) {
        result.push_back(mnemonic);
        return;
    }

    char digit = number[index];
    const std::set<char>& charSet = keyPad[digit];

    for (std::set<char>::iterator
            cur = charSet.begin(),
            end = charSet.end(); cur != end; ++cur) {
        mnemonic.push_back(*cur);
        mnemonicsForPhoneNumberImpl(result, number, index + 1, mnemonic);
        mnemonic.pop_back();
    }
}

std::vector<std::string> Exercise::mnemonicsForPhoneNumber(
                                                     const std::string& number)
{
    std::vector<std::string> result;
    std::string mnemonic;

    mnemonicsForPhoneNumberImpl(result, number, 0, mnemonic);

    return result;
}

// 7.8
std::string Exercise::lookAndSay(int n)
{
    return std::string();
}

// 7.9
static std::map<char, int> romanSymbols =
{
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
};

int Exercise::convertRomanToDecimal(const std::string& romanNumber)
{
    int result = 0;

    for (int i = 0; i < romanNumber.size(); ++i) {
        if (i == romanNumber.size() - 1
                || romanSymbols[romanNumber[i]]
                    >= romanSymbols[romanNumber[i+1]]) {
            result += romanSymbols[romanNumber[i]];
        } else {
            result -= romanSymbols[romanNumber[i]];
        }
    }
    return result;
}

// 7.10

static void allValidIPAddressesImpl(std::vector<std::vector<int>>& result,
                                    const std::string&             input,
                                    std::vector<int>&              ipAddress,
                                    int                            index) 
{
    if (ipAddress.size() == 4) {
       if (index == input.size()) {
           result.push_back(ipAddress);
       }
       return;
    }

    int end = std::min(index + 2, static_cast<int>(input.size() - 1));

    for (int i = index; i <= end; ++i) {
        int part = std::stoi(input.substr(index, i - index + 1));
        if (part <= 255) {
            ipAddress.push_back(part);
            allValidIPAddressesImpl(result, input, ipAddress, i + 1);
            ipAddress.pop_back();
        }
    }
}

std::vector<std::vector<int>> Exercise::allValidIPAddresses(const std::string& input)
{
    std::vector<std::vector<int>> result;

    std::vector<int> ipAddress;
    allValidIPAddressesImpl(result, input, ipAddress, 0);

    return result;
}

// 7.11
std::string Exercise::stringSinusoidal(const std::string& input)
{
    std::string result;

    for (int i = 1; i < input.size(); i += 4) {
        result.push_back(input[i]);
    }

    for (int i = 0; i < input.size(); i += 2) {
        result.push_back(input[i]);
    }

    for (int i =3; i < input.size(); i += 4) {
        result.push_back(input[i]);
    }

    return result;
}

// 7.12
std::string Exercise::runLengthEncode(const std::string& input)
{
    std::string result;

    int i = 0;
    int j = 0;
    while (j < input.size()) {
        if (input[i] != input[j]) {
            result.push_back(j - i + 48);
            result.push_back(input[i]);
            i = j;
        }
        ++j;
    }
    result.push_back(j - i + 48);
    result.push_back(input[i]);

    return result;
}

std::string Exercise::runLengthDecode(const std::string& input)
{
    std::string result;

    return result;
}




















































