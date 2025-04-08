class Solution {
    public:
        bool canJump(vector<int>& nums) {
            vector<bool> canJump(nums.size(), false);
            canJump[0] = true;
            int end = nums.size() - 1;
            for(int i = 0; i < nums.size(); ++i){
                if(canJump[i]){
                    for(int j = i + 1; j <= end; ++j){
                        if(j - i <= nums[i]) canJump[j] = true;
                        else break;
                    }
                }
    
                if(canJump[i] && (end - i) <= nums[i])return true;
            }
            return false;
        }
    };


class Solution {
    public:
        bool canJump(vector<int>& nums) {
            int reach = 0;        
            for(int i = 0; i < nums.size() - 1; ++i){
                if(reach >= i) reach = reach < i + nums[i] ? i + nums[i] : reach;
                else break;
            }
            return reach >= nums.size() - 1;
        }
    };