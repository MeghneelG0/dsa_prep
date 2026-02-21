
class Solution {
    int max_diameter = 0; // Our high score tracker

    int dfs(TreeNode* root) {
        if (!root) return 0;
        int leftdepth = dfs(root->left);
        int rightdepth = dfs(root->right);
        max_diameter = max(max_diameter, leftdepth + rightdepth);
        return 1 + max(leftDepth, rightDepth);
    }
    public:

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return max_diameter;
    }

};