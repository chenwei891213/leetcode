//Use two pointer
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<nums.size()-2;++i){
            int L=i+1;int R=nums.size()-1;
            while(L<R){
                if(nums[i]+nums[L]+nums[R]==0){
                    ans.push_back({nums[i],nums[L],nums[R]});
                    while(L+1<nums.size() && nums[L]==nums[L+1])++L;
                    while(R-1>=0 && nums[R]==nums[R-1])--R;
                    ++L;
                    --R;
                }
                else if(nums[i]+nums[L]+nums[R]>0)--R;
                else ++L;
            }
            while(i+1<nums.size()&&nums[i]==nums[i+1])++i;
        }        
        return ans;
    }
};
//Use two pointer+set
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> res;
        sort(nums.begin(), nums.end());
        if (nums.empty() || nums.back() < 0 || nums.front() > 0) return {};
        for (int k = 0; k < (int)nums.size() - 2; ++k) {
            if (nums[k] > 0) break;
            int target = 0 - nums[k], i = k + 1, j = (int)nums.size() - 1;
            while (i < j) {
                if (nums[i] + nums[j] == target) {
                    res.insert({nums[k], nums[i], nums[j]});
                    while (i < j && nums[i] == nums[i + 1]) ++i;
                    while (i < j && nums[j] == nums[j - 1]) --j;
                    ++i; --j;
                } else if (nums[i] + nums[j] < target) ++i;
                else --j;
            }
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};