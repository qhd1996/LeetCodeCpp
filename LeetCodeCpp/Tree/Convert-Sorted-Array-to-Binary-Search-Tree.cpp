//DFS
//Time Complexity O(n)
//Space Complexity O(logn)

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
     TreeNode* insert(int left, int right, vector<int>& v) {
       if (left > right)
			return NULL;
		else if (left == right)
			return new TreeNode(v[left]);
		int mid = left + (right - left) / 2;
		TreeNode* root = new TreeNode(v[mid]);
		root->left = insert(left, mid - 1, v);
		root->right = insert(mid + 1, right, v);
		return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return insert(0, nums.size()-1, nums);
    }
};
