// here we are going to compute height from every node using height default function
//and in addition to that we will check the variable 1+left+right
int height(Node *root, int *p)
{
    if (root == NULL)
        return 0;

    int left = height(root->left, p);
    int right = height(root->right, p);

    int d = left + right + 1;
    *p = max(*p, d);

    return 1 + max(left, right);
}
int diameter(Node *root)
{
    int maxi = 0;
    int *p;
    p = &maxi;
    int t = height(root, p);
    return maxi;
    // Your code here
}