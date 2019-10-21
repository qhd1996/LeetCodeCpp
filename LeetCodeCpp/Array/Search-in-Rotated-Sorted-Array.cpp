//Arrary, Binary Search
//Time Complexity o(logn)
//Space Complexity O(1)

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l =0, h = nums.size()-1;
        while(l <= h){
            int mid = l + (h - l) / 2;
            
            //target found
            if(nums[mid] == target) 
                return mid; 
            
            //subarray from l to mid is sorted
            if(nums[l] < nums[mid]){
                if(target >= nums[l] && target < nums[mid])
                    //target is between l to mid then reduce search space to l...mid-1
                    h = mid-1;
                else
                    // target is not in the first half search the other half from mid+1 to h
                    l = mid+1;    
            }
            
            //implies that mid to h is sorted as this is a sorted rotated array
            else if(nums[l] > nums[mid]){
                //target is in between mid to high, search mid+1 to h
                if(target <= nums[h] && target > nums[mid])
                    l = mid+1;
                // target not in the above portion search the left half from l to mid-1
                else
                    h = mid-1;   
            }
            
            //when nums[l] == nums[mid] we're not sure what to do so move right;
            else l++; 
        }
        return -1;
    }
};
