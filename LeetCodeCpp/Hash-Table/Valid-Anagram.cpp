//Solution 1
//Sorting
//Time Complexity O(nlogn)
//Space Complexity O(1)

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s==t;
    }
};

//Solution 2
//Hash Table
//Time Complexity O(n)
//Space Complexity O(1)

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
        
        int alpha[128] = {0};
        for(int i = 0; i < s.length(); i++){
            alpha[s[i]] += 1;
        }
        for(int j = 0;j < t.length(); j++){
            if(alpha[t[j]] == 0)
                return false;
            else
                alpha[t[j]]--;
        }
        return true;
    }
};

//Hash Table considering unicode
//Time Complexity O(nlogn)
//Space Complexity O(n)

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
        
        unordered_map<char, int> map;
        for(int i = 0; i < s.length(); i++){
            if(map.find(s[i]) == map.end())
                map.insert({s[i], 1});
            else
                map[s[i]] += 1;
        }
        for(int j = 0;j < t.length(); j++){
            if(map.find(t[j]) == map.end() || map[t[j]] == 0)
                return false;
            else
                map[t[j]]--;
        }
        return true;
    }
};
