class Solution {
    public:
        int characterReplacement(string s, int k) {
            int maxcount = 0;
            int ans = 0;
            int left = 0;
            int right = 0;
            unordered_map<char, int>table;
    
            while(right < s.length()){
    
                table[s[right]]++;
                maxcount = max(table[s[right]], maxcount);
                if((right - left + 1) - maxcount > k){
                    table[s[left]]--;
                    left++;     
                }
                ans = max(ans, right - left + 1);
                right++;
            }
            return ans;
        }
    };
