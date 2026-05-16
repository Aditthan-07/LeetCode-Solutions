#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Solution {
    struct TrieNode {
        TrieNode* children[26] = {nullptr};
        bool isEnd = false;
    };
    void insert(TrieNode* root, const string& word) {
        TrieNode* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx]) curr->children[idx] = new TrieNode();
            curr = curr->children[idx];
        }
        curr->isEnd = true;
    }
    string findRoot(TrieNode* root, const string& word) {
        TrieNode* curr = root;
        string prefix = "";
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx]) return word;
            curr = curr->children[idx];
            prefix += c;
            if (curr->isEnd) return prefix;
        }
        return word;
    }
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        TrieNode* root = new TrieNode();
        for (const string& d : dictionary) insert(root, d);
        stringstream ss(sentence);
        string word, res = "";
        while (ss >> word) {
            if (!res.empty()) res += " ";
            res += findRoot(root, word);
        }
        return res;
    }
};
