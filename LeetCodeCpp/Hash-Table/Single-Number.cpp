//Solution1
//Hash Table
//Time Complexity O(n)
//Space Complexity O(n)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> map;
        for (auto const& i: nums){
            if(map.find(i) != map.end())
                map.erase(i);
            else
                map.insert({i, 1});
        }
        return map.begin()->first;
    }
};

//Solution 2
//Math
//Time Complexity O(n)
//Space Complexity O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
      set<int> set(nums.begin(), nums.end());
      
      return 2* accumulate(set.begin() , set.end(), 0) - accumulate(nums.begin() , nums.end(), 0);
        
    }
};

//Solution 3
//Bit Manipulation
//Time Complexity O(n)
//Space Complexity O(1)

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0;
        
        for(auto const i: nums){
            a ^= i;
        }
        
        return a;
        
    }
};

