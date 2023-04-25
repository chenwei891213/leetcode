class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>count;
        if(s.size()!=t.size())return false;
        for(int i=0;i<s.size();++i){
            count[s[i]]++;
            count[t[i]]--;
        }
        for(auto i:count){
            if(i.second!=0)return false;
        }
        return true;
    }
};