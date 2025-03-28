class Solution {
    public:
        int lengthOfLIS(vector<int>& nums) {
            vector<int>table(nums.size(), 1);
            table[0] = 1;
            int ans = 0;
            for(int i = 0; i < nums.size(); i++){
                for(int j = i - 1; j > -1; j--){
                    if(nums[j] < nums[i]) table[i] = max(table[i], 1+table[j]);
                }
                ans = max(table[i], ans);
            }
            return ans;
        }
    };