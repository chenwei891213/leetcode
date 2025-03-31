class Solution {
    public:
        bool isValidChar(char s){
            if(s >= 'a' && s <='z')return true;
            else if(s >= 'A' && s <= 'Z')return true;
            else if(s >= '0' && s <= '9') return true;
            else return false;
        }
        bool isPalindrome(string s) {
            int left = 0;
            int right = s.length()-1;
            while(left < right){
                if(!isValidChar(s[left]))left++;
                else if(!isValidChar(s[right]))right--;
                else if((s[left] + 32 - 'a') % 32 == (s[right] + 32 - 'a') % 32){
                    left++;
                    right--;
                }
                else return false;
            }
            return true;
        }
    };
    
    