#include <string>
#include <stack>
#include <cctype>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> countSt;
        stack<string> strSt;
        string curStr = "";
        int k = 0;
        for (char c : s) {
            if (isdigit(c)) {
                k = k * 10 + (c - '0');
            } else if (c == '[') {
                countSt.push(k);
                strSt.push(curStr);
                k = 0;
                curStr = "";
            } else if (c == ']') {
                int repeat = countSt.top(); countSt.pop();
                string prev = strSt.top(); strSt.pop();
                while (repeat--) prev += curStr;
                curStr = prev;
            } else {
                curStr += c;
            }
        }
        return curStr;
    }
};
