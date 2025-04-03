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
        void inOrder(TreeNode* root, vector<int> &list){
            if(!root)return;
            if(root -> left) inOrder(root -> left, list);
            list.push_back(root -> val);
            if(root -> right) inOrder(root -> right, list);
            return;
        }
        bool isValidBST(TreeNode* root) {
            vector<int> list;
            inOrder(root, list);
            for(int i = 0; i < list.size() - 1; ++i){
                if(list[i] >= list[i + 1])return false;
            }
            return true;
        }
    };

class Solution {
    public:
        bool isValidBST(TreeNode* root) {
            return isValidBST(root, LONG_MIN, LONG_MAX);
        }
        bool isValidBST(TreeNode* root, long mn, long mx) {
            if (!root) return true;
            if (root->val <= mn || root->val >= mx) return false;
            return isValidBST(root->left, mn, root->val) && isValidBST(root->right, root->val, mx);
        }
    };