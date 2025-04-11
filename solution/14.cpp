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