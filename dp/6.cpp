class Solution {
  public:
  int fun(string& s,string& t,int x, int y,vector<vector<int>>& dp)
  {
      if(dp[x][y]!=-1)
      return dp[x][y];
      
      if(x==0)
      return y;
      
      if(y==0)
      return x;
      
      if(s[x-1]==t[y-1])
      return fun(s,t,x-1,y-1,dp);
      
      else
      {
         
	// given three choises	
	// insert method
         
         int a = fun(s,t,x,y-1,dp);
         
         // removing it 
         
         int b= fun(s,t,x-1,y,dp);
         
         // replacing it 
         
         int c = fun(s,t,x-1,y-1,dp);
         
         dp[x][y]= 1+min(a,min(b,c));
         
         return dp[x][y];
      }
  }
  
    int editDistance(string s, string t) 
    {
        int x = s.size();
        
        int y = t.size();
        
        vector<vector<int>>dp(x+1,vector<int>(y+1,-1));
        
        int ans;
        
         ans = fun(s,t,x,y,dp);
         
         return ans;
        
    }
};
