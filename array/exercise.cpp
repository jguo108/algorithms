
#include "exercise.h"
#include <climits>
#include <algorithm>

void Exercise::dutchFlag(std::vector<int>& array, int pivotIdx)
{
    if (pivotIdx < 0 || pivotIdx >= array.size()) {
        return;
    }

    int pivot = array[pivotIdx];
    size_t left = 0;
    size_t right = array.size() - 1;
    size_t equal = 0;

    while (true) {
        while (array[left] <= pivot && left <= right) {
            if (array[left] < pivot) {
                std::swap(array[left], array[equal]);
                ++equal;
            }
            ++left;
        }
        while (array[right] > pivot && right >= left) {
            --right;
        }

        if (left > right) {
            break;
        }
        std::swap(array[left], array[right]);
    }
}


void Exercise::integerPlusOne(std::vector<int>& number)
{

    std::reverse_iterator<std::vector<int>::iterator> cur = number.rbegin();
    std::reverse_iterator<std::vector<int>::iterator> end= number.rend();

    int carry = 1;
    int newDigit = 0;

    for(; cur != end; ++cur) {
        newDigit = *cur + carry;
        if (newDigit == 10) {
            newDigit = 0;
            carry = 1;
        } else {
            carry = 0;
        }
        *cur = newDigit;
    }

    if (carry == 1) {
        number[0] = 1;
        number.push_back(0);
    }
}

bool Exercise::advanceThroughArray(std::vector<int>& input)
{
    int dist = 1;
    bool possible = false;

    for (int i = input.size() - 2; i >= 0; --i) {
        if (input[i] >= dist) {
            dist = 0;
            possible = true;
        } else {
            possible = false;
        }
        ++dist;
    }

    return possible;
}


void Exercise::deleteRepeatedElementsInSortedArray(std::vector<int>& input)
{
    int size = input.size();

    if (size == 1) {
        return;
    }

    int i = 0;
    int j = 1;

    while (j < size) {
        if (input[i] == input[j]) {
            ++j;
        } else {
            ++i;
            input[i] = input[j];
            ++j;
        }
    }
    for (int k = ++i; k < size; ++k) {
        input[k] = 0;
    }
}


int Exercise::buyAndSellStockOnce(std::vector<int>& input)
{
    int size = input.size();
    int maxElem = input[size - 1];
    int maxProfit = 0;

    for (int i = size - 2; i >= 0; --i) {
        if (input[i] < maxElem) {
            int profit = maxElem - input[i];
            if (profit > maxProfit) {
                maxProfit = profit;
            }
        } else {
            maxElem = input[i];
        }
    }

    return maxProfit;
}

std::vector<int> Exercise::enumerateAllPrimes(int n)
{
    std::vector<int> allNumbers;
    std::vector<int> primes;

    allNumbers.reserve(n + 1);

    for (int i = 2; i <= n; ++i) {
        allNumbers[i] = i;
    }

    for (int i = 2; i <= n; ++i) {
        if (i * (i + 1) > n) {
            break;
        }
        for (int j = i + 1; j <= n; ++j) {
            int index = i * j;
            if (index <= n) {
                allNumbers[index] = 0;
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        if (allNumbers[i] != 0) {
            primes.push_back(i);
        }
    }

    return primes;
}

void Exercise::permuteArray(std::vector<char>& input,
                            std::vector<int>&  permutation)
{
    for (int i = 0; i < permutation.size(); ++i) {
        if (permutation[i] < 0) {
            continue;
        }
        int moveToIndex = permutation[i];
        char toMoveElement = input[i];
        while (permutation[moveToIndex] >= 0) {
            int moveToElement = input[moveToIndex];
            input[moveToIndex] = toMoveElement;
            int nextMoveToIndex = permutation[moveToIndex];
            permutation[moveToIndex] = -1;
            moveToIndex = nextMoveToIndex;
            toMoveElement = moveToElement;
        }
    }
}

bool Exercise::nextPermutation(std::vector<int>& input)
{
    std::vector<int>::reverse_iterator it = input.rbegin();

    for (; it != input.rend() - 1; ++it) {
        if (*it > *(it + 1)) {
            break;
        }
    }

    if (it == input.rend() - 1) {
        // The permutation is the last one
        return false;
    }

    int target = *(it + 1);
    std::vector<int>::reverse_iterator firstGreaterThan
        = std::find_if(input.rbegin(),
                       it + 1,
                       [&target](int arg) { return arg > target; });

    std::swap(*(it + 1), *firstGreaterThan);

    std::reverse(input.rbegin(), it + 1);

    return true;
}




























































































