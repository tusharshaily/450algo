// here we are using the null approach with the queue to distingwish the layerss 
vector <int> zigZagTraversal(Node* root)
{
	vector<int> ans;
	
	if(root==NULL)
	{
	    return ans;
	}
	
	vector<int> t;
	
	int count=0;
	
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	
	Node* x;
	
	while(q.size())
	{
	    if(q.front()==NULL && q.size()==1)
	    {
	        if(count%2==1)
	        {
	            reverse(t.begin(),t.end());
	            
	            for(auto &x: t)
	            {
	                ans.push_back(x);
	            }
	            
	        }
	        
	        else
	        {
	            
	            for(auto &x: t)
	            {
	                ans.push_back(x);
	            }
	        }
	        break;
	    }
	    
	    if(q.front()==NULL)
	    {
	        q.pop();
	        q.push(NULL);
	        
	        if(count%2==1)
	        {
	            reverse(t.begin(),t.end());
	            
	            for(auto &x: t)
	            {
	                ans.push_back(x);
	            }
	            
	        }
	        
	        else
	        {
	            
	            for(auto &x: t)
	            {
	                ans.push_back(x);
	            }
	        }
	            
	            t.resize(0);
	            count++;
	    }
	    
	    x=q.front();
	    
	    q.pop();
	    
	    t.push_back(x->data);
	    
	    if(x->left!=NULL)
	    {
	        q.push(x->left);
	    }
	    
	    if(x->right!=NULL)
	    {
	        q.push(x->right);
	    }
	    
	}
	
return ans;
	
	
}
