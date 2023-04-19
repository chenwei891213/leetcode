using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int,int>count;
        for(auto i:nums){
            if(++count[i]>1)return true;
            else ++count[i];
        }
        return false;
    }
};