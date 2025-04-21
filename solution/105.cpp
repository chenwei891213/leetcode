class Solution {
    public:
        TreeNode* construct(vector<int>& preorder, int pleft, int pright, vector<int>& inorder, int ileft, int iright, unordered_map<int, int>& table){
            if(pleft > pright || ileft > iright) return NULL;
            TreeNode* root = new TreeNode(preorder[pleft]);
            int mid = table[preorder[pleft]];
            int i = mid - ileft; // represent the left subtree node number
            root -> left = construct(preorder, pleft+1, pleft+i, inorder, ileft, mid-1, table);
            root -> right = construct(preorder, pleft+i+1, pright, inorder, mid+1, iright, table);
            return root;
    
        }
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            unordered_map<int, int> table;
            for(int i = 0; i < inorder.size(); ++i) table[inorder[i]] = i;
            return construct(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, table);
        }
    };