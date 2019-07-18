
#include "exercise.h"
#include <climits>
#include <algorithm>

// ============================================================================

static void generateMatchedParensImpl(std::vector<std::string>& result,
                                      std::string&              validPattern,
                                      int                       numberOfPairs,
                                      int                       numberOfLeftParens,
                                      int                       numberOfExtraLeftParens)
{
    if ((numberOfLeftParens == numberOfPairs)
            && (numberOfExtraLeftParens == 0)) {
        result.push_back(validPattern);
        return;
    }

    if (numberOfLeftParens == numberOfPairs) {
        validPattern.push_back(')');
        generateMatchedParensImpl(result,
                                  validPattern,
                                  numberOfPairs,
                                  numberOfLeftParens,
                                  numberOfExtraLeftParens - 1);
        validPattern.pop_back();
    } else { // numberOfLeftParens < numberOfPairs
        validPattern.push_back('(');
        generateMatchedParensImpl(result,
                                  validPattern,
                                  numberOfPairs,
                                  numberOfLeftParens + 1,
                                  numberOfExtraLeftParens + 1);
        validPattern.pop_back();

        if (numberOfExtraLeftParens != 0) {
            validPattern.push_back(')');
            generateMatchedParensImpl(result,
                                      validPattern,
                                      numberOfPairs,
                                      numberOfLeftParens,
                                      numberOfExtraLeftParens - 1);
            validPattern.pop_back();
        }
    }
}

std::vector<std::string> Exercise::generateMatchedParens(int numberOfPairs)
{
    std::vector<std::string> result;
    std::string validPattern;
    generateMatchedParensImpl(result, validPattern, numberOfPairs, 0, 0);

    return result;
}

// ============================================================================

static bool isPalindome(const string& str)
{
    int i = 0;
    int j = str.size() - 1;

    while (i <= j) {
        if (str[i] != str[j]) {
            return false;
        }
        ++i;
        --j;
    }
    return true;
}

static void plindromicDecompositionsImpl(vector<vector<string>>& result, 
                                         vector<string>&         decomposition,
                                         const string&           input,
                                         int                     index)
{
    if (index >= input.size()) {
        result.push_back(decomposition);
        return;
    }

    for (int len = 1; len <= input.size() - index; ++len) {
        string prefix = input.substr(index, len); 
        if (isPalindome(prefix)) {
            decomposition.push_back(prefix);
            plindromicDecompositionsImpl(result, decomposition, input, index + len);
            decomposition.pop_back();
        }
    }
}

vector<vector<string>> Exercise::plindromicDecompositions(const string& input)
{
    vector<vector<string>> result;
    vector<string> decomposition;

    plindromicDecompositionsImpl(result, decomposition, input, 0);
    return result;
}




























