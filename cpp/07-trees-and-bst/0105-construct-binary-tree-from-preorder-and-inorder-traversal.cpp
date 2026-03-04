#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    unordered_map<int, int> inMap;
    int preIdx = 0;
    TreeNode* build(const vector<int>& preorder, int l, int r) {
        if (l > r) return nullptr;
        int val = preorder[preIdx++];
        TreeNode* root = new TreeNode(val);
        int mid = inMap[val];
        root->left = build(preorder, l, mid - 1);
        root->right = build(preorder, mid + 1, r);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i = 0; i < inorder.size(); ++i) inMap[inorder[i]] = i;
        return build(preorder, 0, inorder.size() - 1);
    }
};
