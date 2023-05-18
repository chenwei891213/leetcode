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
//Use queue
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*>list;
        if(root)list.push(root);
        while(!list.empty()){
            TreeNode* q=list.front();list.pop();
            if(q->left)list.push(q->left);
            if(q->right)list.push(q->right);
            TreeNode* temp=q->left;
            q->left=q->right;
            q->right=temp;
        }
        return root;
    }
};
//Use recursive 
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root){
            TreeNode* temp=root->left;
            root->left=root->right;
            root->right=temp;
            invertTree(root->left);
            invertTree(root->right);
        }
        return root;
    }
};