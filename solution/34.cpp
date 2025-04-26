class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      	vector<int>ans = {-1,-1};
        int left = 0;
        int right = nums.size()-1;
        while(left <= right){
            int mid=(left+right)/2;
            if(nums[mid]>=target)right=mid-1;
            else left=mid+1;
        }
        if(left==nums.size()||nums[left]!=target)return ans;
        ans[0]=left;
        right = nums.size()-1;
        while(left <= right){
            int mid=(left+right)/2;
            if(nums[mid]<=target)left=mid+1;
            else right=mid-1;
        }
        ans[1]=left-1;
        return ans;
    }
};


class Solution {
    public:
        int search(vector<int>& nums, int target){
            int left = 0, right = nums.size()-1;
            while(left <= right){
                int mid = (left+right) / 2;
                if(nums[mid] >= target) right = mid - 1;
                else left = mid + 1;
            }
            return left;
        }
    
        vector<int> searchRange(vector<int>& nums, int target) {
            int left = search(nums, target);
            if(left == nums.size() || nums[left] != target) return {-1, -1};
            return {left, search(nums, target+1)-1};
        }
    };