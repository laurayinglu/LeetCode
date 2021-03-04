// https://leetcode.com/problems/count-primes/
// Sieve of Eratosthenes
class Solution {
public:
    // solution 1: by comparison, we found that smaller factor is within [1, sqrt(x)]
    // O(nsqrt(n))
    // TLE
//     bool isPrime(int n) {

//         for (int i = 2; i*i <= n; i++) { // even number is not prime
//             if (n % i == 0)
//                 return false;
//         }
        
//         return true;
//     }
        
//     int countPrimes(int n) {
//         int ans = 0;
//         for (int i = 2; i < n; i++) {
//             if (isPrime(i))
//                 ans++;
//         }
        
//         return ans;
//     }
    
// solution 2: optimize isPrime, make it faster
//        bool isPrime(int n) {
//         if (n <= 1)
//             return false;
//         if (n <= 3)
//             return true;

//         // This is checked so that we can skip
//         // middle five numbers in below loop
//         if (n % 2 == 0 || n % 3 == 0)
//             return false;

//         for (int i = 5; i * i <= n; i = i + 6)
//             if (n % i == 0 || n % (i + 2) == 0)
//                 return false;

//         return true;
//     }
    
//     int countPrimes(int n) {
//         int res = 0;
//         int x = n-1;
        
//         while (x >= 1) {
          
//             // check if prime number 
//             if (isPrime(x)) {
//                 res++;
//                 //cout << x << endl;
//             }
//             x--;
//         }
        
//         return res;
    
    
// solution 3: Sieve of Eratosthenes
// eg. prime = 3; mark 3*3, 3*4, 3*5, ... , < n to be isPrime(i) = 0;
    
    int countPrimes(int n) {
        if (n <= 2)
            return 0;
        vector<int> isPrime(n,1); // initialize to be true
        isPrime[0] = isPrime[1] = 0;
        int ans = 1; // isPrime[2] = 1
        for (int i = 3; i < n; i+=2) { // even number is not prime
            if (isPrime[i]) {
                ans += 1;
                if ((long long)i*i < n){
                    for (int j = i*i; j < n; j+=2*i) { // skip even number
                        isPrime[j] = 0;
                    }
                }
            }
        }
        
        return ans;
    }
};