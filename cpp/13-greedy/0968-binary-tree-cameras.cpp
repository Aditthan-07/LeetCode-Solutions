struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    int cameras = 0;
    // 0: uncovered, 1: covered by camera, 2: has camera
    int dfs(TreeNode* node) {
        if (!node) return 1;
        int l = dfs(node->left), r = dfs(node->right);
        if (l == 0 || r == 0) {
            cameras++;
            return 2;
        }
        if (l == 2 || r == 2) return 1;
        return 0;
    }
public:
    int minCameraCover(TreeNode* root) {
        if (dfs(root) == 0) cameras++;
        return cameras;
    }
};
