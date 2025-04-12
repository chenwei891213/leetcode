class Solution {
    public:
        bool isHappy(int n) {
            unordered_set<int> table;
            while(n != 1){
                int temp = n;
                int sum = 0;
                while(temp > 0){
                    sum += (temp % 10) * (temp % 10);
                    temp /= 10;
                }
                if(table.count(sum)) return false;
                else table.insert(sum);
                n = sum;
            }
            return true;
        }
    };
    
// use slow and fast pointer to solve this problem
class Solution {
    public:
        int sum(int n){
            int sum = 0;
            while(n > 0){
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            return sum;
        }
        bool isHappy(int n) {
            int slow = n, fast = n;
            while(true){
                slow = sum(slow);
                fast = sum(fast);
                fast = sum(fast);
                if(slow == fast) break;
            }
            return slow == 1;
        }
    };