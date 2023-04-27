//My solution
class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int left = 0;
        int right = 1;
        int temp = 0;
        int ans=0;
        while(right<s.size()){
            while(left>=0 && right<s.size() && s[left]=='0' && s[right]=='1'){
                --left;
                ++right;
                ++temp;
            }
            ans=max(ans,2*temp);
            left = right;
            right = left+1;
            temp=0;
        }
        return ans;
    }
};
//Another people solution 
class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        int i = 0;
        int zeronums = 0;
        int onenums = 0;
        int ans = 0;
        while(i<s.size()){
            onenums = 0;
            zeronums = 0;
            while( s[i] == '0'){
                ++zeronums;
                ++i;
            }
            while(s[i] == '1'){
                ++onenums;
                ++i;
            }
            ans=max(ans,2*min(onenums,zeronums));
        }
        return ans;
    }
};
//Magic solution 
class Solution {
public:
    int findTheLongestBalancedSubstring(string s) {
        string target="01";
        int ans=0;
        while(target.size()<=s.size()){
            if(s.find(target)!=string::npos){
                ans=target.size();
                target="0"+target+"1";
            }
            else break;
        }
        return ans;
    }
};