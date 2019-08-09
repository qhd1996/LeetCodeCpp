//Hash Table
//Time Complexity O(n)
//Space Complexity O(1)

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, int> p2i;
        unordered_map<string, int> w2i;
        stringstream in(str);
        int i = 0, n = pattern.size();
        for (string word; in >> word; ++i) {
            if (p2i[pattern[i]] != w2i[word])
                return false;
            p2i[pattern[i]] = w2i[word] = i + 1;
        }
        return i == n;
    }
};
