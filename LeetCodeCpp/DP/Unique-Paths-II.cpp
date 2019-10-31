//DP
//Time Complexity O(m * n)
//Space Complexity O(n)
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        if(obstacleGrid[0][0] == 1)return 0;
    
        vector<long> dp(n);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
            if(obstacleGrid[i][j]) dp[j] = 0;
            else if(i == 0 && j == 0) dp[j] = 1;
            else if(i == 0) dp[j] = dp[j-1];
            else if(j == 0) dp[j] = dp[j];
            else dp[j] += dp[j-1];
        }
    }
    return dp[n-1];
}
};
