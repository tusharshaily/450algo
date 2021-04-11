
// making array like 1 -1 2 3 4 -1 6 7 8 9 

vector<int> leftView(Node *root)
{
   vector<int> t;
   queue<Node*> q;
   
    vector<int>ans;
   
   if(root==NULL)
   return ans;
   
   q.push(root);
   q.push(NULL);
   
   while(q.size())
   {
       if(q.front()==NULL && q.size()==1)
       break;
       
       if(q.front()==NULL)
       {
           t.push_back(-1);
           q.pop();
           q.push(NULL);
           continue;
       }
       
       Node* x= q.front();
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
   
  
   
   ans.push_back(t[0]);
   
   for(int i=1;i<t.size();i++)
   {
       if(t[i]==-1 && i+1<t.size())
       {
           ans.push_back(t[i+1]);
       }
   }
   return ans;
}
