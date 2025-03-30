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
    int find(TreeNode* root, int &k){
        int val = 0;
        if(!root) return -1;
        if(root->left != NULL)val = find(root->left, k);
        if(k == 0)return val;
        if(--k == 0)return root->val;
        return find(root->right, k);

    }
    int kthSmallest(TreeNode* root, int k) {
        return find(root, k);
    }
};

class Solution {
    public:
    
        int kthSmallest(TreeNode* root, int k) {
            stack<TreeNode*> table;
            int cnt = 0;
            while(root || !table.empty()){
                while(root){
                    table.push(root);
                    root = root -> left;
                }
                ++cnt;
                root = table.top();
                if(cnt == k)return root -> val;
                table.pop();
                root = root->right;
            }       
            return -1;
    
    
    
        }
    };