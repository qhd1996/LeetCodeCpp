//Solution1 
//Hash Table
//Time Complexity O(n)
//Space Complexity O(1)
//Hash Table
//Time Complexity O(n)
//Space Complexity O(1)

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char alpha[128];
        fill_n(alpha, 128, -1);
        bool use[128] = {false};
        for(int i = 0; i< s.length(); i++){
            if(alpha[s[i]] == -1){
                if(use[t[i]])
                    return false;
                else{
                    alpha[s[i]] = t[i];
                    use[t[i]] = true;
                }
            }
            else if(alpha[s[i]] != t[i])
                return false;
            else 
                continue;
        }
        return true;
}
};


//solution 2
//No Hash Table
//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    bool isIsomorphic(string s, string t) {
    int cs[128] = {0}, ct[128] = {0};
    for(int i=0; i<s.size(); i++)
    {
        if(cs[s[i]] != ct[t[i]]) return false;
        else if(!cs[s[i]]) //only record once
        {
            cs[s[i]] = i+1;
            ct[t[i]] = i+1;
        }
    }
    return true;
}
};
