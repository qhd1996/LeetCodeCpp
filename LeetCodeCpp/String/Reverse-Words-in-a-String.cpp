/*
* 从左向右扫描，取出单词，反转单词，拼接成结果串
* 时间复杂度O(n)
* 空间复杂度O(1)
*/
class Solution {
public:
    string reverseWords(string s) {
        string res;
        int i = 0;
        while(i < s.size()){
            //去掉空格
            while(i < s.size() && s[i] == ' ') 
                i++;
            int j = i;
            //取单词
            while(j < s.size() && s[j] != ' ') 
                j++;
            if(j > i){
                string sub = s.substr(i, j-i);
                reverse(sub.begin(), sub.end());
                if(res.size()) 
                    res += ' ';
                res += sub;
            }
            i = j;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
