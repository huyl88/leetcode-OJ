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
    void inOrderTraversal(TreeNode* root, vector<int>& inorder)
    {
        if(root != NULL)
        {
            inOrderTraversal(root->left, inorder);
            inorder.push_back(root->val);
            inOrderTraversal(root->right, inorder);
        }
    }
    bool isValidBST(TreeNode* root) {
       vector<int> inorder;
       inOrderTraversal(root, inorder);
       if(inorder.size() == 0) return true;
       for(vector<int>::iterator it = inorder.begin(), it1 = it+1; it1 != inorder.end(); it++, it1++)
       {
           if(*it >= *it1) return false;
       }
       return true;
    }
};