class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<unordered_set<char>> rows = {
            {'q','w','e','r','t','y','u','i','o','p'},
            {'a','s','d','f','g','h','j','k','l'},
            {'z','x','c','v','b','n','m'}
        };
        vector<string> res;
        for (string& w : words) {
            int rowIdx = -1;
            char first = tolower(w[0]);
            for (int r = 0; r < 3; ++r) {
                if (rows[r].count(first)) { rowIdx = r; break; }
            }
            bool ok = true;
            for (char c : w) {
                if (!rows[rowIdx].count(tolower(c))) { ok = false; break; }
            }
            if (ok) res.push_back(w);
        }
        return res;
    }
};
