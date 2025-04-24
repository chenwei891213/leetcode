class Solution {
    public:
        int minSubArrayLen(int target, vector<int>& nums) {
            int curSum = 0;
            int ans = INT_MAX;
            int right = 0;
            int m = nums.size();
            for(int left = 0; left < m; ++left){
    
                while(right < m && curSum < target){
                    curSum += nums[right++];
                }    
                if(curSum >= target){
                    ans = min(ans, right - left);
                    curSum -= nums[left];
                } 
            }
    
            return ans == INT_MAX ? 0 : ans;
        }
    };


//use binary search to find the right bound
class Solution {
    public:
        int search(int i, int target, vector<int>& nums){
            int left = i, right = nums.size()-1;
            while(left <= right){
                int mid = (left+right) / 2;
                if(nums[mid] >= target) right = mid-1;
                else left = mid+1;
            }
            return left;
        }
        
        int minSubArrayLen(int target, vector<int>& nums) {
            int m = nums.size();
            vector<int> table(m+1, 0);
            int ans = m+1;
            for(int i = 0; i < m; ++i) table[i+1] = table[i] + nums[i];
            for(int i = 0; i < m; ++i){
                int right = search(i+1, table[i]+target, table);
                if(right == m+1) continue;
                ans = min(ans, right-i);
            }
            return ans == m+1 ? 0 : ans;
        }
    };