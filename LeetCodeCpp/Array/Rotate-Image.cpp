//Array
//Time Complexity O(n^2)
//Space Complexity O(n)
//First transpose, then exchange column i and n - 1 - i
//If rotate the image by 90 degrees(anticlockwise), the second step should be //exchanging row i and n - 1 - i

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int d = matrix.size();
        vector<int> tmp_vec(d, 0);
        for(int i = 0; i < d; i++){
            for(int j = i; j < d; j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }     
        for(int m = 0; m < d / 2; m++){
            for(int n = 0; n < d; n++){
                int tmp = matrix[n][m];
                matrix[n][m] = matrix[n][d - 1 - m];
                matrix[n][d - 1 - m] = tmp;
            }
        }
        
                
    }
};
