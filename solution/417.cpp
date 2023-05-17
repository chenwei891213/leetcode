//DFS
class Solution {
public:
    vector<vector<int>>H;
    void find(int x,int y,vector<vector<int>>& N){
        N[x][y]=1;
        if(x-1>=0 && N[x-1][y]==0 && H[x][y]<=H[x-1][y] )find(x-1,y,N);   
        if(y-1>=0 && N[x][y-1]==0 && H[x][y]<=H[x][y-1] )find(x,y-1,N);
        if(x+1<H.size() && N[x+1][y]==0  && H[x][y]<=H[x+1][y] )find(x+1,y,N);
        if(y+1<H[0].size() && N[x][y+1]==0 && H[x][y]<=H[x][y+1] )find(x,y+1,N);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        H=heights;
        vector<vector<int>>P(H.size(),vector<int>(H[0].size(),0));
        vector<vector<int>>A(H.size(),vector<int>(H[0].size(),0));
        vector<vector<int>>ans;
        for(int i=0;i<H[0].size();i++){
            find(0,i,P);
            find(H.size()-1,i,A);
        }
        for(int i=0;i<H.size();i++){
            find(i,0,P);
            find(i,H[0].size()-1,A);
        }
        for(int i=0;i<H.size();i++){
            for(int j=0;j<H[0].size();j++){
                if(P[i][j]==1 && A[i][j]==1)ans.push_back({i,j});
            }
        }
        return ans;
    }
};
//BFS
class Solution {
public:
    vector<vector<int>>H;
    void find(queue<pair<int,int>>q,vector<vector<bool>>& visited){      
        vector<vector<int>>dirs{{0,-1},{0,1},{1,0},{-1,0}};
        while(!q.empty()){
            auto t=q.front();q.pop();
            for(auto dir:dirs){
                int x=t.first+dir[0];int y=t.second+dir[1];
                if(x<0 || x>H.size()-1||y<0 || y>H[0].size()-1||visited[x][y]==true||
                H[t.first][t.second]>H[x][y])continue;
                q.push({x,y});
                visited[x][y]=true;
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        H=heights;
        vector<vector<bool>>P(H.size(),vector<bool>(H[0].size(),false));
        vector<vector<bool>>A(H.size(),vector<bool>(H[0].size(),false));
        queue<pair<int,int>>q1,q2;
        vector<vector<int>>ans;
        for(int i=0;i<H[0].size();i++){
            q1.push({0,i});
            q2.push({H.size()-1,i});
            P[0][i]=true;
            A[H.size()-1][i]=true;
        }
        for(int i=0;i<H.size();i++){
            q1.push({i,0});
            q2.push({i,H[0].size()-1});
            P[i][0]=true;
            A[i][H[0].size()-1]=true;
        }
        find(q1,P);
        find(q2,A);
        for(int i=0;i<H.size();i++){
            for(int j=0;j<H[0].size();j++){
                if(P[i][j]==1 && A[i][j]==1)ans.push_back({i,j});
            }
        }
        return ans;
    }  
};