#ifndef EXERCISE
#define EXERCISE

#include <iostream>
#include <vector>

using namespace std;

class Exercise 
{
  public:
    static vector<string> generateMatchedParens(int numberOfPairs);
      // EPI, Problem 16.6, Page 262

    static vector<vector<string>> plindromicDecompositions(const string& input);
};

#endif
