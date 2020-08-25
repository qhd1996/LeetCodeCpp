//前缀积,后缀积
//时间复杂度O(n)
//空间复杂度O(n)
//原始方法
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> fwd(n, 1), bwd(n, 1), res(n);
        for (int i = 0; i < n - 1; i++) {
            fwd[i + 1] = fwd[i] * nums[i];
        }
        for (int i = n - 1; i > 0; i--) {
            bwd[i - 1] = bwd[i] * nums[i];
        }
        for (int i = 0; i < n; i++) {
            res[i] = fwd[i] * bwd[i];
        }
        return res;
    }
};

//优化版本
//时间复杂度O(n)
//空间复杂度O(1),不使用辅助数组
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(), 1);
        for(int i = 1; i < nums.size(); i++){
            res[i] = res[i - 1] * nums[i - 1];
        }
        int right = 1;
        for(int i = nums.size() - 1; i >= 0; i--){
            res[i] *= right;
            right *= nums[i];
        }
        return res;
    }
};
