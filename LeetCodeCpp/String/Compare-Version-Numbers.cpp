//String
//Time Complexity O(m + n)
//Space Complexity O(m + n)

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int len1 = version1.length();
        int len2 = version2.length();
        int i = 0, j = 0;
        string strVer1 = "", strVer2 = "";
        while((i < len1)||(j < len2)) {
            while((i < len1)&&(version1[i] != '.')) {
                strVer1 += version1[i];
                i++;
            }
            while((j < len2)&&(version2[j] != '.')) {
                strVer2 += version2[j];
                j++;
            }
            if(strVer1 == "") {
                if(stoi(strVer2) > 0) return -1;
            } else if(strVer2 == "") {
                if(stoi(strVer1) > 0) return 1;
            } else {
                if(stoi(strVer1) > stoi(strVer2)) return 1;
                else if(stoi(strVer1) < stoi(strVer2)) return -1;
            }
            strVer1 = "";
            strVer2 = "";
            i++;j++;
        }
        return 0;
    }
};
