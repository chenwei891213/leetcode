class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>pos;
        for(int i=0;i<nums.size();i++){
            int target_num=target-nums[i];
            if(pos.find(target_num)!=pos.end())return {i,pos[target_num]};
            else pos[nums[i]]=i;
        }
        return {};
    }
};