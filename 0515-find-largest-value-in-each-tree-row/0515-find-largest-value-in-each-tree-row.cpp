/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    void helper(TreeNode* root, vector<int>& ans) {
        if (!root)
            return;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            int maxEl = INT_MIN;
            for (int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                q.pop();
                maxEl = max(maxEl, temp->val);
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            ans.push_back(maxEl);
        }
    }

public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        helper(root, ans);
        return ans;
    }
};