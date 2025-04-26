class Solution {
    public:
        int minDistance(string word1, string word2) {
            int m = word1.size(), n = word2.size();
            vector<vector<int>> table(m+1, vector<int>(n+1, 0));
            for(int i = 0; i <= m; ++i) table[i][0] = i;
            for(int i = 0; i <= n; ++i) table[0][i] = i;
    
            for(int i = 1; i <= m; ++i){
                for(int j = 1; j <= n; ++j){
                    if(word1[i-1] == word2[j-1]) table[i][j] = table[i-1][j-1];
                    else table[i][j] = min(table[i-1][j-1], min(table[i][j-1], table[i-1][j]))+1;
                }
            }
    
            return table[m][n];
        }
    };