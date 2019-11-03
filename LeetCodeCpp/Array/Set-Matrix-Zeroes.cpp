//Array
//Time Complexity O((m + n) * (m + n))
//Space Complexity O(1)

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int MODIFIED = -1000000;
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i  = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    for (int k = 0; k < n; k++){
                        if (matrix[i][k] != 0)
                            matrix[i][k] = MODIFIED;
                    }
                    for (int k = 0; k < m; k++) {
                        if (matrix[k][j] != 0)
                            matrix[k][j] = MODIFIED;
                    }
                }
            }
        }
        
         for(int i  = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if (matrix[i][j] == MODIFIED)
                    matrix[i][j] = 0;
            }
         }
        
    }
};
