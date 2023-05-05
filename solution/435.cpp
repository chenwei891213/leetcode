class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int ans=0;
        int temp=intervals[0][1];
        for(int i=1;i<intervals.size();++i){
            if(intervals[i][0]<temp){
                ++ans;
                temp=intervals[i][1]<temp?intervals[i][1]:temp;
            }
            else{
                temp=intervals[i][1];
            }
        }
        return ans;
    }
};