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
        vector<vector<int>> levelOrder(TreeNode* root) {
            queue<TreeNode*>list;
            vector<vector<int>> ans;
            if(root == NULL)return ans;
            list.push(root);
            while(!list.empty()){
                int level = list.size();
                vector<int>element;
                for(int i = 0; i < level; ++i){
                    auto curNode = list.front();
                    list.pop();
                    element.push_back(curNode -> val);
                    if(curNode -> left)list.push(curNode -> left);
                    if(curNode -> right)list.push(curNode -> right);
                }
                ans.push_back(element);
                element.clear();
            }
            return ans;
        }
    };