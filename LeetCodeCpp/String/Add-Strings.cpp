//String
//Time Complexity O(max(m, n))
//Space Complexity O(m + n)

class Solution {
public:
    string addStrings(string num1, string num2) {
        int carry=0;
        string result;
             
        string *pnum1,*pnum2;
        if (num1.size() > num2.size()){
            pnum1=&num1;
            pnum2=&num2;
        } else {
            pnum1=&num2;
            pnum2=&num1;
        }
        int size1 = pnum1->size();
        int size2 = pnum2->size();
        int max = size1;
        
        char cres[max+2];
        char *pcres = cres;
        for (int i = 1;i <= max;i++) {
            int p1 = size1 - i;
            int p2 = size2 - i;
            
            int val1 = (*pnum1)[p1] - '0';
            int val2 = p2 >= 0? (*pnum2)[p2] -'0' : 0;
            int val = val1 + val2 + carry;
            carry = val / 10;
            val = val % 10;
            
            //printf("val1 %d val2 %d carry %d\n", val1, val2, carry);
            
            *pcres++ = char(val + '0');
        }
        if (carry) {
            *pcres++ = char(carry + '0');
        }
        *pcres++ = '\0';
        
        result = string(cres);
        reverse(result.begin(), result.end());
        
        return result;
    }
};
