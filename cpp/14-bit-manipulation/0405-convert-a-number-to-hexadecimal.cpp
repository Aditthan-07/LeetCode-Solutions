#include <string>
using namespace std;

class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        string hexDigits = "0123456789abcdef", res = "";
        unsigned int n = num;
        while (n > 0) {
            res = hexDigits[n & 0xf] + res;
            n >>= 4;
        }
        return res;
    }
};
