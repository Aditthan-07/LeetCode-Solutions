#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (s.empty() || words.empty()) return res;
        int wordLen = words[0].size(), numWords = words.size();
        unordered_map<string, int> wordCount;
        for (const string& w : words) wordCount[w]++;
        for (int i = 0; i < wordLen; ++i) {
            int l = i, count = 0;
            unordered_map<string, int> curMap;
            for (int r = i; r + wordLen <= s.size(); r += wordLen) {
                string w = s.substr(r, wordLen);
                if (wordCount.count(w)) {
                    curMap[w]++;
                    count++;
                    while (curMap[w] > wordCount[w]) {
                        curMap[s.substr(l, wordLen)]--;
                        l += wordLen;
                        count--;
                    }
                    if (count == numWords) res.push_back(l);
                } else {
                    curMap.clear();
                    count = 0;
                    l = r + wordLen;
                }
            }
        }
        return res;
    }
};
