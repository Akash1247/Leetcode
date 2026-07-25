class Solution {
public:
    const int mod=1e9+7;
    int solve(int n){
        if(n<=2)return n;
        if(n==3)return 5;
        vector<long>dp(n+1);
        dp[1]=1;
        dp[2]=2;
        dp[3]=5;
        for(int i=4;i<=n;i++){
            dp[i]=((dp[i-1]*2)%mod+(dp[i-3])%mod)%mod;
        }
        return dp[n];
    }
    int numTilings(int n) {
        return solve(n);
    }
};