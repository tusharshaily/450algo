class Solution{
public:
    int equalPartition(int n, int arr[])
    {
        long long int t = 0;
        
        for( int i=0;i<n; i++)
        {
            t+=arr[i];
        }
        
        if(t%2==0)
        {
            t=t/2;
            
            vector<vector<int>>dp(n+1,vector<int>(t+1));
            
            // intialization 
            
            for(int i=0; i<=n; i++ )
            {
                dp[i][0]=1;
            }
            
            for(int i =1;i<=t;i++)
            {
                dp[0][i]=0;
            }
            
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=t;j++)
                {
                    if(j<arr[i-1])
                    {
                        dp[i][j]=dp[i-1][j];
                    }
                    else
                    dp[i][j] = dp[i-1][j]||dp[i-1][j-arr[i-1]];
                }
            }
            
            return dp[n][t];
        }
        return 0;
    }
};
