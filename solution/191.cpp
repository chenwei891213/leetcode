class Solution {
    public:
        int hammingWeight(int n) {
            int ans = 0;
            while(n > 0){
                int mod = n % 2;
                if(mod)ans++;
                n = n/2;
            }
            return ans;
        }
    };

class Solution {
    public:
        int hammingWeight(int n) {
            int ans = 0;
            while(n > 0){
                ans += n & 1;
                n = n >> 1;
            }
            return ans;
        }
    };