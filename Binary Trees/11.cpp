vector <int> bottomView(Node *root)
{
   vector<int> vi(1000000,-1);
    
    queue<pair<Node*,int>>q;
    
    vector<int> ans;
    
    if(root==NULL)
    return ans;
    
    q.push({root,500000});
    
    pair<Node*,int> x;
    while(q.size())
    {
        x=q.front();
        
        vi[x.second]=x.first->data;
        
        q.pop();
        
        
        if(x.first->left!=NULL)
        {
            q.push({x.first->left,x.second-1});
        }
        
        if(x.first->right!=NULL)
        {
            q.push({x.first->right,x.second+1});
        }
    }
    
    for(int i=0;i<1000000;i++)
    {
        
        if(vi[i]!=-1)
        {
            ans.push_back(vi[i]);
        }
    }
    return ans;// Your Code Here
}
