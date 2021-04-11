#include <bits/stdc++.h>
using namespace std;

struct node 
{
    int data;
    struct node* left=nullptr;
    struct node* right=nullptr;
    struct node* parent=nullptr;
    node(int val)
    {
        data=val;
    }
};

int rec(node* root)
{
    if(root==NULL)
    return -1;
    
    node*p =root->parent;
    
    if(p!=NULL && p->left==root)
    return p->data;
    
    else
    return rec(p);
}

// int inorder(node *root)
// {
//     if(root==nullptr)return -1;
    
//     if(root->right!=NULL)
//     {
//         node* p= root->right;
        
//         while(p->left!=NULL)
//         {
//             p=p->left;
//         }
//         return p->data;
//     }
//     else
//     {
//         return  rec(root);
//     }
// }

node * start= NULL;

node* insert(int i)
{
    node* p = new node(i);
    
    if(start==NULL)
    {
        start=p;
    }
    else
    {
     node* curr=start;
     node* pre=start;
     
     while(curr!=NULL)
     {
         pre=curr;
         
         if(curr->data<i)
         {
             curr=curr->right;
         }
         else
         curr=curr->left;
     }
     
     if(pre->data>i)
     {
         pre->left=p;
         
     }
     else
     {
         pre->right=p;
     }
     p->parent=pre;
     
    }
    return p;
}



int main() {
    int n;
    cin>>n;
    vector<int> v(n);
	for(int i=0;i<n;i++)
	cin>>v[i];
	
	for(auto x: v)
	{
	    cout<<x<<" ";
	}
	cout<<"\n";
	vector<int>ans(n,-1);
	
	for(int i= n-1;i>=0;i--)
	{
	    node* x=insert(v[i]);
	    ans[i]=rec(x);
	}
	for(auto x: ans)
	{
	    cout<<x<<" ";
	}
	return 0;
}
