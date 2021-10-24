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
    void inorder(TreeNode* root, vector<int> & vec)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->left!=NULL)
        {
            inorder(root->left, vec);
        }
       // cout<<root->val;
        vec.push_back(root->val);
        if(root->right!=NULL)
        {
            inorder(root->right, vec);
        }
        
    }
    int kthSmallest(TreeNode* root, int k) 
    {
        vector<int> vec;
        inorder(root,vec);
        return vec[k-1];
        
    }
};
