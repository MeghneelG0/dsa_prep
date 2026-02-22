class Solution {
    bool is_balanced = true; 

    int dfs(TreeNode* node) {
        if (!node) return 0;
        
        int leftDepth = dfs(node->left);
        int rightDepth = dfs(node->right);
        
        if (abs(leftDepth - rightDepth) > 1) {
            is_balanced = false;
        }
        
        return 1 + max(leftDepth, rightDepth);
    }

public:
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return is_balanced;
    }
};