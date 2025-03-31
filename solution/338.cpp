//O(nlogn) solution
class Solution {
    public:
        int countbit(int n){
            int cnt = 0;
            while(n){
                cnt += n & 1;
                n = n >> 1;
            }
            return cnt;
        }
        vector<int> countBits(int n) {
            vector<int> table;
            for(int i = 0;i <= n; ++i) table.push_back(countbit(i));
            return table;
        }
    };
//O(nlogn) solution
class Solution {
    public:
    
        vector<int> countBits(int n) {
            vector<int> table;
            for(int i = 0; i <= n; i++){
                int sum = 0;
                int num = i;
                while(num){
                    sum += num % 2;
                    num /= 2;
                }
                table.push_back(sum);
            }
            return table;
        }
    };
//O(n) solution
class Solution {
    public:
    
        vector<int> countBits(int n) {
            vector<int> table;
            table.push_back(0);
            for(int i = 1;i  <= n; ++i){
                table.push_back(table[i/2] + i % 2);
            }
            return table;
        }
    };