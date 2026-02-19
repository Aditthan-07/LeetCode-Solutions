#include <stack>
#include <algorithm>
using namespace std;

class MinStack {
    stack<pair<int, int>> st;
public:
    MinStack() {}
    void push(int val) {
        int curMin = st.empty() ? val : min(val, st.top().second);
        st.push({val, curMin});
    }
    void pop() {
        st.pop();
    }
    int top() {
        return st.top().first;
    }
    int getMin() {
        return st.top().second;
    }
};
