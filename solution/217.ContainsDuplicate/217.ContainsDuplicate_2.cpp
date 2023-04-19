using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int>count;
        for(auto i:nums)count.insert(i);
        return !(nums.size()==count.size());
    }
};