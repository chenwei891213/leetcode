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
//This method uses two pointers, l representing the buy position and r representing the sell position. 
//If the difference between the values of pointer r and l is greater than zero, 
//then update the answer by choosing the maximum value between prices[r]-prices[l] and the current answer. 
//If not, move the l pointer to the position of r and increment r by 1. 
//The concept of this method is quite special, and I couldn't come up with it when I tried to solve this problem.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0;
        int r=1;
        int ans=0;
        while(r<prices.size()){
            if(prices[r]-prices[l]>0)ans=max(ans,prices[r]-prices[l]);
            else l=r;
            ++r;
        }
        return ans;
    }
};