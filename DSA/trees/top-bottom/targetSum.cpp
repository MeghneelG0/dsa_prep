class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // 1. Base Case (Dead end)
        if (!root) return false;
        
        // 2. Leaf Check (Am I a leaf? If yes, check the math)
        if (!root->left && !root->right) {
            return targetSum == root->val; 
            // (or targetSum - root->val == 0, same thing!)
        }
        
        // 3, 4, & 5. Pass the backpack down and OR them together
        return hasPathSum(root->left, targetSum - root->val) || 
               hasPathSum(root->right, targetSum - root->val);
    }
};