class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                long long hight=0;
                while(i<nums.size()&&nums[i]==0){
                    ++hight;
                    ++i;
                }
                ans+=(1+hight)*hight/2;
            }
        }    
        return ans;
    }
};
///////////////////////////////////////
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0;
        int zeronum=0;
        for(auto num:nums){
            if(num==0)ans+=++zeronum;
            else zeronum=0;
        }
        return ans;
    }
};