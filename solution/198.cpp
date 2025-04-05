class Solution {
    public:
        int rob(vector<int>& nums) {
            if(nums.size() == 1) return nums[0];
            vector<int>table(nums.size()+1, 0);
            table[0] = 0;
            table[1] = nums[0];//rob first house
            for(int i = 2; i < table.size(); ++i){ 
                table[i] = max(table[i-1], nums[i-1]+table[i-2]);      
            }
            return table[nums.size()];
        }
    };