
void left(Node *root,vector<int>& ans)
{
    if(root==NULL) return ;
    
    if(root->left==NULL && root->right==NULL) return ;
    
    ans.push_back(root->data);
    
    if(root->left!=NULL)
        left(root->left,ans);
    
    else if(root->right!=NULL)
    left(root->right,ans);

}

void leaf(Node *root,vector<int>& ans)
{
    if(root==NULL) return ;
    
    if(root->left==NULL && root->right==NULL) { ans.push_back(root->data); return;}
    
    leaf(root->left,ans);
    
    leaf(root->right,ans);
}

void right(Node *root,vector<int>& ans)
{
    if(root==NULL) return ;
    
    if(root->left==NULL && root->right==NULL) return ;
    
    if(root->right!=NULL)
    right(root->right,ans);
    
    else if(root->left!=NULL)
    right(root->left,ans);
    
    ans.push_back(root->data);
}

