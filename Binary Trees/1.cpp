vector<int> reverseLevelOrder(Node *root)
{
    queue<Node *> q;
    vector<int> t;
    if (root == NULL)
        return t;

    q.push(root);

    while (!q.empty())
    {
        Node *p = q.front();

        t.push_back(p->data);

        if (p->right != NULL)
            q.push(p->right);

        if (p->left != NULL)
            q.push(p->left);

        q.pop();
    }
    reverse(t.begin(), t.end());
    return t;
}