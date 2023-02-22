#include <stdexcept>
#include <stack>

using namespace std;

class StackReverser 
{
  public:
    void reverse(stack<int>& st);

  private:
    int getAndRemoveBottomElement(stack<int>& st);
};

void StackReverser::reverse(stack<int>& st)
{
    if (st.empty()) {
        return;
    }
    int value = getAndRemoveBottomElement(st);
    reverse(st);
    st.push(value);
}

int StackReverser::getAndRemoveBottomElement(stack<int>& st)
{
    if (st.size() == 1) {
        int value = st.top();
        st.pop();
        return value;
    }

    int value = st.top();
    st.pop();
    int last_element = getAndRemoveBottomElement(st);
    st.push(value);
    return last_element;
}