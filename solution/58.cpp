class Solution {
    public:
        int lengthOfLastWord(string s) {
            int left = 0, right = 0;
            int i = s.length() - 1;
            while(i >= 0){
                if(s[i] != ' '){
                    right = i;
                    break;
                }
                i--;
            }
            while(i >= 0){
                if(i-1 < 0 || s[i-1] == ' '){
                    left = i;
                    break;
                }
                i--;
            }
            return right - left + 1;
        }
    };


class Solution {
    public:
        int lengthOfLastWord(string s) {
            int counting = false;
            int ans = 0;
            for(int i = s.length() - 1; i >= 0; --i){
                if(s[i] != ' '){
                    counting = true;
                    ++ans;
                }
                else if(counting) break;
            }
            return ans;
        }
    };