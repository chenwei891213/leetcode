class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        priority_queue<pair<int, vector<int>>> table;
        for(int i : nums1){
            for(int j : nums2){
                int sum = i + j;
                if(table.size() < k) table.push({sum, {i,j}});
                else if(sum < table.top().first){
                    table.pop();
                    table.push({sum, {i,j}});
                }
                else break;
            }
        }
        while(!table.empty()){
            ans.push_back(table.top().second);
            table.pop();
        }
        return ans;
    }
};