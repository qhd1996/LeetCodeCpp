//Time complexity O(n)
//Space Complexity O(n)

class Solution {
public:
    int fib(int N) {
        if(N <= 1)
            return N;
        return fib(N - 1) + fib(N - 2);
    }
};
