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

// follow up solution
class Solution {
    public:
        bool isSubsequence(string s, string t) {
            unordered_map<char, vector<int>> table;
            int pre = -1;
            for(int i = 0; i < t.length(); ++i) table[t[i]].push_back(i);
            for(char c : s){
                auto it = upper_bound(table[c].begin(), table[c].end(), pre);
                if(it == table[c].end()) return false;
                pre = *it;
            }
            return true;
        }
    };
    
    // create a hash table according to the string t, each element is 
    // record each char at different appear index in the string