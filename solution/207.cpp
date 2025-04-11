//first try
class Solution {
    public:
        bool dfs(unordered_map<int, vector<int>>& table, vector<bool>& visited, int course){
            if(visited[course])return false;
            else if(!table.count(course) || table[course].size() == 0)return true;
            visited[course] = true;
            for(int c : table[course]){
                if(!dfs(table, visited, c))return false;
                table[course].erase(
                    std::remove(table[course].begin(), table[course].end(), c),
                    table[course].end()
                );
                visited[c] = false;
            }
            visited[course] = false;
            return true;
        }
  
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            unordered_map<int, vector<int>> table;
            vector<bool> visited(numCourses, false);
            for(auto t : prerequisites)table[t[0]].push_back(t[1]);
    
            for(int i = 0; i < numCourses; ++i){
                if(!table.count(i))continue;
                if(dfs(table, visited, i))continue;
                else return false;
            }
            return true;
        }
    };
    

// revision
class Solution {
    public:
        bool canFinishCourse(vector<vector<int>>& table, vector<int>& visited, int course){
            if(visited[course] == -1) return false;
            if(visited[course] == 1) return true;
            visited[course] = -1;
            for(auto a : table[course]){
                if(!canFinishCourse(table, visited, a)) return false;
            }
            visited[course] = 1;
            return true;
        }
    
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            
            vector<vector<int>> table(numCourses, vector<int>());
            vector<int> visited(numCourses, 0);
            for(auto t : prerequisites)table[t[0]].push_back(t[1]);
    
            for(int i = 0; i < numCourses; ++i){
                if(!canFinishCourse(table, visited, i)) return false;
            }
            return true;
        }
    };



// BFS solution
class Solution {
    public:
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
            vector<vector<int>> graph(numCourses, vector<int>());
            vector<int> inDegree(numCourses, 0);
            queue<int> list;
            for(auto prerequisite : prerequisites){
                graph[prerequisite[0]].push_back(prerequisite[1]);
                inDegree[prerequisite[1]]++;
            }
            for(int i = 0; i < inDegree.size(); ++i){
                if(inDegree[i] == 0) list.push(i);
            }
            int finishCourses = 0;
            while(!list.empty()){
                int p = list.front(); list.pop();
                finishCourses ++;
                for(int neighbor : graph[p]){
                    inDegree[neighbor] --;
                    if(inDegree[neighbor] == 0) list.push(neighbor);
                }
            }
            return finishCourses == numCourses;
        }
    };


