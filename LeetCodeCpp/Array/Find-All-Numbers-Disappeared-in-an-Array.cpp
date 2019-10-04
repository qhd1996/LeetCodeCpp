/**
This problem does not allow sorting or hashtable, and the answer is quite clever.
First we iterate through the input array and mark elements as negative using nums[nums[i] -1] = -nums[nums[i]-1](only change once). 
In this way all the numbers that we have seen will be marked as negative. 
In the second iteration, if a value is not marked as negative,  it implies we have never seen that index before, so just add it to the return list.
**/
//Index
//Time Complexity O(n)
//Space Complexity O(1)

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            int val = abs(nums[i]) - 1;
            if(nums[val] > 0)
                nums[val] = -nums[val];
        }
        
        vector<int> returnList;
        
        for(int j = 0; j < nums.size(); j++){
           if(nums[j] > 0)
               returnList.push_back(j + 1);
        }
        
        return returnList;
    }
};
