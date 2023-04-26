class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int ans = 0;
        unordered_map<char,int> count;
        for(int i=0;i<s.size();i++){
            while(count[s[i]]!=0 && left<s.size()){
                --count[s[left]];
                ++left;
            }
            ++count[s[i]];
            ans=max(ans,i-left+1);
        }
        return ans;
    }
};
//Use sliding window to solve this problem.
//We need to maintain a window that represents the substring without repeating character.
//In order to ensure that the every character unique,we need to create a hash table to record the last appearance position of each character in string s.
//Then we need a left pointer to record window left boarder. 
//Then, for each character in the string, if it has appeared before, 
//we need to move the left pointer to the next position after the last appearance position of that character.
//If the character did not appear in the previous position.Record position of this character.
//We can use window's length to determine whether we need to update the answer.
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int ans=0;
        unordered_map<int,int>c;
        for(int i=0;i<s.size();i++){
            if(c.count(s[i]) && left<=c[s[i]]){
                left=c[s[i]]+1;
            }
            c[s[i]]=i;
            ans=max(ans,i-left+1);
        }
        return ans;
    }
};