class Solution {
    public:
    
        int numDecodings(string s) {
            vector<int> table(s.length() + 1, 0);
            unordered_map<string, char> lookUpTable;
            char c = 'A';
            for(int i = 1; i <= 26; ++i){
                lookUpTable[to_string(i)] = c;
                ++c;
            }
            // 12 
            //112 
            table[0] = 1;
            table[1] = s[0] == '0' ? 0 : 1;
            for(int i = 2; i <= s.length(); ++i){
                string t = "";
                t += s[i-2];
                t += s[i-1];
                string key(1, s[i-1]);
                if(lookUpTable.count(key) && lookUpTable[key] <= 'Z' && lookUpTable[key]  >= 'A'){
                    table[i] += table[i-1];
                }
                if(lookUpTable.count(t) && lookUpTable[t]  <= 'Z' && lookUpTable[t]  >= 'A'){
                    table[i] += table[i-2];
                } 
            }
            
            return table[s.length()];
        }
    };
    
class Solution {
    public:
    
        int numDecodings(string s) {
            vector<int> table(s.length() + 1, 0);
            table[0] = 1;
            for(int i = 1; i <= s.length(); ++i){
                table[i] = s[i-1] == '0' ? 0 : table[i-1];
                if(i >= 2 && (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <='6')))table[i] += table[i-2];
            }
            
            return table.back();
        }
    };
    