//Solution 1
//Hash Table, Sliding Window
//Time Complexity O(n)
//Space Complexity O(1)
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> pv(128,0), sv(128,0), res;
        if(s.size() < p.size())
           return res;
        // fill pv, vector of counters for pattern string and sv, vector of counters for the sliding window
        for(int i = 0; i < p.size(); ++i)
        {
            ++pv[p[i]-'a'];
            ++sv[s[i]-'a'];
        }
        if(pv == sv)
           res.push_back(0);

        //here window is moving from left to right across the string. 
        //window size is p.size(), so s.size()-p.size() moves are made 
        for(int i = p.size(); i < s.size(); ++i) 
        {
             // window extends one step to the right. counter for s[i] is incremented 
            ++sv[s[i]-'a'];
            
            // since we added one element to the right, 
            // one element to the left should be discarded. 
            //counter for s[i-p.size()] is decremented
            --sv[s[i-p.size()]-'a']; 

            // if after move to the right the anagram can be composed, 
            // add new position of window's left point to the result 
            if(pv == sv)  // this comparison takes O(26), i.e O(1), since both vectors are of fixed size 26. Total complexity O(n)*O(1) = O(n)
               res.push_back(i-p.size()+1);
        }
        return res;
    }
};

//Solution 2 
//Simplified Version
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        unordered_map<char, int> map;
        for(auto c: p) map[c]++;
        int i = 0, j = 0, count = p.size();
        while(j < s.size()){
            if(map[s[j++]]-- > 0) count--;
            while(count == 0){
                if(j - i == p.size()) res.push_back(i);
                if(map[s[i++]]++ == 0) count++;
            }
        }
        return res;
    }
};
