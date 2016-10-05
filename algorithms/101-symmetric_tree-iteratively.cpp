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
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        stack<TreeNode*> sk;
        sk.push(root->left);
        sk.push(root->right);
        while(!sk.empty())
        {
            TreeNode* node1 = sk.top();
            sk.pop();
            TreeNode* node2 = sk.top();
            sk.pop();
            if(!node1 && !node2) continue;
            if(!node1 || !node2) return false;
            if(node1->val != node2->val) return false;
            sk.push(node1->left);
            sk.push(node2->right);
            sk.push(node1->right);
            sk.push(node2->left);
        }
        return true;
    }
};