int rec(Node* node)
{
    if(node==NULL)
        return 0;
    
    if(node->left==NULL && node->right==NULL)
    {
        int k = node->data;
        node->data=0;
        
        return k;
    }
    
    int left=0;
    
    int right=0;
    
    left = rec(node->left);
    
    right = rec(node->right);
    
    int q = node->data;
    
    node->data = left+right;
    
    return node->data+q;
}
void toSumTree(Node *node)
{
    // Your code here
    int t = rec(node);
    
}
