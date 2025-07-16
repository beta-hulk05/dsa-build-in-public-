#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int func(int n , vector<int>& dp){
        if(n == 0) return 1;
        if(n < 0) return 0;
        if(dp[n] != -1) return dp[n];
        int step1 = func(n-1 , dp);
        int step2 = func(n-2 , dp);
        return dp[n] = step1 + step2;
    }
public:
    // memoization
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return func(n, dp);
    }
    // tabulation
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for(int i = 1; i <= n; i++){
            if(i==1) dp[i] = 1;
            else{
                dp[i] = dp[i-1] + dp[i-2];
            }
        }
        return dp[n];
    }
};