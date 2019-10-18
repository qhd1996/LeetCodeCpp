//a / b = exp(loga - logb)
//Time Complexity O(1)
//Space Complexity O(1)

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        if (divisor == 0) return INT_MAX;
        long long res = double(exp(log(fabs(dividend))-log(fabs(divisor))));
        if ((dividend < 0)^( divisor < 0)) res = -res;
        if (res > INT_MAX) res = INT_MAX;
        return res;
    }
};

//Time Complexity O(nlogn)
//Space Complexity O(1)

class Solution {
public:
    int divide(int dividend, int divisor) {
        //Boundary case
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        long dvd = labs(dividend), dvs = labs(divisor), ans = 0;
        int sign = dividend > 0 ^ divisor > 0 ? -1 : 1;
        while (dvd >= dvs) {
            long temp = dvs, m = 1;
            while (temp << 1 <= dvd) {
                temp <<= 1;
                m <<= 1;
            }
            dvd -= temp;
            ans += m;
        }
        return sign * ans;
    }
};
