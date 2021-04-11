bool rec(Node* root,int *p,int n)
{
    if(root->left==NULL && root->right==NULL)
    {
        if(*p==-1)
        {
            *p=n;
            return true;
        }
        else
        {
            if(*p==n)
            return true;
            return false;
        }
    }
    
    bool l = true;
    
    bool r =true;
    
    if(root->left!=NULL)
    {
        l=rec(root->left,p,n+1);
    }
    
    if(root->right!=NULL)
    {
        l=rec(root->right,p,n+1);
    }
    
    return l&&r;
    
}
bool check(Node *root)
{
    if(root==NULL)
    return true;
    
    int vi=-1;
    return rec(root,&vi,0);
}
