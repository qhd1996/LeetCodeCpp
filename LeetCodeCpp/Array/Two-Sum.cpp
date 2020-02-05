//Hash Table
//A little tricky
//Time Complexity O(n)
//Space Complexity O(n)

class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> res;
        
        for(int i = 0; i < nums.size(); i++){
            if (map.find(nums[i]) == map.end()){ 
                // store the first one poisition into the second one's key
                map[target - nums[i]] = i; 
            }else { 
                // found the second one
                res.push_back(map[nums[i]]);
                res.push_back(i);
                break;
            }
        }
        return res;
    }
          
};
