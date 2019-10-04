//Time complexity O(n)
//Space Complexuty O(1)

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;  //Rerord the length of the consecutive ones
        int max_len = 0; //Rerord the max length of the consecutive ones
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 1)
                count ++;
            else{
                if(max_len < count)
                    max_len = count;
                count = 0;
            }
        }
        
        //Boundary case, when the loop ends
        if(max_len < count)
                    max_len = count;
        
        return max_len;

    }
};
