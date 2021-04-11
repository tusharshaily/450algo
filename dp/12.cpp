int a;
int b;
int c;

int rec(int n, vector<int>&dp)
{
    if(n<0)
    return INT_MIN;
    
    if(n==0)
    return 0;
    
    if(dp[n]!=-1)
    return dp[n];
    
    int c1=1+rec(n-a,dp);
    
    int c2=1+rec(n-b,dp);
    
    int c3=1+rec(n-c,dp);
    
    dp[n]=max(c1,max(c2,c3));
    
    return dp[n];
    
}
int maximizeTheCuts(int n, int x, int y, int z)
{
    //Your code here
    a=x;
    b=y;
    c=z;
    vector<int>dp(n+1,-1);
    
    dp[0]=0;
    
    int ans = rec(n,dp);
    
    if(ans<0)
    return 0;
    else
    return ans;
}
