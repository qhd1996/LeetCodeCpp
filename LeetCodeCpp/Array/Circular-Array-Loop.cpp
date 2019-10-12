//Two Pointer
//Time Complexity O(n)
//Space Complexity O(n)

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
    	// check for which node is visited
    	vector<int> visited(nums.size(), 0);
        
		for(int i = 0; i< nums.size(); i++){
			if(visited[i]) 
                continue;
            
			vector<int> vs(nums.size(), 0);
			// check for circle
			if(has_circular(i, nums, vs)) {
				return true;
			} else {
				for(int i = 0;i < nums.size();i++)
					if(vs[i]) visited[i] = vs[i];
			}
		}        
		return false;
    }
    
    
    int getNext(int i, vector<int>& nums) {
    	int res = i + nums[i];
    	while(res < 0) res += nums.size();
    	return res % nums.size();
    }

    bool has_circular(int i, vector<int>& nums, vector<int>& visited) {
    	int next = getNext(i, nums);
    	// check for whether next node is self
    	if(next == i) {
    		visited[i] = true;
    		return false;
    	}
        //Check whether next node is in the loop
    	if(visited[next]) return true;
        //check whether the direction is consistent
    	if(nums[next] * nums[i] < 0) return false;
        //mark the node visited
    	visited[next] = true;
    	return has_circular(next, nums, visited);
    }
};
