class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            int minLength = INT_MAX;
            string ans = "";
            bool flag = false;
      
            for(int i = 0; i < strs[0].length(); ++i){
                char t = strs[0][i];
                for(int j = 1; j < strs.size(); ++j){
                    if(i >= strs[j].length() || strs[j][i] != t){
                        flag = true;
                        return ans;
                    }
                }
                ans += t;
            }
            return ans;
        }
    };

class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            int minLength = INT_MAX;
            string ans = "";
        
            for(int i = 0; i < strs[0].length(); ++i){
                char t = strs[0][i];
                for(int j = 1; j < strs.size(); ++j){
                    if(i >= strs[j].length() || strs[j][i] != t){
                        return strs[j].substr(0, i);
                    }
                } 
            }
            return strs[0];
        }
    };


class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            string ans = "";    
            sort(strs.begin(), strs.end());
            int n = strs.size();
            string first = strs[0], second = strs[n-1];
            for(int i = 0; i < min(first.length(), second.length()); ++i){
                if(first[i] != second[i]) return ans;
                ans += first[i];
            }
            return ans;
            
        }
    };