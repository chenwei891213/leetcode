class Solution {
    public:
        void combination(vector<int>& candidates, int target, vector<vector<int>> &ans, vector<int> element, int start){
            
            if(target == 0){
                ans.push_back(element);
                return;
            }
            else if(target < 0)return;
    
            for(int i = start; i < candidates.size(); ++i){
                element.push_back(candidates[i]);
                combination(candidates, target - candidates[i], ans, element, i);
                element.pop_back();
            }
        }
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
            vector<vector<int>> ans;
            vector<int> element;
            combination(candidates, target, ans, element, 0);
    
            return ans;
        }
    };