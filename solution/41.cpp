class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<bool> visited(nums.size(), false);
        for(int num : nums){
            if(num > 0 && num <= nums.size()) visited[num-1] = true;
        }
        for(int i = 0; i < visited.size(); ++i){
            if(!visited[i]) return i+1;
        }
        return nums.size()+1;
    }
};
// O(1) space solution
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i){
            while(nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i]-1] != nums[i]){
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] != i+1) return i+1;
        }
        return nums.size() + 1;
    }
};

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] <= 0 || nums[i] > nums.size()){
                nums[i] = nums.size()+1;
            }
        }
        for(int i = 0; i < nums.size(); ++i){
            int n = abs(nums[i]);
            if(n > 0 && n <= nums.size()){
                nums[n-1] = -abs(nums[n-1]);
            }
        }
        for(int i = 0; i < nums.size(); ++i){
            if(nums[i] > 0) return i+1;
        }
        return nums.size()+1;
    }
};