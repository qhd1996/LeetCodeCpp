//Hash Table
//Time Complexity O(n)
//Space Complexity O(n)

class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mapping;
        vector<int> result;
        for(int i = 0; i<nums.size(); i++){
            mapping[nums[i]] = i;
        }
        for(int i =0; i<nums.size(); i++){
            const int difference = target - nums[i];
            if(mapping.find(difference) != mapping.end() &&         mapping[difference]>i){
                result.push_back(i);
                result.push_back(mapping[difference]);
                break;
            }
        }
        return result;
    }
};
