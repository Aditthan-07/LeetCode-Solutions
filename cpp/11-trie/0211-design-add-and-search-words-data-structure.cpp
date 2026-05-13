#include <string>
using namespace std;

class WordDictionary {
    struct Node {
        Node* children[26] = {nullptr};
        bool isWord = false;
    } root;
    bool searchInNode(const string& word, int idx, Node* node) {
        if (!node) return false;
        if (idx == word.size()) return node->isWord;
        char c = word[idx];
        if (c == '.') {
            for (int i = 0; i < 26; ++i) {
                if (node->children[i] && searchInNode(word, idx + 1, node->children[i])) return true;
            }
            return false;
        } else {
            return searchInNode(word, idx + 1, node->children[c - 'a']);
        }
    }
public:
    WordDictionary() {}
    void addWord(string word) {
        Node* curr = &root;
        for (char c : word) {
            int i = c - 'a';
            if (!curr->children[i]) curr->children[i] = new Node();
            curr = curr->children[i];
        }
        curr->isWord = true;
    }
    bool search(string word) {
        return searchInNode(word, 0, &root);
    }
};
