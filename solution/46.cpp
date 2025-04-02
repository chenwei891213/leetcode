class Solution {
    public:
    
        void dfs(vector<int>element, vector<vector<int>> &ans, vector<int>&nums, vector<bool> &choose){
    
            if(element.size() == nums.size()){
                ans.push_back(element);
                return;
            }
    
            for(int i = 0; i < nums.size(); ++i){
                if(choose[i])continue;
                element.push_back(nums[i]);
                choose[i] = true;
                dfs(element, ans, nums, choose);   
                element.pop_back();
                choose[i] = false;
            }
        }
    
        vector<vector<int>> permute(vector<int>& nums) {
            vector<bool> choose(nums.size(), false);
            vector<int> element;
            vector<vector<int>> ans;
            dfs(element, ans, nums, choose);   
            return ans;
        }
    };
    
    