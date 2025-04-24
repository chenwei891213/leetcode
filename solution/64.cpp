class Solution {
    public:
        int minPathSum(vector<vector<int>>& grid) {
            int row = grid.size();
            int col = grid[0].size();
            vector<vector<int>> table(row+1, vector<int>(col+1, INT_MAX));
            table[0][1] = table[1][0] = 0;
    
            for(int i = 0; i < grid.size(); ++i){
                for(int j = 0; j < grid[0].size(); ++j){
                    table[i+1][j+1] = min(table[i][j+1], table[i+1][j]) + grid[i][j];
                }
            }
    
            return table[row][col];
        }
    };


//space optimized version
class Solution {
    public:
        int minPathSum(vector<vector<int>>& grid) {
    
            for(int i = 0; i < grid.size(); ++i){
                for(int j = 0; j < grid[0].size(); ++j){
                    if(i==0 && j==0)continue;
                    else if(j == 0) grid[i][0] += grid[i-1][0];
                    else if(i == 0) grid[0][j] += grid[0][j-1];
                    else{
                        grid[i][j] += min(grid[i][j-1], grid[i-1][j]);
                    }
                }
            }
    
            return grid.back().back();
    
        }
    };