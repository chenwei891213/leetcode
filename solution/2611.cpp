//My solution 
class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int ans=0;
        vector<int>temp;
        for(int i=0;i<reward1.size();i++){
            ans+=reward1[i];
            temp.push_back(reward2[i]-reward1[i]);
        }
        sort(temp.begin(),temp.end(),greater<int>());
        for(int i=0;i<temp.size()-k;i++)ans+=temp[i];
        return ans;
    }
};
//Other people solution 
class Solution {
public:
    int miceAndCheese(vector<int>&r1, vector<int>& r2, int k) {
    	priority_queue<int>pq;
        long long int ans=0;
        for(int i=0;i<r1.size();i++){
        	pq.push(r1[i]-r2[i]);
        	ans+=r2[i];
        }
        while(k!=0){
        	ans+=pq.top();
            pq.pop();
            k--;
        }
        return ans;
    }
};