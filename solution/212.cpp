class Solution {
    public:
        class Trie{
    
          
            public:
                bool isWord;
                Trie* next[26];
                string str;
                
                Trie(){
                    isWord = false;
                    for(int i = 0; i < 26; i++) next[i] = NULL; 
                    str = "";
                }
    
                void insert(string word){
                    Trie* ptr = this;
                    for(auto c : word){
                        auto index = c - 'a';
                        if(ptr -> next[index] == NULL) ptr -> next[index] = new Trie();
                        ptr = ptr -> next[index];
                    }
                    ptr -> isWord = true;
                    ptr -> str = word;
                }
        };
    
        bool dfs(int row, int col, vector<vector<char>> &board, Trie* wordList, vector<vector<bool>> &visited, vector<string> &ans){
            
            if(row < 0 || row >= board.size()||
                col < 0 || col >= board[0].size()||
                wordList -> next[board[row][col] - 'a'] == NULL ||   
                visited[row][col] == true
            )return false;
            wordList = wordList -> next[board[row][col] - 'a'];
            if(wordList -> isWord == true){
                wordList -> isWord = false;
                ans.push_back(wordList -> str);
            }
            
            visited[row][col] = true;
            bool res = dfs(row + 1, col, board, wordList, visited, ans) ||
                        dfs(row - 1, col, board, wordList, visited, ans)||
                        dfs(row, col + 1, board, wordList, visited, ans)||
                        dfs(row, col - 1, board, wordList, visited, ans);
            visited[row][col] = false;
            return res;
        }
    
        vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
            Trie* wordList =  new Trie();
            vector<string> ans;
            int col = board[0].size();
            int row = board.size();
            vector<vector<bool>> visited(row, vector<bool>(col, false));
            for(auto c : words) wordList -> insert(c);
            for(int i = 0; i < board.size(); ++i){
                for(int j = 0; j < board[0].size(); ++j){
                    if(wordList -> next[board[i][j] - 'a'] != NULL)dfs(i, j, board, wordList, visited, ans);
                }
            }
            return ans;
        }
    };
    
 