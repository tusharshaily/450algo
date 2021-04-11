// for the pre-oder traversal

// here we are going to print the node in the stack then move its right child then its left child

vector<int> preorder(Node *root)
{
    vector<int> t;
    stack<Node *> st;

    st.push(root);
    while (st.size())
    {
        Node *p = st.top();
        st.pop();

        if (p != NULL)
        {
            t.push_back(p->data);
            st.push(p->right);
            st.push(p->left);
        }
    }

    return t;
}

// recursion version

void pre(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        pre(root->left);
        pre(root->right);
    }
}