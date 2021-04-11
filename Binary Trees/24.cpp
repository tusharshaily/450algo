#include <bits/stdc++.h>
using namespace std;
/*
                        1
                    2       3   
                4       5
                
                        1
                    3       2
                        5       4
                        
                        
    1 2 3
    2 4 5
    
    1 3 2
    2 5 4
    
    
    //use adjency list representation 
*/
int main() 
{
	int t;
	
	cin>>t;
	
	int n,e;
	
	while(t--)
	{
	    cin>>n>>e;
	    
	    vector<vector<int>>arr(n+1);
	    vector<vector<int>>brr(n+1);
	    
	    int u,v;
	    
	    for(int i=0;i<e;i++)
	    {
	        cin>>u>>v;
	        arr[u].push_back(v);
	    }
	    
	    for(int i=0;i<e;i++)
	    {
	        cin>>u>>v;
	        brr[u].push_back(v);
	    }
	    
	    for(int i=0;i<=n;i++)
	    {
	        if(arr[i].size()>1)
	        {
	            reverse(arr[i].begin(),arr[i].end());
	        }
	    }
	    
	    bool f = true;
	    
	    for(int i=0;i<=n;i++)
	    {
	        if(!f)
	        break;
	        
	        if(arr[i].size()==brr[i].size())
	        {
	            int k =arr[i].size();
	            
	            for(int j=0;j<k;j++)
	            {
	               if(arr[i][j]!=brr[i][j])
	               {
	                   f=false;
	                   break;
	               }
	            }
	        }
	        else
	        f=false;

	    }
	    
	    if(f)
	    cout<<"1\n";
	    else
	    cout<<"0\n";
	    
	}
	
	
	return 0;
}
