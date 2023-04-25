class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int left=0;
        int right=n-1;
        int ans=0;
        while(left<right){
            if(height[left]<height[right]){
                ans=max(ans,height[left]*(right-left));
                ++left;
            }
            else{
                ans=max(ans,height[right]*(right-left));
                --right;
            }
        }
        return ans;
    }
};
//Clear code 
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int left=0;
        int right=n-1;
        int ans=0;
        while(left<right){
            ans=max(ans,min(height[left],height[right])*(right-left));
            height[left]<height[right]?left++:right--;
        }
        return ans;
    }
};