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
public:
    int MOD = 1e9 + 7;
    vector<int> currSum;
    int treeSum(TreeNode* root, int sum) {
        if (!root) return 0;
        sum = root->val + treeSum(root->left, sum) + treeSum(root->right, sum);
        currSum.push_back(sum);
        return sum;
    }
    int maxProduct(TreeNode* root) {
        int total = treeSum(root, 0);
        long long maxi = LLONG_MIN;
        for(int i = 0; i < currSum.size(); i++) {
            long long prod = 1LL * (total - currSum[i]) * currSum[i];
            maxi = max(maxi, prod);
        }
        return maxi % MOD;
    }
};