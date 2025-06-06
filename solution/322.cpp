class Solution {
    public:
        int coinChange(vector<int>& coins, int amount) {
            int ans = 0;
            vector<int> table(amount + 1, amount+1);
            table[0] = 0;
            for(int i = 1; i < amount + 1; i++){
                for(int j = 0; j < coins.size(); j++){
                    if(coins[j] <= i)table[i] = min(table[i], table[i - coins[j]] + 1);
                }
            }   
            return table[amount] > amount ? -1 : table[amount];
        }
    };