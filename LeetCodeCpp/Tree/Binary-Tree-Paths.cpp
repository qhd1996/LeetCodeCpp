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
    vector<string> paths;
    void DFS(TreeNode* node, string path){
        path += "->" + to_string(node->val);
        if(node->left == NULL && node->right == NULL)
            paths.push_back(path);
        else{
            if(node->left != NULL)
                DFS(node->left, path);
            if(node->right != NULL)
                DFS(node->right, path);
        }
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root != NULL)
        {
            DFS(root, "");
            for(int i = 0; i < paths.size(); i++)
                paths[i].erase(paths[i].begin(), paths[i].begin() + 2);
        }
        return paths;
    }
};
