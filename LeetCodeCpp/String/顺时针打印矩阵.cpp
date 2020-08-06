/*
*方法1 模拟
*初始位置是矩阵的左上角，初始方向是向右，当路径超出界限或者进入之前访问过的位置时，则顺时针旋转，进入下*一个方向。
*判断路径是否进入之前访问过的位置需要使用一个与输入矩阵大小相同的辅助矩阵visited
*如何判断路径是否结束？由于矩阵中的每个元素都被访问一次，因此路径的长度即为矩阵中的元素数量
*时间复杂度 O(mn)
*空间复杂度 O(1)
*/


class Solution {
private:
    /* 顺时针方向 右 下 左 上*/
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0){
            return {};
        }

        int rows = matrix.size(), columns = matrix[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(columns));
        int total = rows * columns;
        int row = 0, column = 0;
        int direction = 0;
        vector<int> res(total);

        for(int i = 0; i < total; i++){
            res[i] = matrix[row][column];
            visited[row][column] = true;
            int nextRow = row + directions[direction][0], nextColumn = column + directions[direction][1];
            if (nextRow < 0 || nextRow >= rows || nextColumn < 0 || nextColumn >= columns || visited[nextRow][nextColumn]) {
                direction = (direction + 1) % 4;
            }
            row += directions[direction][0];
            column += directions[direction][1];
        }
        return res;
    }
};

/*
*方法2 分层模拟
*一层一层遍历
*每层的顺序都是上右下左
*时间复杂度O(mn)
*空间复杂度O(1)
*/


class Solution {
private:
    /* 顺时针方向 右 下 左 上*/
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0 || matrix[0].size() == 0){
            return {};
        }

        int rows = matrix.size(), columns = matrix[0].size();
        vector<int> res;
        int left = 0, right = columns - 1, top = 0, bottom = rows - 1;
        while (left <= right && top <= bottom) {
            /* 上 */
            for (int column = left; column <= right; column++) {
                res.push_back(matrix[top][column]);
            }
            /* 右 */
            for (int row = top + 1; row <= bottom; row++) {
                res.push_back(matrix[row][right]);
            }
            /* 防止重复访问 */
            if(left < right && top < bottom){
                /* 下 */
                for (int column = right - 1; column > left; column--) {
                    res.push_back(matrix[bottom][column]);
                }
                /* 左 */
                for (int row = bottom; row > top; row--) {
                    res.push_back(matrix[row][left]);
                }
            }
            
            left++;
            right--;
            top++;
            bottom--;
        }
        return res;
    }
};
