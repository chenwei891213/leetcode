class Solution {
public:
    int countSubstrings(string s) {
        int ans = 0;
        for(int i=0;i<s.size();++i){
            int left = i;
            int right = i;
            while(left>=0 && right<s.size() && s[left]==s[right]){
                ++ans;
                --left;
                ++right;
            }
        }
        for(int i=0;i<s.size();++i){
            int left = i;
            int right = i+1;
            while(left>=0 && right<s.size() && s[left]==s[right]){
                ++ans;
                --left;
                ++right;
            }      
        }
        return ans;
    }
};
//Use DP
class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<bool>>dp(s.size(),vector<bool>(s.size(),false));
        int ans=0;
        for(int i=0;i<s.size();++i){
            for(int j=0;j<=i;++j){
                if(i==j || (s[i]==s[j] && ( i-j==1 || dp[i-1][j+1]==true ))){
                    dp[i][j]=true;
                    ++ans;
                }
            }
        }
        return ans;
    }
};