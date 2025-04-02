class Solution {
    public:
        void find(int index, vector<int> element, vector<int> &table, vector<vector<int>> &ans, int k){
            if(element.size() == k){
                ans.push_back(element);
                return;
            }
            if(index >= table.size() || (table.size() - index) < k - element.size())return;
            for(int i = index; i < table.size(); ++i){
                element.push_back(table[i]);
                find(i+1, element, table, ans, k);
                element.pop_back();
            }
            return;
        }
    
    
        vector<vector<int>> combine(int n, int k) {
    
            vector<int>table;
            vector<vector<int>> ans;
            vector<int>element;
            for(int i = 1; i <= n; ++i)table.push_back(i);
            find(0, element, table, ans, k);
            return ans;
        }
    };