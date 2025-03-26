//solution 1
class Solution {
    public:
        int missingNumber(vector<int>& nums) {
            int length = nums.size();
            int sum = (length + 1) * length / 2;
            for(auto num : nums){
                sum -= num;
            }
            return sum;
        }
    
    };
//solution 2
class Solution {
    public:
        int missingNumber(vector<int>& nums) {
            int result = nums.size();
            for(int i = 0; i < nums.size(); i++){
                result ^= i ^ nums[i];
            }
            return result;
        }
    
    };