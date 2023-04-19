//Traverse the prices array and record lower price,then update the ans by prices[i] minus lowprice.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int lowprice=prices[0];
        int ans=0;
        for(int i=1;i<prices.size();i++){
            lowprice=min(lowprice,prices[i]);
            ans=max(ans,prices[i]-lowprice);
        }
        return ans;
    }
};