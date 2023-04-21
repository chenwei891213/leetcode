class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>>count(s.size(),vector<bool>(s.size(),false));
        int n=s.size();
        //int count[1000][1000]={0};
        string ans="";
        for(int i=0;i<n;i++){
            for(int j=0;j<i+1;j++){
                count[j][i]=( s[i]==s[j] && (i-j<2 || count[j+1][i-1]==true));
                if(count[j][i]==true && i-j+1>ans.size())ans=s.substr(j,i-j+1);
            }
        }
        return ans;
    }
};