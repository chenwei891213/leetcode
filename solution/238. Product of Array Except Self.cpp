//The first loop calculates the product of each position from the last position to the next position of that position.
//The results of the first loop are represent the product of the values following the position i. 
//TTe second loop obtains the answer by taking the prefix product of each position using the result obtained from the first loop for that position.
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        ans[n-1]=1;
        for(int i=n-2;i>=0;i--){
            ans[i]=nums[i+1]*ans[i+1];
        }
        int left=1;
        for(int i=0;i<n;i++){
            ans[i]*=left;
            left*=nums[i];
        }
        return ans;
    }
};
