struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int dfs(TreeNode* root, int sum) {
        if (!root) return 0;
        sum = sum * 10 + root->val;
        if (!root->left && !root->right) return sum;
        return dfs(root->left, sum) + dfs(root->right, sum);
    }
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};
