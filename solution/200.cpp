//DFS
class Solution {
public:
    void findisland(vector<vector<char>>& grid,vector<vector<int>>& visited,int i,int j){
        if(0<=i && i<grid.size() && 0<=j && j<grid[0].size()){
            if(visited[i][j]==0 && grid[i][j]=='1'){
                visited[i][j]='1';
                findisland(grid,visited,i+1,j);
                findisland(grid,visited,i-1,j);
                findisland(grid,visited,i,j+1);
                findisland(grid,visited,i,j-1);
            }
        }     
    }
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        vector<vector<int>>visited(row,vector<int>(col));
        int ans=0;
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                if(visited[i][j]==0 && grid[i][j]=='1'){
                    ++ans;
                    visited[i][j]='1';
                    findisland(grid,visited,i+1,j);
                    findisland(grid,visited,i-1,j);
                    findisland(grid,visited,i,j+1);
                    findisland(grid,visited,i,j-1);
                }
            }
        }
        return ans;
    }
};
//BFS
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        queue<int>q;
        vector<vector<int>>visited(row,vector<int>(col));
        vector<int>x_direction={0,-1,0,1};
        vector<int>y_direction={1,0,-1,0};
        int ans=0;
        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                if(visited[i][j]==1 || grid[i][j]=='0')continue;
                q.push(i*col+j);
                while(!q.empty()){
                    int position=q.front();q.pop();
                    for(int k=0;k<=3;k++){
                        int x=position%col+x_direction[k];
                        int y=position/col+y_direction[k];
                        if(0<=x && x<col && 0<=y && y<row){
                            if(visited[y][x]==0 && grid[y][x]=='1'){
                                visited[y][x]=1;
                                q.push(x+y*col);
                            }
                        }
                    }
                }
                ++ans;
            }
        }
        return ans;
    }
};