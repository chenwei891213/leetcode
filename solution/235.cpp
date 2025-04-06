class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            if(!root || (root -> val == p -> val) || (root -> val == q -> val) )return root;
            TreeNode* left = lowestCommonAncestor(root -> left, p, q);
            TreeNode* right = lowestCommonAncestor(root -> right, p, q);
            if(left && right)return root;
            
            return left == NULL ? right : left;
        }
    };

class Solution {
    public:
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            int maxValue = max(p -> val, q -> val), minValue = min(p -> val, q -> val);
            if(root -> val < maxValue && root -> val < minValue) return lowestCommonAncestor(root -> right, p, q);
            else if(root -> val > maxValue && root -> val > minValue) return lowestCommonAncestor(root -> left, p, q);
            else return root;
        }
    };
    