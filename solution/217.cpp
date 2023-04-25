//use hash table 
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
//use set
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int>count;
        for(auto i:nums)count.insert(i);
        return !(nums.size()==count.size());
    }
};
//Traverse the sorted array nums by comparing the current element with the next one. 
//If both values are the same, then the array contains duplicate elements.
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1])return true;
        }
        return false;
    }
};