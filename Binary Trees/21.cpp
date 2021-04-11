class Solution
{
    public:
    
    bool rec(Node* root,int* p)
    {
        if(root==NULL)
        return true;
        
        if(root->left==NULL && root->right==NULL)
        {
            *p+=root->data;
            return true;
        }
        
        int left=0;
        int right=0;
        
        bool l =rec(root->left,&left);
        
        bool r =rec(root->right,&right);
        
        if(l&&r)
        {
            if(root->data == left+right)
            {
                *p+=left+right+root->data;
                return true;
            }
            
            return false;
        }
        return false;
    }
    
    bool isSumTree(Node* root)
    {
         int m =0;
         return rec(root,&m);
    }
};
