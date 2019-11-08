//Array, DFS
//Time Complexity O(C(n, k))
//Space Complexity O(k), stack

class Solution {
public: 
    void search(int len, int target, vector<int>&nums, int start, vector<int>& tmp, vector<vector<int> >& res){
        
        if(tmp.size() == len && target == 0){
            res.push_back(tmp);
            return;
        }
        
        if(tmp.size()>len || target<0){
            return;
        }
        
        for(int i  = start; i < nums.size(); i++){
            tmp.push_back(nums[i]);
            search(len, target - nums[i], nums, i + 1, tmp, res);
            tmp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums = {1,2,3,4,5,6,7,8,9};
        vector<vector<int> > res;
        
        //Corner case
        if(k == 0) return res;
        
        //General case
        vector<int> tmp;
        search(k, n, nums, 0, tmp, res);
        
        return res;
        
    }
};
