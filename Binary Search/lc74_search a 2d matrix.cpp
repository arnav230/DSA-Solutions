class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int low=0;
        int row=matrix.size();
        int col=matrix[0].size();
        int high=(row*col)-1;
        if(target<matrix[0][0] || target>matrix[row-1][col-1]) return false;
        while(low<=high) {
            int mid=low+(high-low)/2;
            int i=mid/col;
            int j=mid%col;
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]<target) low=mid+1;
            else high=mid-1;
        }
        return false;
    }
};
