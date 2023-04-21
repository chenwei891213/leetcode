class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0];
        vector<int>maxp(nums.size(),0),minp(nums.size(),0);
        maxp[0]=nums[0];
        minp[0]=nums[0];
        for(int i=1;i<nums.size();++i){
            maxp[i]=max(nums[i],max(maxp[i-1]*nums[i],minp[i-1]*nums[i]));
            minp[i]=min(nums[i],min(maxp[i-1]*nums[i],minp[i-1]*nums[i]));
            ans=max(ans,maxp[i]);
        }
        return ans;
    }
};

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans=nums[0];
        int maxp=nums[0];
        int minp=nums[0];
        for(int i=1;i<nums.size();++i){
            if(nums[i]<0)swap(maxp,minp);
            maxp=max(nums[i],nums[i]*maxp);
            minp=min(nums[i],nums[i]*minp);
            ans=max(ans,maxp);
        }
        return ans;
    }
};