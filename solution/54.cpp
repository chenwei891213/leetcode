class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            vector<int> ans;
            int row = matrix.size();
            int col = matrix[0].size();
            vector<vector<int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
            vector<vector<bool>>visited(row, vector<bool>(col, false));
            int i = 0, j = 0, idx = 0;
            for(int k = 0; k < col * row; ++k){
                ans.push_back(matrix[i][j]);
                visited[i][j] = true;
                int x = i + direction[idx][0];
                int y = j + direction[idx][1];
                if(x >= row || y >= col || x < 0 || y < 0 || visited[x][y] ){
                    idx = (idx + 1) % 4;
                    x = i + direction[idx][0];
                    y = j + direction[idx][1];
                }
                i = x;
                j = y;
            }
            return ans;
        };
    
    };

class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            int row = matrix.size();
            int col = matrix[0].size();
            vector<int> ans;
            int left = 0, right = col - 1, up = 0, down = row - 1;
            while(true){
                for(int i = left; i <= right; ++i) ans.push_back(matrix[up][i]);
                if(++up > down)break;
                for(int i = up; i <= down; ++i) ans.push_back(matrix[i][right]);
                if(--right < left)break;
                for(int i = right; i >= left; --i) ans.push_back(matrix[down][i]);
                if(--down < up)break;
                for(int i = down; i >= up; --i) ans.push_back(matrix[i][left]);            
                if(++left > right)break;
            }
            return ans;
        }
    };