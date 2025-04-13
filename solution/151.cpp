class Solution {
    public:
        string reverseWords(string s) {
            string ans = "";
            vector<pair<int, int>> records;
            for(int left = 0; left < s.length(); ++left){
                if(s[left] == ' ') continue;
                int right = left;
                while(right < s.length()){
                    if(s[right] == ' ') break;
                    else ++right;
                } 
                records.push_back(make_pair(left, right-1));
                left = right;
            }
            for(int i = records.size() - 1; i >= 0; --i){
                int left = records[i].first;
                int right = records[i].second;
                ans += s.substr(left, right - left + 1);
                if(i !=  0) ans += ' ';
            }
            
            return ans;
        }
    };

//in-place solution
class Solution {
    public:
        string reverseWords(string s) {
            reverse(s.begin(), s.end());
            int saveIndex = 0;
            for(int i = 0; i < s.length(); ++i){
                if(s[i] == ' '){
                    continue;
                }
                int j = i;
                if(saveIndex != 0) s[saveIndex++] = ' ';
                while(j < s.length() && s[j] != ' '){
                        s[saveIndex++] = s[j++];
                }
                reverse(s.begin() + saveIndex - (j-i), s.begin() + saveIndex);
                i = j;
            }
            s.resize(saveIndex);
            return s;
        }
    };