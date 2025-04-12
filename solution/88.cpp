class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int i = nums1.size()-1; 
            int j = m - 1;
            int k = n - 1;
            while(k >= 0){
                nums1[i--] = (j < 0 || nums1[j] < nums2[k]) ? nums2[k--] : nums1[j--];
            }
    
        }
    };