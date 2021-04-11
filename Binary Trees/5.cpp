// ** inorder traversal using recursion and iteration

// using recurion

void inoder(Node *root)
{
    if (root != NULL)
    {
        in(root->left);
        cout << root->val << " ";
        in(root->left);
    }
}

// the main challenge is doing the interation

// we are going to use stack in it .

vector<int> inOrder(Node *root)
{
    // creating a vector to store the ans

    vector<int> t;

    stack<Node *> st;

    // we are moving towards the extreme left first
    while (root)
    {
        st.push(root);
        root = root->left;
    }

    while (!st.empty())
    {
        Node *p = st.top();
        st.pop();

        t.push_back(p->data);

        // whenever we find any new right subtree then we are going to move extreme right just like the
        // parent tree we did
        if (p->right != NULL)
        {
            Node *k = p->right;
            while (k)
            {
                st.push(k);
                k = k->left;
            }
        }
    }
    return t;
}