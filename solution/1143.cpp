class Solution {
    public:
        int longestCommonSubsequence(string text1, string text2) {
            vector<vector<int>> table(text2.length()+1, vector<int>(text1.length()+1, 0));
    
            for(int i = 1; i <= text2.length(); ++i){
                for(int j = 1; j <= text1.length(); ++j){
                    if(text1[j-1] == text2[i-1]) table[i][j] = 1 + table[i-1][j-1];
                    else table[i][j] = max(table[i-1][j], table[i][j-1]);
                }
            }
            return table[text2.length()][text1.length()];
        }
    };
    // if(1[m]==2[n])
    // table[m][n] = 1 + table[m-1][n-1]
    // else
    // table[m][n] = max(table[m][n-1], table[m-1][n])
        //. n a a c d e
    //    n 0 0 0 0 0 0 
    //    a 0 1 1 1 1 1 
    //    c 0 1 1 2 2 2
    //    e 0 1 1 1 1 3 
    
