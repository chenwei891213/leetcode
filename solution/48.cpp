class Solution {
    public:
        void rotate(vector<vector<int>>& matrix) {
            int n = matrix.size() - 1;
            int left = 0, right = matrix.size() - 1;
            while(left < right){
                for(int i = 0; i < (right-left); ++i){
                    int temp = matrix[left][left+i];
                    matrix[left][left+i] = matrix[n-left-i][left];
                    matrix[n-left-i][left] = matrix[n-left][n-left-i];
                    matrix[n-left][n-left-i] = matrix[left+i][n-left];
                    matrix[left+i][n-left] = temp;
                }
                left++;
                right--;
            }
        }
    };