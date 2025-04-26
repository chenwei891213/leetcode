class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int row = matrix.size(), col = matrix[0].size();
            int left = 0, right = row-1;
            while(left <= right){
                int mid = (left+right)/2;
                if(matrix[mid][0] >= target) right = mid-1;
                else left = mid+1;
            }
            int m = left;
            if(m == 0 && matrix[m][0] != target) return false;
            else if(m < row && matrix[m][0] == target) return true;
            left = 0; 
            right = col-1;
            while(left <= right){
                int mid = (left+right)/2;
                if(matrix[m-1][mid] == target) return true;
                else if(matrix[m-1][mid] >= target) right = mid-1;
                else left = mid+1;
            }
            return false;
    
        }
    };


// simplified version
class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int row = matrix.size(), col = matrix[0].size();
            int left = 0, right = row-1;
            while(left <= right){
                int mid = (left+right)/2;
                if(matrix[mid][0] == target) return true;
                else if(matrix[mid][0] > target) right = mid-1;
                else left = mid+1;
            }
            int m = left > 0 ? left - 1 : left;
            left = 0; 
            right = col-1;
            while(left <= right){
                int mid = (left+right)/2;
                if(matrix[m][mid] == target) return true;
                else if(matrix[m][mid] > target) right = mid-1;
                else left = mid+1;
            }
            return false;
    
        }
    };

// Use 1D binary search
class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int m = matrix[0].size(), n = matrix.size();
            int left = 0, right = m*n-1;
            while(left <= right){
                int mid = (left+right) / 2;
                if(matrix[mid/m][mid%m] == target) return true;
                else if(matrix[mid/m][mid%m] < target) left = mid + 1;
                else right = mid - 1;
            }
            return false;
        }
    };