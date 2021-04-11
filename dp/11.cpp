class Solution{
    public:
    const long long int mod = 1e9+7;
    long long countWays(int n, int k){
        // code here
        
        if(n==0) return 0;
        
        if(n==1) return k;
        
        long long int same = k;
        
        long long int diff = k*(k-1);
        
        long long  int prev;
        
        for(int i=3;i<=n;i++)
        {
            prev=diff;
            diff =((same*(k-1))%mod+(prev*(k-1))%mod)%mod;
            same = prev;
        }
        return (same+diff)%mod;
    }
};
