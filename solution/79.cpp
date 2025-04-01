class Solution {
    public:
        bool dfs(int row, int col, int i, vector<vector<char>>& board, string word, vector<vector<bool>> &visited){
    
            if(col < 0 || col >= board[0].size() ||
                row < 0 || row >= board.size() ||
                visited[row][col] == true||
                board[row][col] != word[i])return false;
    
            if(i == word.length() -1)return true;
            visited[row][col] = true;
            bool res =  dfs(row + 1, col, i+1, board, word, visited) ||
                        dfs(row - 1, col, i+1, board, word, visited) ||
                        dfs(row, col + 1, i+1, board, word, visited) ||
                        dfs(row, col - 1, i+1, board, word, visited);
            visited[row][col] = false;
    
            return res;
    
        }
        bool exist(vector<vector<char>>& board, string word) {
            int m = board.size();
            int n = board[0].size();
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            for(int i = 0; i < board.size(); ++i){
                for(int j = 0; j < board[0].size(); ++j){
                    if(dfs(i, j, 0, board, word, visited))return true;
                }
            }
            return false;
    
    
        }
    };

class Solution {
    public:
        bool dfs(int row, int col, int i, vector<vector<char>>& board, string word){
            
            if(col < 0 || col >= board[0].size() ||
                row < 0 || row >= board.size() ||
                board[row][col] == '$'||
                board[row][col] != word[i])return false;
            char temp = board[row][col];
            if(i == word.length() -1)return true;
            board[row][col] = '$';
            bool res =  dfs(row + 1, col, i+1, board, word) ||
                        dfs(row - 1, col, i+1, board, word) ||
                        dfs(row, col + 1, i+1, board, word) ||
                        dfs(row, col - 1, i+1, board, word);
            board[row][col] = temp;
    
            return res;
    
        }
        bool exist(vector<vector<char>>& board, string word) {
    
            for(int i = 0; i < board.size(); ++i){
                for(int j = 0; j < board[0].size(); ++j){
                    if(dfs(i, j, 0, board, word))return true;
                }
            }
            return false;
    
    
        }
    };