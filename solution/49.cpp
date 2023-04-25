//Use Hash table
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>count;
        vector<vector<string>>ans;
        for(int i=0;i<strs.size();i++){
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            count[temp].push_back(strs[i]);
        }
        for(auto i:count){
            ans.push_back(i.second);
        }
        return ans;
    }
};