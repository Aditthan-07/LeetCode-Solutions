#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int dfs(TreeNode* node, int maxVal) {
        if (!node) return 0;
        int count = (node->val >= maxVal) ? 1 : 0;
        maxVal = max(maxVal, node->val);
        return count + dfs(node->left, maxVal) + dfs(node->right, maxVal);
    }
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};
