//Array
//Time Complexity O(n^2)
//Space Complexity O(n^2)

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>> res(n, vector<int> (n, 1));
        
        int left, right, top, down, index;
        left = top = index = 0, right = down = n-1;
        
        while (left <= right && top <= down) {
            for (unsigned int j = left; j <= right; j++)
                res[top][j] = ++index;
            top++;
            for (unsigned int i = top; i <= down; i++)
                res[i][right] = ++index;
            right--;
            for (int j = right; j >= left; j--)
                res[down][j] = ++index;
            down--;
            for (int i = down; i >= top; i--)
                res[i][left] = ++index;
            left++;
        }
        return res;
    }
};
