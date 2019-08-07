//Hash Table
//Time Complexity O(n)
//Space Complexity O(n)

class Solution {
public:
    int tran(int n){
        int ans = 0;
        while(n){
            ans += pow(n%10, 2);
			n/=10;
        }
        return ans;
    }
    
    bool isHappy(int n) {
        bool rep[1000];
        memset(rep, 0, sizeof(rep));
		n = tran(n);
        while(!rep[n]){
			rep[n] = true;
            if(n == 1)
                return true;   
			n = tran(n);
        }
        return false;
    }
};
