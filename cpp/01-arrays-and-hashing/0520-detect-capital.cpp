class Solution {
public:
    bool detectCapitalUse(string word) {
        int capCount = 0;
        for (char c : word) {
            if (isupper(c)) ++capCount;
        }
        if (capCount == word.size() || capCount == 0) return true;
        if (capCount == 1 && isupper(word[0])) return true;
        return false;
    }
};
