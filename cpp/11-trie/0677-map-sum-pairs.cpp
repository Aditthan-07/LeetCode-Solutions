#include <string>
#include <unordered_map>
using namespace std;

class MapSum {
    struct TrieNode {
        TrieNode* children[26] = {nullptr};
        int val = 0;
    } root;
    unordered_map<string, int> map;
public:
    MapSum() {}
    void insert(string key, int val) {
        int diff = val - map[key];
        map[key] = val;
        TrieNode* curr = &root;
        for (char c : key) {
            int idx = c - 'a';
            if (!curr->children[idx]) curr->children[idx] = new TrieNode();
            curr = curr->children[idx];
            curr->val += diff;
        }
    }
    int sum(string prefix) {
        TrieNode* curr = &root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (!curr->children[idx]) return 0;
            curr = curr->children[idx];
        }
        return curr->val;
    }
};
