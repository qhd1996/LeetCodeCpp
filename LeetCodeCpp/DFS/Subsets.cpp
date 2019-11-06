//Array, DFS
//Time Complexity O(2 ^ n), but considering the copy of each tmp to res, it should be O(n * //2^n)
//Space Complexity O(n ^ 2)

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector <int> > res;
        vector<int> tmp;
        search(nums, 0,tmp, res);
        
        return res;
        
    }
private:
    void search(vector<int>& nums, int start, vector<int>& tmp, vector<vector <int> >& res){
        if(start == nums.size()){
            res.push_back(tmp);
            return;
        }
        
        tmp.push_back(nums[start]);
        search(nums, start + 1, tmp, res);
        tmp.pop_back();
        search(nums, start + 1, tmp, res);
    }
};
