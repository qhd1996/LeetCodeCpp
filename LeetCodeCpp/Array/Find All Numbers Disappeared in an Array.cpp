//Hash Table
//Time Complexity O(n)
//Space Complexity O(n)
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> key(nums.size() + 1, 0);
    
        for(int i = 0; i < nums.size(); i++){
            key[nums[i]]++;
        }
        
        int smallest = 1;
        int largest = nums.size();
        vector<int> missing;
    
        for(int i = smallest; i <= largest; i++){
            if(key[i] == 0){
             missing.push_back(i);
            }
        }
    return missing;
        
    }
};
