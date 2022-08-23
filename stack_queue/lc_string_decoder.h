#include <string>
#include <stack>

namespace lc
{

// Leetcode 394

// TODO

class StringDecoder
{
  public:
    static std::string decode(std::string input) {
        std::string result;
        std::stack<int> nums;
        std::stack<std::string> strings;

        for (auto c : input) {
            if (isdigit(c)) {
                nums.push(c - 48);
            } else if (c == ']') {
                int repetition = nums.top();
                nums.pop();

                std::string current_string = strings.top();
                strings.pop();
                while (current_string != "[") {


                    current_string = strings.top();
                    strings.pop();
                }
            } else {
                strings.push(std::string(1, c));
            }

        }

        return result;
    }
};

}