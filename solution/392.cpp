//first version
class Solution {
    public:
        bool isSubsequence(string s, string t) {
    
            stack<char>list;
            for(char c : s) list.push(c);
            int i = t.length() - 1;
            while(!list.empty() && i > -1){
                char findChar = list.top();
                if(t[i--] == findChar) list.pop();
            }
            return list.empty();
        }
    };
    
class Solution {
    public:
        bool isSubsequence(string s, string t) {
            int j = 0; // s index
            for(int i = 0; i < t.size() && j < s.size(); ++i){
                if(s[j] == t[i]) ++j;
            }
            return j == s.length();
        }
    };