//String
//Time Complexity O(n)
//Space Complexity O(1)

class Solution {
public:
    string simplifyPath(string path) {
        deque<string> myDeque;
        istringstream ss(path);
        string str;
        while (getline(ss, str, '/')) 
            if (!str.empty()) {
                if (str == ".." && !myDeque.empty())
                    myDeque.pop_back();
                else if (str != "." && str != "..")
                    myDeque.push_back(str);
            }
        string res = "";
        while (!myDeque.empty()) {
            res += "/" + myDeque.front();
            myDeque.pop_front();
        }
        return res.empty()?"/":res;
    }
};
