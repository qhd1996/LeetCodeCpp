//DFS
//Time Complexity O(1)
//Space Complexity O(1)

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        string ip;
        //paras:string s,start index of s,step(from0-3),intermediate ip,final result
        dfs(s, 0, 0, ip, result); 
        return result;
    }
    void dfs(string s,int start,int step,string ip,vector<string>& result){
        if(start == s.size() && step == 4){
            ip.erase(ip.end() - 1); //remove the last '.' from the last decimal number
            result.push_back(ip);
            return;
        }
        /*
        An IP address contains four 8-bit unsigned integers, which means they range from 0 to 255, which means 1 to 3 digits, but 4 digits if we include the dot. The first if statement checks whether it exceeds the amount of digits possible left for an IP address, and the second if statement checks whether we have enough digits left given the current progress.
        */
        if(s.size() - start > (4 - step) * 3) return;
        if(s.size() - start < (4 - step)) return;
        int num=0;
        for(int i = start; i < start + 3; i++){
            num = num * 10 + (s[i] - '0');
            if(num <= 255){
                ip += s[i];
                dfs(s, i+1, step+1, ip + '.', result);
            }
            if(num==0) break;
        }
    }
};
