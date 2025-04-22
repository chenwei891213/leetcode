// First version
class Solution {
    public:
        int helper(TreeNode* root, int& ans){
            if(!root) return 0;
            int valLeft = helper(root -> left, ans);
            int valRight = helper(root -> right, ans);
            int cur = max(root -> val, root -> val + valRight);
            cur = max(cur, root -> val + valLeft);
            ans = max(ans, cur);
            ans = max(ans, root -> val + valLeft + valRight);
            return cur;
        }
        int maxPathSum(TreeNode* root) {
            int ans = INT_MIN;
            helper(root, ans);
            return ans;     
        }
    };



class Solution {
    public:
        int helper(TreeNode* root, int& ans){
            if(!root) return 0;
            int left = max(helper(root -> left, ans), 0);
            int right = max(helper(root -> right, ans), 0);
            ans = max(ans, root -> val + left + right);
            return max(left, right) + root -> val;
        }
        int maxPathSum(TreeNode* root) {
            int ans = INT_MIN;
            helper(root, ans);
            return ans;     
        }
    };
    