class Solution{
public:

int fun(int i, int j,int n,int m,vector<vector<int>>&dp,vector<vector<int>>&M)
{
    if(dp[i][j]!=-1)
    return dp[i][j];
    
    
    // move up right
    int a =-1;
    
    int b=-1;
    
    int c=-1;
    
    if(i-1>=0 && j+1<m)
    a=fun(i-1,j+1,n,m,dp,M);
    
    // move right
    
    if( j+1<m)
    b=fun(i,j+1,n,m,dp,M);
    
    // move down right
    if(i+1<n && j+1<m)
    c=fun(i+1,j+1,n,m,dp,M);
    
    dp[i][j]=M[i][j]+max(a,max(b,c));
    
    return dp[i][j];
    
}

    int maxGold(int n, int m, vector<vector<int>> M)
    {
        vector<vector<int>>dp(n,vector<int>(m,-1));
        
        for(int i=0;i<n;i++)
        {
            dp[i][m-1]=M[i][m-1];
        }
        
        
        for(int i=0;i<n;i++)
        {
            dp[i][0]=fun(i,0,n,m,dp,M);
        }
        
        int maxi=0;
        
        for(int i=0;i<n;i++)
        {
            maxi=max(maxi,dp[i][0]);   
        }
        return maxi;
    }


};
