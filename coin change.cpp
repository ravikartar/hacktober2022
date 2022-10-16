{
 
        long long  int  dp[N+1][sum+1];
        for(int i=0;i<N+1;i++){
            dp[i][0]=1;
        }
        for(j=0;j<sum+1;j++){
            dp[0][j]=0;
        }
        for(int i=1;i<=N;i++){
            for(int j=1;j<=sum;j++){
                if(coins[i-1]<=j){
                  dp[i][j] = dp[i-1][j]+dp[i][j-coins[i-1]];
                  
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[N][sum];
    }
