//My solution
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(int i=nums.size()-1;i>0;i--){
            if(nums[i]==nums[i-1])nums.erase(nums.begin()+i);
        }
        return nums.size();
    }
};
//Use Two Pointers
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        for(int j=1;j<nums.size();j++){
            if(nums[j]!=nums[i]){
                nums[i+1]=nums[j];
                i++;
            }
        }
        return i+1;
    }
};