class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            nums[i]=max(nums[i],nums[i]+nums[i-1]);
            ans=max(ans,nums[i]);
        }
        return ans;
    }
};
//Use Divide and Conquer.This core ideas is divide the array to the left part and right part from middle position.
//Then the maximum will exists somewhere from
//entirely in the left-half of array [L, mid-1], OR
//entirely in the right-half of array [mid+1, R], OR
//3.in array consisting of mid element along with some part of left-half and some part of right-half such that these 
//form contiguous subarray - [L', R'] = [L', mid-1] + [mid] + [mid+1,R'], where L' >= L and R' <= R
class Solution {
public:
    int helper(vector<int>& nums,int l,int r){
        if(l>r)return INT_MIN;
        int mid=(l+r)/2;int r_sum=0,l_sum=0;
        for(int i=mid-1,cur_sum=0;i>=l;i--){
            cur_sum+=nums[i];
            l_sum=max(l_sum,cur_sum);
        }
        
        for(int i=mid+1,cur_sum=0;i<=r;i++){
            cur_sum+=nums[i];
            r_sum=max(r_sum,cur_sum);
        }
        return max(max(helper(nums,mid+1,r),helper(nums,l,mid-1)),r_sum+l_sum+nums[mid]);
    }
    int maxSubArray(vector<int>& nums) {
        return(helper(nums,0,nums.size()-1));
    }
};
//Optimized Divide and Conquer
class Solution {
public:
    vector<int>r_sum,l_sum;
    int helper(vector<int>& nums,int l,int r){
        if(l==r)return nums[l];
        int mid=(l+r)/2;
        return max(max(helper(nums,mid+1,r),helper(nums,l,mid)),l_sum[mid]+r_sum[mid+1]);
    }
    int maxSubArray(vector<int>& nums) {
        r_sum=l_sum=nums;
        for(int i=1;i<nums.size();i++)l_sum[i]+=max(0,l_sum[i-1]);
        for(int i=nums.size()-2;i>=0;i--)r_sum[i]+=max(0,r_sum[i+1]);
        return(helper(nums,0,nums.size()-1));
    }
};