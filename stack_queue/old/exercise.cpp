
#include "exercise.h"
#include <climits>
#include <algorithm>
#include <stack>

int Exercise::RPNExpression(const std::vector<std::string>& expression)
{
    std::stack<int> s;

    for (const auto& part : expression) {
        int num1, num2;
        if (part == "+") {
            num1 = s.top();
            s.pop();
            num2 = s.top();
            s.pop();
            s.push(num1 + num2);
        } else if (part == "-") {
            num1 = s.top();
            s.pop();
            num2 = s.top();
            s.pop();
            s.push(num1 - num2);
        } else if (part == "*") {
            num1 = s.top();
            s.pop();
            num2 = s.top();
            s.pop();
            s.push(num1 * num2);
        } else if (part == "/") {
            num1 = s.top();
            s.pop();
            num2 = s.top();
            s.pop();
            s.push(num1 / num2);
        } else {
            int num = std::stoi(part);
            s.push(num);
        }
    }
    return s.top();
}


bool Exercise::testWellFormedness(const std::vector<char>& input)
{
    return true;
}

std::string Exercise::normalizePathname(const std::string& path)
{
    return std::string();
}

std::vector<int> Exercise::sunsetViewEastToWest(const std::vector<int>& buildings)
{
    std::stack<int> s;

    for (int i = buildings.size() - 1; i >= 0; --i) {
        while (!s.empty() && buildings[i] > s.top()) {
            s.pop();
        }
        s.push(buildings[i]);
    }
    std::vector<int> result;
    while (!s.empty()) {
        result.push_back(s.top());
        s.pop();
    }
    return result;
}
















