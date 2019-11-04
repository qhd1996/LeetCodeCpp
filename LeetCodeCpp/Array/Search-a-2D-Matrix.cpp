//Array, Binary Search
//Time Complexity O(log(m * n))
//Space Complexity O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) return false;
        int lo = 0, hi = matrix.size() * matrix[0].size() - 1;
        while (lo <= hi){
            int mid = lo + (hi - lo) / 2, x = mid / matrix[0].size(), y = mid % matrix[0].size();
            if (matrix[x][y] == target) return true;
            if (matrix[x][y] > target) 
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        return false;
    }
};

//Solution2
//Array 
//Time Complexity O(m + n)
//Space Complexity O(1)

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        if(matrix.empty()) return false;
        int m = matrix.size(), n = matrix[0].size(), row = 0, col = n-1;
        while( row < m && col >= 0){
            if(matrix[row][col]==target) return true;
            else if(matrix[row][col] < target) row++;
            else col--;
        }
        return false;
    }
};
