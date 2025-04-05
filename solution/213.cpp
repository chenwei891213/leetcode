class Solution {
    public:
        int rob(vector<int>& nums) {
            vector<vector<int>>dp(2, vector<int>(nums.size() + 1, 0));
            dp[1][1] = nums[0];
            for(int i = 2; i <= nums.size(); ++i){
                if(i == nums.size())dp[1][i] = dp[1][i-1];
                else dp[1][i] = max(nums[i - 1] + dp[1][i-2], dp[1][i-1]);
                dp[0][i] = max(nums[i - 1] + dp[0][i-2], dp[0][i-1]);
            }
            return max(dp[0][nums.size()], dp[1][nums.size()]);
        }
    };


class Solution {
    public:
        int rob(vector<int>& nums) {
            if(nums.size() <= 1) return nums.empty() ? 0 : nums[0];
            return max(rob(nums, 0, nums.size() - 1), rob(nums, 1, nums.size()));
        }
        int rob(vector<int>& nums, int start, int end){
            int robEven = 0, robOdd = 0;
            for(int i = start; i < end; ++i){
                if((i + 1) % 2 == 0){
                    robEven = max(nums[i] + robEven, robOdd);
                }
                else{
                    robOdd = max(nums[i] + robOdd, robEven);
                }
            }
            return max(robOdd, robEven);
        }
    };
        