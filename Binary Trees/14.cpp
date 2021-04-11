void dfs(Node *root, int k, vector<vector<int>> &arr)
{
    arr[k].push_back(root->data);

    if (root->left != NULL)
        dfs(root->left, k + 1, arr);

    if (root->right != NULL)
        dfs(root->right, k, arr);
}

vector<int> diagonal(Node *root)
{
    vector<vector<int>> arr(100005);
    vector<int> ans;
    if (root == NULL)
        return ans;

    // here we use the dfs so as that the require element gets print
    dfs(root, 0, arr);
    for (int i = 0; i < 1000005; i++)
    {
        if (arr[i].size() == 0)
            break;

        for (auto &x : arr[i])
            ans.push_back(x);
    }

    return ans;
}
