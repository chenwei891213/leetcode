class Solution {
    public:
        int longestConsecutive(vector<int>& nums) {
            unordered_set<int> s(nums.begin(), nums.end());
            int ans = 0;
            for(auto num:nums){
                auto prev = --num;
                auto next = ++num+1;
                s.erase(num);
                while(s.count(prev)){
                    s.erase(prev);
                    prev--;
                }
                while(s.count(next)){
                    s.erase(next);
                    next++;
                }
                ans = max(ans, next - prev - 1 );
            }
    
    
            return ans;
        }
    };
    