
// unoptimize solution
int height(Node* root)
{
    if(root==NULL)
    return 0;
    
    int l = height(root->left);
    
    int r = height(root->right);
    
    return 1+max(l,r);
}


bool isBalanced(Node *root)
{
    if(root == NULL)
    return true;
    
    bool f = isBalanced(root->left);
    
    if(f)
    f=f&&isBalanced(root->right);
    else
    return f;
    
    if(f)
    {
        int l = height(root->left);
        
        int r = height(root->right);
        
        int k = l>r?l-r:r-l;
        
        if(k>1)
        return false;
        
        return true;
    }
    
    return f;
}

// salution can be optimize if we save the calculated index in one go 
