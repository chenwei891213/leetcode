class Solution {
    public:
        bool isIsomorphic(string s, string t) {
            int table1[256] = {0}, table2[256] = {0};
            for(int i = 0; i < s.length(); ++i){
                if(table1[s[i]] != table2[t[i]]) return false;
                table1[s[i]] = i+1;
                table2[t[i]] = i+1;
            }
            return true;
        }
    };
    
    
    