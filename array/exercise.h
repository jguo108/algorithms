#ifndef EXERCISE
#define EXERCISE

#include <iostream>
#include <vector>

class Exercise 
{
  public:
    static void dutchFlag(std::vector<int>& array, int pivotIdx);
      // EPI, Problem 6.1, Page 56
    
    static void integerPlusOne(std::vector<int>& number);
      // EPI, Problem 6.2, Page 59

    static void multiplyTwoIntegers(std::vector<int>& number1,
                                    std::vector<int>& number2);
      // EPI, Problem 6.3, Page 60 (Uncompleted)

    static bool advanceThroughArray(std::vector<int>& input);
      // EPI, Problem 6.4, Page 61

    static void deleteRepeatedElementsInSortedArray(std::vector<int>& input);
      // EPI, Problem 6.5, Page 62

    static int buyAndSellStockOnce(std::vector<int>& input);
      // EPI, Problem 6.6, Page 63

    static int buyAndSellStockTwice(std::vector<int>& input);
      // EPI, Problem 6.7, Page 64 (Uncompleted)

    static std::vector<int> enumerateAllPrimes(int n);
      // EPI, Problem 6.8, Page 65

    static void permuteArray(std::vector<char>& input,
                             std::vector<int>&  permutation);
      // EPI, Problem 6.9, Page 67

    static bool nextPermutation(std::vector<int>& input);
      // EPI, Problem 6.10, Page 69

    // 6.11 to 6.15 are about random numbers. Skip for now and will re-visit
    // later


};

#endif
