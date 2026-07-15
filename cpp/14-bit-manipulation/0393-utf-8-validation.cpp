#include <vector>
using namespace std;

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int nBytes = 0;
        for (int num : data) {
            int byte = num & 0xFF;
            if (nBytes == 0) {
                if ((byte >> 5) == 0b110) nBytes = 1;
                else if ((byte >> 4) == 0b1110) nBytes = 2;
                else if ((byte >> 3) == 0b11110) nBytes = 3;
                else if ((byte >> 7) != 0b0) return false;
            } else {
                if ((byte >> 6) != 0b10) return false;
                nBytes--;
            }
        }
        return nBytes == 0;
    }
};
