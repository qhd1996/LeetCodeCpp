//Array, Binary Search
//Time Complexity O(log(m) + log(n))
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
