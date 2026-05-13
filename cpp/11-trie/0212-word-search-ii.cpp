#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
    struct TrieNode {
        TrieNode* children[26] = {nullptr};
        string word = "";
    };
    void insert(TrieNode* root, const string& w) {
        TrieNode* curr = root;
        for (char c : w) {
            int idx = c - 'a';
            if (!curr->children[idx]) curr->children[idx] = new TrieNode();
            curr = curr->children[idx];
        }
        curr->word = w;
    }
    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node, vector<string>& res) {
        char ch = board[r][c];
        if (ch == '#' || !node->children[ch - 'a']) return;
        node = node->children[ch - 'a'];
        if (!node->word.empty()) {
            res.push_back(node->word);
            node->word = "";
        }
        board[r][c] = '#';
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        for (auto& d : dirs) {
            int nr = r + d[0], nc = c + d[1];
            if (nr >= 0 && nc >= 0 && nr < board.size() && nc < board[0].size()) {
                dfs(board, nr, nc, node, res);
            }
        }
        board[r][c] = ch;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (const string& w : words) insert(root, w);
        vector<string> res;
        for (int r = 0; r < board.size(); ++r) {
            for (int c = 0; c < board[0].size(); ++c) {
                dfs(board, r, c, root, res);
            }
        }
        return res;
    }
};
