#include <string>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Codec {
    void serializeDfs(TreeNode* node, stringstream& ss) {
        if (!node) { ss << "# "; return; }
        ss << node->val << " ";
        serializeDfs(node->left, ss);
        serializeDfs(node->right, ss);
    }
    TreeNode* deserializeDfs(stringstream& ss) {
        string val;
        ss >> val;
        if (val == "#") return nullptr;
        TreeNode* node = new TreeNode(stoi(val));
        node->left = deserializeDfs(ss);
        node->right = deserializeDfs(ss);
        return node;
    }
public:
    string serialize(TreeNode* root) {
        stringstream ss;
        serializeDfs(root, ss);
        return ss.str();
    }
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserializeDfs(ss);
    }
};
