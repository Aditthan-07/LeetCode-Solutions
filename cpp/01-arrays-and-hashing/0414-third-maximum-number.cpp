class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> top3;
        for (int x : nums) {
            top3.insert(x);
            if (top3.size() > 3) {
                top3.erase(top3.begin());
            }
        }
        return top3.size() == 3 ? *top3.begin() : *top3.rbegin();
    }
};
