class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxLen = 0, curr = 0;
        for (int x : nums) {
            if (x == 1) maxLen = max(maxLen, ++curr);
            else curr = 0;
        }
        return maxLen;
    }
};
