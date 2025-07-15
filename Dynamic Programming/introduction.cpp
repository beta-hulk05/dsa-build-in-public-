#include<bits/stdc++.h>
using namespace std;
class Solution {
    int mod = 1e9 + 7;
    private:
    long long int func(int n, vector<int>& dp){
        if(n <= 1) return n;
        if(dp[n] != -1) return dp[n];
        return dp[n] =  (func(n-1, dp) + func(n-2, dp)) % mod;
    }
    
  public:
    long long int topDown(int n) {
        vector<int> dp(n+1 , -1);
        return func(n, dp);
        
        
    }

    long long int bottomUp(int n) {
        if(n == 0) return 0;
        vector<int> dp(n+1);
        // dp[0] = dp[1] = 1;
        dp[0] = 0; dp[1] = 1;
        for(int i = 2; i <= n; i++){
            dp[i] = (dp[i-1] + dp[i-2]) % mod;
        }
        return dp[n];
    }
};