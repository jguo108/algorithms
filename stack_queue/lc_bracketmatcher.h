#include <string>
#include <stack>

namespace lc {

// Leetcode 20

class BracketMatcher
{
  private:
    std::string d_input;

  public:
    BracketMatcher(const std::string& input) : d_input(input) {}

    bool match();
};

inline
bool BracketMatcher::match()
{
    std::stack<char> st;

    for (auto c : d_input) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.empty()) {
                return false;
            }
            char top = st.top();
            if (c == ')') {
                if (top == '(') {
                    st.pop();
                } else {
                    return false;
                }
            } else if (c == ']') {
                if (top == '[') {
                    st.pop();
                } else {
                    return false;
                }
            } else if (c == '}') {
                if (top == '{') {
                    st.pop();
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
        return st.empty();

    }
}

}