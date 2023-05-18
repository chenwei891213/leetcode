//When attempting to solve this problem, I faced a challenge in understanding how to move the left pointer to accomplish my objective. 
//Therefore, it is necessary for me to review this problem.
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int>count(128,0);
        // unordered_map<char,int>count;
        string ans="";
        int cnt=0;
        int minleft=-1;
        int minlen=INT_MAX;
        int start=0;
        for(auto i:t)count[i]++;
        for(int i=0;i<s.size();i++){
            if(--count[s[i]]>=0)++cnt;
            while(cnt==t.size()){
                if(i-start+1<minlen){
                    minlen=i-start+1;
                    minleft=start;
                }
                if(++count[s[start]]>0)--cnt;
                ++start;
            }
        }  
        return ans=minleft==-1?"":s.substr(minleft,minlen);
    }
};