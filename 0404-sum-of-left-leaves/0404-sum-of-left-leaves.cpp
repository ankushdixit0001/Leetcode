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
    int leftSum(TreeNode* root,bool isLeft){
    if(root==NULL){
        return 0;
    }
    if(!root->left&&!root->right&&isLeft){
        return root->val;
    }
    return leftSum(root->left,true)+leftSum(root->right,false);
}
public:
    int sumOfLeftLeaves(TreeNode* root) {
    return leftSum(root,false);
    }
};