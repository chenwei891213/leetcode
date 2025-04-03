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
        bool subOrNot(TreeNode* p, TreeNode* q){
            if(!p && !q) return true;
            else if(!p || !q) return false;
            else if(p -> val != q -> val) return false;
            return (subOrNot(p -> left, q -> left) && subOrNot(p -> right, q -> right));
        }
        bool isSubtree(TreeNode* root, TreeNode* subRoot) {
            if(!root)return false;
            if(subOrNot(root, subRoot))return true;
            return (isSubtree(root -> left, subRoot) || isSubtree(root -> right, subRoot));
        }
    };