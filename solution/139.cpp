class Solution {
    public:
        bool wordBreak(string s, vector<string>& wordDict) {
            unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
            vector<bool>dp_array(s.length()+1, false);
            dp_array[0] = true;
            for(int i=0; i < s.length(); i++){
                for(int j = i; j >-1; j--){
                    if(wordSet.count(s.substr(j,i-j+1)) && dp_array[j] == true){
                        dp_array[i+1] = true;
                        break;
                    }
                }
            }
            return dp_array[s.length()];
        }
    };