//Array, DFS
//Time Complexity O(n^2)
//Space Complexity O(n)

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
        vector<vector<int> > result;
        sort(candidates.begin(), candidates.end());
        vector<int> pSol;
        search(candidates, 0, pSol, target, result);
        return result;    
    }
    
    void search(vector<int>& candidates, int next, vector<int>& pSol, int target, vector<vector<int> >& result){  
        
        if (target == 0) {
            result.push_back(pSol);
            return;
        }
        
        int n = candidates.size();
        int i = next;
        while(i < n  && target - candidates[i] >= 0) {
            // NOTE : this condition helps neglecting making identical sets
            //  this is the catch of this question
            if (i == next || candidates[i] != candidates[i-1]) {
                pSol.push_back(candidates[i]);
                search(candidates, i + 1, pSol, target - candidates[i], result);
                pSol.pop_back();
            }
            i++;
        }
    }
};
