//Array, DFS
//Time Complexity O(n^2)
//Space Complexity O(n)

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > result;
        sort(candidates.begin(), candidates.end());
        
        vector<int> pSol;
        search(candidates, 0, pSol, target, result);
        return result;    
    }
    
private:
    void search(vector<int>& candidates, int next, vector<int>& pSol, int target, vector<vector<int> >& result){
        //Find one solution
        if(target == 0){
            result.push_back(pSol);
            return;
        }
        
        //Find failure
        if(next == candidates.size() || target - candidates[next] < 0)
            return;
        
        //Choose candidate[next]
        pSol.push_back(candidates[next]);
        search(candidates, next, pSol, target - candidates[next], result);
        
        //Do not choose candidate[next]
        pSol.pop_back();
        search(candidates, next + 1, pSol, target, result);
    }
};
