// the first method 

cpp_int findCatalan(int n) 
    {
         vector<cpp_int> ans(n+1,0);
    
         ans[0]=1;
         ans[1]=1;
         
         for(int i=2;i<=n;i++)
         {
             for(int j = 0 ;j<i;j++)
             {
                 ans[i]+=(ans[j]*ans[i-j-1]);
             }
         }
         
         return ans[n];
    }

// second method

// using the formula ctalan(n) = 2n!/n!n+1! 
