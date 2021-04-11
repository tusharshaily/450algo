#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node*left;
    Node* right;
    
    Node(int x)
    {
        data=x;
        left=NULL;
        right=NULL;
    }
};

void display(Node* root)
{
    if(root==NULL)
    return ;
    
    cout<<root->data<<" ";
    
    display(root->left);
    
    display(root->right);
    
}


Node* rec(string g)
{
    if(g.size()==0)
    return NULL;
    
    int key =-1;
    
    for(int i=0;i<g.size();i++)
    {
        if(g[i]=='(')
        {
            key=i-1;
            break;
        }
    }
    
    if(key==-1)
    {
        int u = stoi(g);
        
        Node* p =new Node(u);
        
        return p;
    }
    
    int val = stoi(g.substr(0,key+1));
    
    Node * x = new Node(val);
    
    key++;
    
    stack<int> st;
    
    st.push(key);
    
    int key2;
    
    for(int i=key+1;i<g.size();i++)
    {
        if(g[i]=='(')
        {
            st.push(i);
        }
        
        if(g[i]==')')
        {
            key2=i;
            st.pop();
        }
        
        if(st.size()==0)
        break;
    }
    
    string left = g.substr(key+1,key2-key-1);
    x->left=rec(left);
    
    key2++;
    
    if(key2<g.size())
    { 
        string right = g.substr(key2+1,g.size()-key2-2);
        x->right=rec(right);
    }
    else
    x->right=NULL;
    
    return x;
}

int main() 
{
	string g;
	cin>>g;
	
	Node* root = rec(g);
	
	display(root);
	
	return 0;
}
