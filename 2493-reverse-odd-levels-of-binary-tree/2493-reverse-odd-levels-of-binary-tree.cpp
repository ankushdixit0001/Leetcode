/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
    void helper(TreeNode* leftNode, TreeNode* rightNode, int level){
        if(!leftNode||!rightNode){
            return;  
        } 
        if(level%2){
            swap(leftNode->val,rightNode->val);
        } 
        helper(leftNode->left,rightNode->right,level+1);
        helper(leftNode->right,rightNode->left,level+1);
    }
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        helper(root->left,root->right,1);
        return root;
    }
};