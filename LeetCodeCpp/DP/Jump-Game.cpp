//Array, DP
//Time Complexity O(n)
//Space Complexity O(1)

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 1) 
            return true;
        
        int reach = 0;
        
        for(int i = 0; i <= reach; i++){
            if(nums[i] + i > reach){
                if(nums[i] + i >= n - 1)
                    return true;
                else
                    reach = nums[i] + i;
            }
        }
        
        return false;
        
    }
};
