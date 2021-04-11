string rec(Node *root,unordered_map<string,int>& mp)
{
    if(root==NULL)
     return "$";
     
     string g = to_string(root->data);
     
     if(root->left==NULL && root->right ==NULL)
     {
         return g;
     }
     
     string left = rec(root->left,mp);
     
     string right = rec(root->right,mp);
     
     g += left;
     
     g += right;
     
     mp[g]++;
     
     return g;
}

bool dupSub(Node *root)
{
     unordered_map<string,int>mp;
     
     string g = rec(root,mp);
     
     for(auto x: mp)
     {
         if(x.second>=2)
         return true;
     }
     
     return false;
}
