class Solution {
private:
    int size;
    //return 2^n unique sets where n is determined by pos;
    void search(vector<int>& nums, int pos, vector<int>& v, vector<vector<int>>& vv)
    {
        vv.push_back(v);
        for(int i = pos; i < size; ++i)
        {
            if(i==pos || nums[i]!=nums[i-1])
            {
                v.push_back(nums[i]);
                search(nums, i+1, v, vv);
                v.pop_back();
            }
        }
    }
public:
    //AC - recursive method;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        size = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> vv;
        vector<int> v;
        search(nums, 0, v, vv);
        return vv;
    }
};
