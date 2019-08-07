//Solution 1
//Time Complexity O(n^1.5)
//Space Complexity O(1)

class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        for(int i = 1; i < n; i++){
            if(isPrime(i))
                count++;
        }
        return count;
    }

private: 
    bool isPrime(int num){
        if(num <= 1)
            return false; 
        for(int i = 2; i <= sqrt(num); i++){
            if(num % i == 0)
                return false;
        }
        return true;
    }
};

//Solution 2 Sieve of Eratosthenes 
//Time Complexity O(nloglogn)
//Space Complexity O(1)

class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2)
            return 0;
        else{
            int *isPrime = new int[n];
            fill_n(isPrime, n, 1); //cannot use memset
            for(int i = 2; i < sqrt(n); i++){
                if(isPrime[i] == 1){
                    for(int j = 0; i * i + i * j < n ; j++){
                        isPrime[i * i + i * j] = 0;
                    }
                }
            }
            int count =  accumulate(isPrime, isPrime + n, 0) - 2;
            delete [] isPrime;
            return count;
        }     
    }

};

