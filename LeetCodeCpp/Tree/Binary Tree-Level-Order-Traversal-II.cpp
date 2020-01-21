//DFS
//Time Complexity O(n)
//Space Complexity O(n)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;
        
        if (!root)
            return res;
        
        q.push(root);
        
        while (!q.empty()) {
            auto size = q.size();
            vector<int> v;

            for (auto i = 0; i < size; i++) {
                TreeNode *tmp = q.front();
                q.pop();

                v.push_back(tmp->val);
                
                if (tmp->left)
                    q.push(tmp->left);
                
                if (tmp->right)
                    q.push(tmp->right);
            }
            res.push_back(v);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
